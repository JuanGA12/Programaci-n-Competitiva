#include <iostream>
using namespace std;
const int N = 1e8+7;
int n,m,cls[N],arr[N],cnt;
int main() {
    cin>>n>>m;
    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        for(int j = 0; j<=35; j++){
            if(a&(1<<j)){
                cls[(1<<j)]+=1;
            }
        }
    }
    for(int i = 0; i < m; ++i) {
        cin >> arr[i];
    }
    for(int i = 0; i <=35; ++i) {
        cout << cls[i]<<" ";
    }
    sort(arr,arr+m);
    for(int i = 0; i < m; ++i){
        if(cls[i]>0) {

            //int value = cls[i];
            arr[i] = -1;
            cnt++;

        }
    }
    cout<<cnt++;

}
