
// Test connecteur C++ MySQL
// O. Dartois, Juin 2017

//#include <stdlib.h>
#include <iostream>

// Les includes strictement nécessaire pour cet exemple

#include "sqlConnector.hpp"

using namespace std;


SqlConnector::SqlConnector() {
    driver = get_driver_instance();
    con = driver->connect(hostname, username, password);
    con->setSchema(dataBaseName);
    stmt = con->createStatement();
}


SqlConnector::~SqlConnector() {
    delete res;
    delete stmt;
    delete con;
}

bool SqlConnector::execute(std::map<std::string,int> mapCount){
    string query = "SELECT * FROM data";
    cout << "SqlConnector::execute" << endl;

    res = stmt->executeQuery(query);
    
    // Etape 5 : exploitation du résultat de la requête
    while (res->next()) {
        // cout << "\t... MySQL a repondu: ";
        // Acces par non du champ de la table : ici le champ 'id' que l'on recupère au format string
        cout << "\tres: " << res->getString("type") << endl;
        cout << "\tres: " << res->getString("count") << endl;
        // Acces à la donnée par son numéro de colonne, 1 étant le premier (ici 'id'), 5 le nom de l'animal
        // cout << res->getString(5) << endl;
    }

}