//
// Created by Nino on 15/06/2020.
//

#ifndef LAB2_BASE_H
#define LAB2_BASE_H

#include <string>
#include <iostream>
class Base {

public:
    Base(){
        std::cout << "costruttore" << std::endl;
    }
    ~Base(){
        std::cout << "distruttore" << std::endl;
    }
    virtual void ls(int indent) const = 0;
    std::string getName() const;
    virtual int mType() const = 0;

protected:
    std::string name;


};


#endif //LAB2_BASE_H
