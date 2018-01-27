#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
using namespace std;

int main(){
    
    string input;
    cin >> input;

    ifstream in("words.txt");
    string word;

    int count = 0;

    while(in >> word){

        for(int i = 0; i < word.length(); i++){
            word[i] = tolower(word[i]);
            if(word[i] < 'a' || word[i] > 'z')
                word = word.substr(0, i);
        }

        if(word == input)
            count++;
    }

    cout << count << endl;

    return 0;
}
