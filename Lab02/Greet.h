#ifndef Greet_h
#define Greet_h
// We should include <string> here
#include <string>

void greet(std::string name, void func(std::string)){
    func(name);
}

#endif /* Greet_h */
