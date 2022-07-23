
/*
 * Complejidad Espacial: O( sizeof(int)*N )
 * Complejidad Temporal: O( nlogz )
 * Idea: Hacemos una busqueda binaria iterativa desde 0 hasta totalumnos/k,
 *       hacemos totalumnos/k ya que (x+b) % k tiene que ser 0 para que sea
 *       la misma cantidad de alumnos por fila.
 *       Tendremos TRUE TRUE TRUE TRUE TRUE TRUE FALSE FALSE FALSE.
 *       La intecion del problema es retornar el ultimo TRUE (maximiza la cantidad de alumnos).
 *       En valid comprobamos que para cada fila entren x alumnos y que cumpla
 *       que la diferencia de alturas no sean mayor a 1. Si valid es True, actualizamos x
 *       a x+=b para ir a la derecha.
 *       La busqueda binaria iterativa se realiza en logz y valid en n.
 *
 * */

#include <iostream>
typedef long long ll;
const ll N = 1e5;
ll t,n,k,z,c[N];
using namespace std;

bool valid(ll x){
    if(x == 0 or x == 1) return true;
    ll s = 0;
    ll carry = 0;
    for(ll i = 1; i <= n; i++){
        if(c[i] == 0){
            carry = 0;
        }else {
            ll aux = carry + c[i];
            if (aux >= x) {
                s += aux / x;
                carry = aux % x;
            }
            else carry = c[i];
        }
    }
    return (s>=k);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--){
        cin>>n>>k;
        ll totalalum = 0;
        for(ll i = 1; i <= n; i++){
            cin>>c[i];
            totalalum+=c[i];
        }
        ll x = 0;
        z = totalalum/k;
        for(ll b = z; b>=1; b/=2){
            while(valid(x+b) ){
                x+=b;
            }
        }
        cout<<(x*k)<<"\n";
    }
    return 0;
}