
/*
 * Complejidad Espacial: O( sizeof(int)*N )
 * Complejidad Temporal: O( n )
 * Idea: Usamos la tecnica de puntero doble, i apunta al inicio de h y
 *       j al final de h. Tenemos que hallar la mayor area seleccionando una cantidad
 *       de barras. Empezamos con i y j, usamos de base a j-i, y altura al minimo entre
 *       h[i] y h[j], hallamos el area y vemos si es mayor al area anterior,
 *       si es mayor acutalizamos el valor del area. Luego si h[i] es mejor a h[j] i a la
 *       derecha, caso contrario j a la izquierda (Nos conviene quedarnos con la
 *       mayor altura).
 *       Una vez terminado el while abremos obtenido el area maxima.
 *       Como es la tecnica de puntero doble, el programa se realiza en n.
 *
 * */

#include <iostream>
using namespace std;
const int N = 2e5+1;
int n,h[N];
int main() {
    cin>>n;
    for(int i = 1; i <= n; i++)cin>>h[i];
    int i=1,j=n,area=0;
    while( i != j){
        int base = j-i,altura = min(h[i],h[j]);
        if( base*altura > area ) area = base*altura; //Mayor area
        ( h[i] < h[j] ) ? i++ : j--;//Si h[i] es mejor i a la derecha, caso contrario j a la izquierda
    }
    cout<<area;
    return 0;
}
