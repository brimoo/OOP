#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){

    ifstream in("words.txt");
    string word;
    int words = 0;

    while(in >> word){
        words++;
    }

    cout << words << endl;

    return 0;

}
