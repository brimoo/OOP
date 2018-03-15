#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "Animal.h"
using namespace std;

class Dog : public Animal{
   
    string name;
    int age;

    public:

        Dog(){
            cout << "Creating Dog" << endl;
            name = "Dog";
            age = 0;
        }

        Dog(string name, int age){
            cout << "Creating Dog" << endl;
            setName(name);
            setAge(age);
        }

        ~Dog(){cout << "Deleting Dog" << endl;}

        void feed(){cout << "A bone, please!" << endl;}

};


#endif
