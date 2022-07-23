/*
 * Complejidad Espacial: O( sizeof(int)*N )
 * Complejidad Temporal: O( nlogn )
 * Idea: Hacemos una busqueda binaria.
 *       El chiste es encontrar un x donde flash y zoom se encuentren (mismo tiempo).
 *       El x puede ir de 0 hasta l, incluyendo decimales.
 *       En getTime calculamos cuanto tiempo se demora flash y zoom para llegar a x y
 *       en base a eso actualizamos a o b. Si el tiempo de flash y zoom es igual
         imprimimos ese tiempo y hacemos break y termina el programa.
 *       La busqueda binaria se realiza en logn y getTime en n.
 *
 * */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const int N = 1e5+1;
int t,n,l,arr[N];
double getTime(double x,int m){
    double vel = 1, time = 0;
    int aux = m==1 ? 0 : l;
    if (m==1){
        for(int i = 0; i < n; i++){
            if(arr[i] > x) break;
            else {
                time += (arr[i] - aux)/vel;
                vel++, aux = arr[i];
            }
        }
        time += (x - aux)/vel;
    }else{
        for(int i = n-1; i >= 0; i--){
            if(arr[i] < x) break;
            else {
                time += (aux - arr[i])/vel;
                vel++, aux = arr[i];
            }
        }
        time += (aux - x)/vel;
    }
    return time;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>t;
    while(t--){
        cin>>n>>l;

        for(int i = 0; i < n; i++)  cin>>arr[i];
        double time, a = 0, b = static_cast<double>(l), timeF, timeZ;

        while(b-a>=1e-9){
            double x = a + (b-a)/2;
            timeF = getTime(x,1), timeZ = getTime(x,2);
            if(abs(timeF-timeZ) < 1e-9){
                time = timeF;
                cout<<fixed<<setprecision(8)<<time<<"\n";
                break;
            }else if(timeF < timeZ) a = x;
            else b = x;
        }
    }
}