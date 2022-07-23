#include <iostream>
#include <algorithm>  
using namespace std;

int n;
const int N = 2e5+10;
int arr[N];

int main(){
    cin >> n;
    int cnt = 1;
    for(int i=0;i<n;++i) cin >> arr[i];
    sort(arr,arr+n);
    for(int i=1;i<n;++i){
        if(arr[i] != arr[i-1]){
            cnt++;
        }
    }
    cout << cnt << "\n";
}