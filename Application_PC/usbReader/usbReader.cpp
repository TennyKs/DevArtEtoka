#include <experimental/filesystem>
#include <iterator>
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
        path_file=p.path().filename().string();

        size_t pos = 0;
        while ((pos = path_file.find(delimiter)) != std::string::npos)
            path_file.erase(0, pos + delimiter.length());
        

        if(mapCount.find(path_file) != mapCount.end())
            mapCount.at(path_file)=mapCount.find(path_file)->second + 1;
        else
            mapCount.insert({path_file,1});
        
    }

    return complete;
}

void UsbReader::display(){
    for(auto it = mapCount.begin(); it != mapCount.end(); ++it)
        std::cout << it->first << " " << it->first << " " << it->second << "\n";
}