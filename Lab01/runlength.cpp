#include <iostream>
using namespace std;

int main(){

    char c;
    int n;

    while(true){

        cin >> c;
        cin >> n;

        if(n == -2)
            break;
        else if(n == -1)
            cout << "\n";
        else{
            for(int i = 0; i < n; i++){
                cout << c;
            }

        }

    }

    return 0;

}
