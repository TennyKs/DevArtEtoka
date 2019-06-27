#include "usbReader.hpp"

int main(int argc, char** argv) {

    if (argc > 1) {
        std::string path = argv[1];

        std::cout<<"Main : "<< path <<std::endl;

        UsbReader usbReader(path);
        usbReader.completeMap();
        usbReader.display();

    }
}