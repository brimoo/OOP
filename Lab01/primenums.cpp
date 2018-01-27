#include <iostream>
using namespace std;

bool isPrime(int n){

    if(n < 2)
        return false;
    if(n == 2)
        return true;
    
    for(int i = 2; i < n; i++){
        if(n % i == 0)
            return false;
    }

    return true;
}

int main(){

    int input;
    cin >> input;

    for(int i = 2; i < input; i++){
        if(isPrime(i))
            cout << i << endl;
    }

    return 0;
}
