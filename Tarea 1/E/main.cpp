#include <iostream>
#include <map>
#include <cmath>
using namespace std;
typedef long long int lli;
lli m;
const int MOD = 1e9+7;
map<lli,lli> cantidad;
lli n = lli(1);

lli recursive(lli a){
    if(a == 1){
        return n;
    }else{
        lli aux;
        if(a%2==0){
            aux = recursive(a/2);
            lli b = (aux*aux) %MOD;
            return b;
        }else{
            aux = recursive((a-1)/2);
            lli b = (n*aux*aux) %MOD;
            return (b);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m;
    lli p;
    for(lli i = lli(0); i < m; i++){
        cin>>p;
        n*=p;
        cantidad[p]++;
    }
    /*
    lli r = 1;
    for(lli i= 2; i<=n/2 ;i++){
        if(n%i == 0){
            r*=i;
            //r%=MOD;
        }
    }
    r*=n;
    //r%=MOD;

     */
    lli acc = lli(1);//overflow con int
    for(auto &i : cantidad) {
       acc*=(i.second+lli(1));
    }

    long double b = (1.0*acc/2.0);

    lli trun = lli(b);
    lli a;
    if(trun == b){//VERIFICAR SI ACC/2 ES FLOAT O INT
        a = recursive(b);
    }else{
        a = lli(powl(n,b))%MOD;//FLOAT
    }
    //cout<<b;
    cout<<a;
    //cout<<recursive(acc/2)%MOD;


    //lli rpta = 1;
    //for(lli j = 0; j <acc/2; j++){
    //    rpta = rpta*n;
    //}
    //cout<<rpta<<endl;
    //rpta = rpta%MOD;
    //rpta %= MOD;
    //int rpta = int(pow(n,acc/int(2)));
    //rpta = rpta%int(MOD);
    //cout<<r;
    //898961331
    //766762396
}
