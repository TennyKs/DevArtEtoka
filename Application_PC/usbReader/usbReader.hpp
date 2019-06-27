#include <iostream>
#include <string>
#include <vector>
#include <map>

class UsbReader {
    private:
        std::map<std::string,int> mapCount;
        std::string path;
        std::vector<std::string> extensions  = {
            "txt",
            "png",
            "mp3"
        };


    public:
        UsbReader(std::string);
        ~UsbReader();

        void display();
        bool completeMap();

};