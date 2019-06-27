
#include <iostream>
#include <QDebug>


#include "sqlConnector.hpp"

using namespace std;


SqlConnector::SqlConnector() {
    driver = get_driver_instance();
    con = driver->connect(hostname, username, password);
    con->setSchema(dataBaseName);
    stmt = con->createStatement();
}


SqlConnector::~SqlConnector() {
    // delete res;
    // delete stmt;
    // delete con;
}

std::string mapToJson(std::map<std::string,int> mapCount) {


    std::string json = "";
    json += "{\"data\":[";

    for(auto it = mapCount.begin(); it != mapCount.end(); ++it) {
        json += "{\"type\":\"" + it->first + "\",";
        json += "\"count\":\"" + std::to_string(it->second) + "\"},";
    }

    json = json.erase(json.length()-1);
    json += "]}";
    qDebug() << QString::fromStdString(json) ;
    return json;
}

bool SqlConnector::execute(std::map<std::string,int> mapCount){


    try {
        string query = "INSERT INTO `datis` (`id`,`usb_data`) VALUES (NULL, \'"+ mapToJson(mapCount) +"\')";
        cout << query << endl;
        cout << "SqlConnector::execute" << endl;

        res = stmt->executeQuery(query);
    }catch (std::exception e) {
        
    }

    return true;
}
