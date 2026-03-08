#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "Contact.h"
#include <string>
#include <vector>
#include <map> 

class Directory {
public:

  bool AddContact(std::string name, std::string phone, std::string address);
  bool RemoveContact(std::string name);
  Contact FindContact(std::string searchName);
  bool ExportContacts(std::string filename);
  std::vector<Contact> FindAllContacts(std::string searchStr);

private:
  std::map<std::string, Contact> contacts;
};

#endif