#include "Directory.h"
#include "Contact.h"
#include <cassert>
#include <iostream>
using namespace std;

int main() {
  Directory dir;

  // Test data
  Contact sam = {"Sam Smith", "2061239876", "123 Baker St"};
  Contact maria = {"Maria M", "4255551245", ""};
  Contact benny = {"Benny Jets", "", "567 Disney Lane"};
  Contact johnny = {"Johnny Appleseed", "5423412", "67 Walnut Ave"};
  Contact john = {"John Wayne", "(949) 252-5200", "18601 Airport Way"};
  Contact emptyContact = {"", "", ""};



  cout << "Demo 1: Add contacts and find Sam Smith" << endl;
  bool addResult = dir.AddContact(maria.name, maria.phoneNumber, maria.address);
  assert(addResult);
  addResult = dir.AddContact(sam.name, sam.phoneNumber, sam.address);
  assert(addResult);
  addResult = dir.AddContact(benny.name, benny.phoneNumber, benny.address);
  assert(addResult);
  Contact findRes = dir.FindContact("Sam Smith");
  assert(findRes == sam);
  findRes.Print();
  cout << endl;

  cout << "Demo 2: Search for a non-existent contact, Big Bird" << endl;
  findRes = dir.FindContact("Big Bird");
  assert(findRes == emptyContact);
  findRes.Print();
  cout << endl;

  cout << "Demo 3: Try to add a duplicate entry, Benny Jets" << endl;
  addResult = dir.AddContact("Benny Jets", "12340923", "57 Yellow Brick Road");
  findRes = dir.FindContact("Benny Jets");
  findRes.Print();
  assert(findRes == benny);
  cout << endl;

  cout << "Demo 4: Try to add a contact without a name" << endl;
  addResult = dir.AddContact("", "123", "asdf");
  findRes = dir.FindContact("");
  assert(findRes == emptyContact);
  assert(!addResult);
  findRes.Print();
  cout << endl;

  cout << "Demo 5: Export contacts to contacts1.csv" << endl;
  bool exportRes = dir.ExportContacts("contacts1.csv");
  assert(exportRes);
  cout << endl;

  cout << "Demo 6: Remove Maria M from directory" << endl;
  bool removeRes = dir.RemoveContact("Maria M");
  assert(removeRes);
  findRes = dir.FindContact("Maria M");
  assert(findRes == emptyContact);
  findRes.Print();
  cout << endl;

  cout << "Demo 7: Confirm other contacts have not been removed" << endl;
  findRes = dir.FindContact("Sam Smith");
  assert(findRes == sam);
  findRes.Print();
  cout << endl;

  cout << "Demo 8: Add after a remove, John and Johnny" << endl;
  addResult = dir.AddContact(johnny.name, johnny.phoneNumber, johnny.address);
  assert(addResult);
  addResult = dir.AddContact(john.name, john.phoneNumber, john.address);
  assert(addResult);
  findRes = dir.FindContact("Johnny Appleseed");
  assert(findRes == johnny);
  findRes.Print();
  cout << endl;

  cout << "Demo 9: Remove a contact that does not exist, Mariah Carey" << endl;
  removeRes = dir.RemoveContact("Mariah Carey");
  assert(!removeRes);
  cout << endl;

  cout << "Demo 10: Export contacts to contacts2.csv" << endl;
  exportRes = dir.ExportContacts("contacts2.csv");
  assert(exportRes);
  cout << endl;

  cout << "Demo 11: Export to invalid file path" << endl;
  exportRes = dir.ExportContacts("nonFolder/contacts3.csv");
  assert(!exportRes);
  cout << endl;

  cout << "Demo 12: Find a single result, Sam" << endl;
  vector<Contact> partialFinds = dir.FindAllContacts("Sam Smith");
  assert(partialFinds.size() == 1);
  assert(partialFinds.at(0) == sam);
  partialFinds = dir.FindAllContacts("Sam");
  assert(partialFinds.size() == 1);
  assert(partialFinds.at(0) == sam);
  partialFinds = dir.FindAllContacts("S");
  assert(partialFinds.size() == 1);
  assert(partialFinds.at(0) == sam);
  partialFinds.at(0).Print();
  cout << endl;

  cout << "Demo 13: Search for a name not in the directory, Mr. Bean" << endl;
  partialFinds = dir.FindAllContacts("Mr. Bean");
  assert(partialFinds.size() == 0);
  cout << endl;

  cout << "Demo 14: Find multiple results, searching for John" << endl;
  partialFinds = dir.FindAllContacts("John");
  assert(partialFinds.size() == 2);
  bool foundJohnny = false, foundJohn = false;
  for(int i = 0; i < partialFinds.size(); i++){
    if (partialFinds.at(i) == john){
      foundJohn = true;
    }
    if (partialFinds.at(i) == johnny){
      foundJohnny = true;
    }
  }
  assert(foundJohn && foundJohnny);
  partialFinds.at(0).Print();
  partialFinds.at(1).Print();
 
}