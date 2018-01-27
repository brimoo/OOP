#include <iostream>
#include <string>
using namespace std;

int main(){

    string str_repeat;
    int n;

    getline(cin, str_repeat);
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << str_repeat << endl;
    }

    return 0;

}
