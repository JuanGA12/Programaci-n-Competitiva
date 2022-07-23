#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int main() {
    long int input;
    cin >> input;
    vector<long int> result;
    result.push_back(input);
    if (input >= 1 and input <= pow(10,6)){
        while (input != 1){
            if(input % 2 == 0){
                input = input/2;
                result.push_back(input);
            }else{
                input = input*3 + 1;
                result.push_back(input);
            }
        }
        for (auto &i : result){
            cout << i << " ";
        }
    }
    else{
        return 0;
    }
}
