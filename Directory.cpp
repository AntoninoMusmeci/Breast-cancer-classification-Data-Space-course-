//
// Created by Nino on 15/06/2020.
//

#include "Directory.h"
#include <utility>
#include <iostream>

std::shared_ptr<Directory> Directory::root = nullptr;
std::shared_ptr<Directory>  Directory::makeDirectory( std::string name, std::weak_ptr<Directory> parent){
    std::shared_ptr<Directory> ptr (new Directory(name));
    ptr->self = ptr;
    ptr->parent = parent;
    return ptr;
}

void Directory::ls(int indent) const {
    std::cout << std::string(indent, ' ' ) <<"[+]" << name << std::endl;
    for(const auto& c : children)
        c.second->ls(indent + 4 );
}

std::shared_ptr<Directory> Directory::addDirectory(std::string nome) {
    std::shared_ptr<Directory> dir = makeDirectory(nome, self);
    children.insert(std::pair<std::string,std::shared_ptr<Directory>>(nome,dir));
    return dir;
}

Directory::Directory(std::string name){
    this->name = name;
}


std::shared_ptr<Directory> Directory::getRoot() {
    if(root == nullptr)
        root = makeDirectory("/", root);
    return root;
}

std::shared_ptr<Base> Directory::get(std::string name){
    if(name == "..") return this->parent.lock();
    if(children.count(name)) return children[name];
    return nullptr;
}

std::shared_ptr<Directory> Directory::getDir(std::string name){
    if(name == "..") return this->parent.lock();
    if(children.count(name)) return std::dynamic_pointer_cast<Directory>(children[name]);
    return nullptr;
}

std::shared_ptr<Base> Directory::getFile(std::string name){
    if(children.count(name)) return std::dynamic_pointer_cast<File>(children[name]);
    return nullptr;
}

int Directory::mType() const{
    return 0;
}

std::shared_ptr<File> Directory::addFile(const std::string &nome, uintmax_t size) {
    if(children.count(nome)) return nullptr; // key exist
    auto file =  std::make_shared<File>(nome,size);
    children.insert(std::pair<std::string,std::shared_ptr<Base>>(nome,file));
    return file;

}

bool Directory::remove(const std::string &nome) {
    if(children.count(nome) > 0){
        children.erase(nome);
        return true;
    }
    return false;
}
