#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    long long input = 0;
    cin>>input;
    long long total = input * (input + 1) / 2;
    for(long long i = 0 ; i < input - 1; i++ ){
        long long number;
        cin>>number;
        total -= number;
    }
    cout<<total;    
    return 0;
}
