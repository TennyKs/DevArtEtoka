#include <iostream>
#include <string>
#include <vector>
#include <map>

class UsbReader {
    private:
        std::map<std::string,int> mapCount;
        std::string path;
//        std::vector<std::string> extensions  = {
//            "txt",
//            "png",
//            "mp3"
//        };

        std::map<int, char> m = {{1, 'a'}, {3, 'b'}, {5, 'c'}, {7, 'd'}};

        std::map<std::string, std::vector<std::string>> extensions = {
            {
                "Video",
                {"avi","mpeg","mp4","mkv"}
            },
            {
                "Audio",
                {"mp3","flac","wav","ogg","oov"}
            },
            {
                "Document",
                {"doc","txt","odp","ods","docx","pdf"}
            },
            {
                "Picture",
                {"gif","png","jpg","jpeg","raw"}
            },
            {
                "Archive",
                {"7z","zip","gz","xz","rar"}
            },
            {
                "Programming",
                {"cpp","hpp","c","h","dart","php","js","c#","html","css"}
            },
        };


    public:
        UsbReader(std::string);
        ~UsbReader();

        void display();
        bool completeMap();

        inline std::map<std::string,int> getMap(){return mapCount;}

};
