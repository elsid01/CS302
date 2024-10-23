#include <unordered_map>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
  //a hashMap that maps a string
  // to an integer
  unordered_map<string, int> people;
  string name;

  //insert into an unordered_map
  people["Dane"] = 13;
  people["Drew"] = 11;
  people["Joe"] = 16;

  cout<< "Enter a name: ";
  cin>>name;

  // If people.find(name) returns an end() iterator, then name was not found 
  // otherwise, the name was found

  cout << people["sue"] << endl;

  if(people.find(name) != people.end())
  //if (people[name] != 0;)
  {
    auto it = people.find(name);

    cout<<"Here is the element in the map"<<endl;

    cout<< it->first << "=>";
    cout << it->second << endl;

  }
  else{
    cout << name << " was not found"<< endl;
  }

  // These two loops can be used to iterate through the unordered_map

  for(auto i = people.begin(); i != people.end(); i++)
  {
    // first is the element's key field
    cout << i->first << " => " << i->second << endl;
  }
  return 0;
}