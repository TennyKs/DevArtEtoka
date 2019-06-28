#include <experimental/filesystem>
#include <iterator>
#include <QDebug>
#include "usbReader.hpp"


namespace fs=std::experimental::filesystem;

UsbReader::UsbReader(std::string _path)
:path(_path)
{}

UsbReader::~UsbReader()
{}




bool UsbReader::completeMap(){
    bool complete = true;
    std::string delimiter = ".";

  	fs::path dir=fs::path(path);
    std::string path_file;

    for(auto& p: fs::recursive_directory_iterator(dir))
    {
        std::string type = "Other";
        path_file=p.path().filename().string();

        size_t pos = 0;
        while ((pos = path_file.find(delimiter)) != std::string::npos)
            path_file.erase(0, pos + delimiter.length());
        

        for (auto it = extensions.begin();it != extensions.end(); ++it) {
            for (unsigned int i = 0;i<it->second.size();++i) {
                if (it->second.at(i) == path_file) {
                    type = it->first;
                }
            }
        }

        if(mapCount.find(type) != mapCount.end())
            mapCount.at(type)=mapCount.find(type)->second + 1;
        else
            mapCount.insert({type,1});


        
    }

    return complete;
}

void UsbReader::display(){

    qDebug() << "display -> " << mapCount.size();
    for(auto it = mapCount.begin(); it != mapCount.end(); ++it)
        std::cout << it->first << " " << it->first << " " << it->second << "\n";
}
