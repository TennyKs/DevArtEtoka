#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>


class SqlConnector{

    private:
        sql::Driver* driver;
        sql::Connection* con;
        sql::Statement* stmt;
        sql::ResultSet* res;

        std::string 
            hostname = "sql309.byethost7.com",
            username = "b7_24105734",
            password = "mtsdevart",
            dataBaseName = "b7_24105734_datisroom";

    public: 
        SqlConnector();
        ~SqlConnector();

        bool execute(std::map<std::string,int> mapCount);

};
