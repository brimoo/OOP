#include <iostream>
#include <string>
using namespace std;

class Entry{

    string lastName;
    string firstName;
    string myEmail;

    public:

        void setName(string name){firstName = name;}
        void setLastname(string name){lastName = name;}
        void setEmail(string email){myEmail = email;}
        string getName(){return firstName;}
        string getLastName(){return lastName;}
        string getEmail(){return myEmail;}

        void print(){
            cout << "First Name: " << firstName << endl;
            cout << "Last Name: " << lastName << endl;
            cout << "Email: " << myEmail << endl;
        }

};
