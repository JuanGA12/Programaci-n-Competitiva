/*
 * Complejidad Espacial: O( INT_MAX )
 * Complejidad Temporal: O( n^2 )
 * Idea: Use una funcion recursiva que va de 1 hasta n,
 *       por cada llamada a esa funcion se evalua de i hasta n
 *       para comprobar los intervalos. Llenamos en un array "occ"
 *       para guardar las ocurrencias (dominante) de cada elemento de cada iteracion.
 *       En base eso comprobamos 3 casos y actualizamos nuestras maximos y minimos.
 *       Dentro de cada caso vamos aumentando en 1 en el array de respuestas
 *       en el menor indice. Una vez terminado el for regresamos las variables globales
 *       a su estado origanal para futuras consultas. Finalmente imprimimos los valores de rpta
 *       de i hasta n
 * */

#include <iostream>
#include <map>

using namespace std;
const int N = 5010;
int numbers[N], rpta[N], occ[N], n, max_index = INT_MIN, min_index = INT_MAX;

void recursive(int i){
    if( i == n+1 ){
        for(int j = 1; j <= n; ++j)cout<<rpta[j]<<" ";
        return;
    }else{
        for(int j = i; j <= n; ++j){

            int index = numbers[j];
            int index_occ = ++occ[index];

            if(index_occ > max_index) {
                max_index = index_occ;
                min_index = index;
                rpta[min_index]++;
                continue;
            }
            if(index_occ == max_index){
                min_index = min(min_index,index);//Varios colores dominantes, se escoge el menor índice.
                rpta[min_index]++;
                continue;
            }
            if(index_occ < max_index){
                rpta[min_index]++;
                continue;
            }
        }
        max_index = INT_MIN;
        min_index = INT_MAX;
        for(int k = 1; k <= n; ++k) occ[k] = 0;//Se cambio el map por array para reducir complejidad.
        recursive(i+1);
    }
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    for(int i = 1; i <= n; ++i)cin>>numbers[i];//se llenan con indices
    recursive(1);
}
