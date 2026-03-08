/*
This file contains the implementation of the Directory class, which manages
a collection of contacts for a simple contacts application. The Directory
class is responsible for adding, removing, searching for, and exporting
contacts, as well as performing partial name searches. This file works with 
the Directory.h file to give functionality for storing and managing 
contact information.

Author: Deena Qannan
*/
#include "Directory.h"
#include <fstream>
using namespace std;


// Adds a new contact to the directory if the name is valid and not a duplicate
bool Directory::AddContact(string name,string phone,string address){
    if (name == "") {
        return false;
    }
      
    // Checking for duplicates
    if (contacts.find(name) != contacts.end()) {
        return false;
    }
    
    Contact c;
    c.name = name;
    c.phoneNumber = phone;
    c.address = address;
    
    contacts[name] = c;
    return true;
    
}

// Removes the contact with the given name from the directory if it exists
bool Directory::RemoveContact(string name) {
    auto it = contacts.find(name);

    if (it == contacts.end()) {
        return false;
    }

    contacts.erase(it);
    return true;
}

// Finds and returns the contact with the given name, or an empty Contact if
//not found
Contact Directory::FindContact(string searchName) {
    auto it = contacts.find(searchName);

    if (it == contacts.end()) {
        return Contact{"", "", ""};
    }

    return it->second;
}

// Exports all contacts to a .csv file in alphabetical order by contact name
bool Directory::ExportContacts(string filename) {
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        return false;
    }

    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        outFile << it->second.name << ","
                << it->second.phoneNumber << ","
                << it->second.address << endl;
    }

    outFile.close();
    return true;
}

// Returns all contacts whose names begin with the given search string
vector<Contact> Directory::FindAllContacts(string searchStr) {
    vector<Contact> results;

    if (searchStr == "") {
        return results;
    }

    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        const string& name = it->second.name;

        if (name.find(searchStr) == 0) { // starts with
            results.push_back(it->second);
        }
    }

    return results;
}

