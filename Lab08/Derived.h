#ifndef DERIVED_H
#define DERIVED_H

#include <iostream>
#include "ADT.h"
using namespace std;

class Derived : public ADT{

    public:

        void doSomething(){cout << "I did something" << endl;}
        void doSomethingElse(){cout << "I did something else" << endl;}
        void dontDoThis(){return;}

};

#endif
