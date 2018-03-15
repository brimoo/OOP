#include <iostream>
#include <vector>
#include "Animal.h"
#include "display.h"
#include "Dog.h"

using namespace std;

int main(){

    vector<Animal *> animals;
    int size;

    cin >> size;

    string name;
    int age;
    char type;

    for(int i = 0; i < size; i++){
    
        cin >> type >> name >> age;

        if(type == 'A'){
            Animal * newAnimal = new Animal();
            newAnimal->setName(name);
            newAnimal->setAge(age);
            animals.push_back(newAnimal);
        }else if(type == 'D'){
            Dog * newDog = new Dog(name, age);
            animals.push_back(newDog);
        }

    }

    display(animals);

    return 0;

}
