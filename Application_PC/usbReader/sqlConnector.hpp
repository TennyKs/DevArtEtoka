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
            hostname = "remotemysql.com",
            username = "pJtsHBduHR",
            password = "BTKyT1EvRA",
            dataBaseName = "pJtsHBduHR";

    public: 
        SqlConnector();
        ~SqlConnector();

        bool execute(std::map<std::string,int> mapCount);

};