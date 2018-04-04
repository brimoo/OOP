#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <iostream>
#include <string>
#include "Sortable.h"
using namespace std;

class Participant : public Sortable{
    
    public:

        typedef bool(*funcptr)(const Participant * p1, const Participant * p2);

        static funcptr comp_cb;

        string name;
        int age;
        double score;
    
        Participant(string n, int a, double s): name(n), age(a), score(s){}

        void print(){cout << name << "\t" << age << "\t" << score << endl;}

        bool compare(const Sortable * s){
            const Participant * other = dynamic_cast<const Participant *>(s);
            return !comp_cb(this, other);
        }

};




#endif
