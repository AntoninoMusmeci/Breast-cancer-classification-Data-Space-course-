//
// Created by Nino on 15/06/2020.
//

#ifndef LAB2_FILE_H
#define LAB2_FILE_H


#include "Base.h"

class File : public Base{
    int size = 0;
    uintmax_t getSize() const;
    void ls(int indent) const override;

public:
    File(std::string name, int size);
    virtual int File::mType() const;
};




#endif //LAB2_FILE_H
