#include <iostream>

using namespace std;
const int N =(2*1e5 + 1);
int n,q,arr[N],i,x;

int main() {
   cin>>n>>q;
   for(int j = 1; j<=n; ++j)cin>>arr[j];
   while(q){
       cin>>i>>x;
       arr[i] *=x;

   }
}
