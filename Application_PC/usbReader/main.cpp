#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "usbReader.hpp"
#include "sqlConnector.hpp"

int main(int argc, char** argv) {

    if (argc > 1) {
        std::string path = argv[1];

        std::cout<<"Main : "<< path <<std::endl;

        UsbReader usbReader(path);
        usbReader.completeMap();
        usbReader.display();

        SqlConnector sqlConnector;
        sqlConnector.execute(usbReader.getMap());

    }
}