
/*
 * Complejidad Espacial: O( sizeof(int)*N )
 * Complejidad Temporal: O( nlog(b-s) )
 * Idea: Hacemos una busqueda ternaria desde el minimo valor de h hasta
 *       el máximo valor de h, para cada busqueda llamamos a peso(x), ahi
 *       retornamos el costo que produciria que todos los pilares sean de
 *       tamaño x. En base a ese costo vamos actualizando los valores de b o
 *       s y guardando en min_peso el peso minimo hasta ese paso.
 *       Una vez que la diferencia entre b y s sea muy poca (o 0) termina el while
 *       e imprimimos min_peso.
 *       La busqueda ternaria se realiza en logn y peso en n.
 *
 * */

#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e5+1;
ll n,a,r,m,h[N];
ll peso(ll x){

    ll cantidad_mayor = 0, cantidad_menor = 0, cnt;
    for (ll i = 0; i < n; i++) (h[i] > x) ? cantidad_mayor += (h[i] - x) : cantidad_menor += (x - h[i]);

    ll aux_min = min(cantidad_mayor, cantidad_menor);

    if( m < (a+r) ) cnt = aux_min * m;
    else cnt = aux_min * (a+r);

    ll veces_mayor = cantidad_mayor - aux_min;
    ll veces_menor = cantidad_menor - aux_min;
    cnt += a * veces_menor;
    cnt += r * veces_mayor;

    return cnt;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>a>>r>>m;
    ll min = LONG_MAX,max = LONG_MIN;
    for(ll i = 0; i < n; i++) {
        cin>>h[i];
        if(min > h[i]) min = h[i];
        if(max < h[i]) max = h[i];
    }
    ll s = min;
    ll b = max;
    ll min_peso;

    while (b-s>=ll(1e-9)){
        ll s2 = s + ((b - s) / 3);
        ll b2 = b - ((b - s) / 3);
        if(peso(s2) < peso(b2)) {
            min_peso = peso(s2);
            b = b2 - 1;
        }
        else {
            min_peso = peso(b2);
            s = s2 + 1;
        }
    }
    cout<<min_peso;

    return 0;
}