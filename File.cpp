//
// Created by Nino on 15/06/2020.
//

#include "File.h"
#include <iostream>

uintmax_t File::getSize() const {
    return 0;
}
void File::ls(int indent) const {
    std::cout << std::string(indent, ' ' ) << name << " " << size << std::endl;
}

File::File(std::string name, int size) :  size(size){
    this-> name = name;

}
int File::mType() const{
    return 1;
}