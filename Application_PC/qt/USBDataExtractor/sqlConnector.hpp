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
            hostname = "sql7.freesqldatabase.com",
            username = "sql7296869",
            password = "fBMfGqYL7I",
            dataBaseName = "sql7296869";

    public: 
        SqlConnector();
        ~SqlConnector();

        bool execute(std::map<std::string,int> mapCount);

};
