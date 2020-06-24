#include <iostream>
#include "Directory.h"
#include <filesystem>

void createFileSistem(const std::filesystem::path path, std::shared_ptr<Directory> root){
    std::filesystem::directory_iterator s(path);
    for( auto a : s) {
        if(!a.is_regular_file())
            createFileSistem(a.path(), root->addDirectory(a.path().filename().string()));
        else
            root->addFile(a.path().filename().string(),a.file_size());

    }
}


int main() {
    std::shared_ptr<Directory> root = Directory::getRoot();
    createFileSistem(R"(C:\Users\Nino\desktop\PDS)",root);
    root->ls(5);
    return 0;
}
