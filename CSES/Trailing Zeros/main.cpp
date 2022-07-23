#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main (){
    lli n,ans;
    cin >> n;
    for (int i = 5; i <= n; i*=5){
        ans += n/i;
    }
    cout<<ans<<"\n";
    return 0;
}