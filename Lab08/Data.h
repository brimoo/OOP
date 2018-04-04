#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Sortable.h"
using namespace std;

class Data{

    vector<Sortable *> data;

    public:

        void add(Sortable * obj){data.push_back(obj);}

        static bool comparison(Sortable * left, Sortable * right){
            left->compare(right);
        }

        void print(){
            for(int i = 0; i < data.size(); i++){
                data[i]->print();
            }
            cout << endl;
        }

        void sort(){
            std::sort(data.begin(), data.end(), comparison);
        }

};


#endif
