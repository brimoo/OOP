#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

    vector<string> words;

    string input;

    while (true){
    
        cin >> input;

        if(input.length() != 1){
            if(input == "quit")
                break;
            else
                words.push_back(input);
        }else{
            for(int i = 0; i < words.size(); i++){
                if(input[0] == words[i][0])
                    cout << words[i] << endl;
            }

        }

    }

    return 0;

}
