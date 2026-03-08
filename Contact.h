#ifndef CONTACT_H
#define CONTACT_H
#include <string>

struct Contact {
    std::string name;
    std::string address;
    std::string phoneNumber;
    
    void Print();
    bool operator==(const Contact& rhs);
    bool operator!=(const Contact& rhs);
};
#endif