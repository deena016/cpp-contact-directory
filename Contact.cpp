#include "Contact.h"
#include <iostream>
using namespace std;

void Contact::Print() {
  if (this->name == "") {
    cout << "Unknown contact" << endl;
  } else {
    cout << "Contact: " << this->name << endl;
    cout << "Phone: "
         << (this->phoneNumber == "" ? "unknown" : this->phoneNumber) << endl;
    cout << "Address: " << (this->address == "" ? "unknown" : this->address);
    cout << endl;
  }
}

bool Contact::operator==(const Contact& rhs){
  bool nameEq = this->name == rhs.name;
  bool phoneEq = this->phoneNumber == rhs.phoneNumber;
  bool addrEq = this->address == rhs.address;
  return  nameEq &&  phoneEq && addrEq;
}

bool Contact::operator!=(const Contact& rhs){
    return !(*this == rhs);
}