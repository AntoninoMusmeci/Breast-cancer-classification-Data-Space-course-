//
// Created by Nino on 15/06/2020.
//

#ifndef LAB2_DIRECTORY_H
#define LAB2_DIRECTORY_H
#include <string>
#include <memory>
#include <map>
#include "Base.h"
#include "File.h"

class Directory : public Base{

    Directory(std::string name);
    std::map<std::string,std::shared_ptr<Base>> children;
    std::weak_ptr<Directory> self;
    std::weak_ptr<Directory> parent;
    static std::shared_ptr<Directory> root;

public:
    static std::shared_ptr<Directory> getRoot();

    std::shared_ptr<Directory> addDirectory(std::string nome);

    static std::shared_ptr<Directory> makeDirectory(std::string name, std::weak_ptr<Directory> parent);

    std::shared_ptr<Base> get(std::string name);

    virtual void ls(int indent) const;

    virtual int mType() const;

    std::shared_ptr<File> addFile(const std::string& nome, uintmax_t size);

    std::shared_ptr<Base> getFile(std::string name);

    std::shared_ptr<Directory> getDir(std::string name);

    bool remove(const std::string& nome);
};


#endif //LAB2_DIRECTORY_H
