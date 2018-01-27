#include <iostream>
using namespace std;

int main(){
    
    int input;

    while(true){

        cin >> input;

        if(input == -1)
            break;

        if(input % 2 == 0)
            cout << "EVEN" << endl;
        else
            cout << "ODD" << endl;
    }

    return 0;

}
