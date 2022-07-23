
/*
 * Complejidad Espacial: O( a )
 * Complejidad Temporal: O( nlogn )
 * Idea: Primero ordenamos a de menor a mayor.
 *       En suma vamos a ir guardamos la suma de todos los valores de a en cada
 *       iteracion.
 *       En s vamos a ir guardando la suma de todos los primeros elementos
 *       de a en cada iteracion
 *       A a le hacemos pop_front al final de cada iteracion.
 *       Una vez que termina el for, imprimimos suma + s y el programa termina.
 *       s  suma
 *          1 2 3 4 -> array de cantidad de alitas por paquete. Un paquete de 1 alita, otro de 2 y asi.
 *       1  2 3 4
 *       2  3 4
 *       3  4
 *       El programa toma nlogn solo por el sort, ya que el for se hace en n
*/

#include <iostream>
#include <forward_list>
#include <numeric>
#include <vector>

using namespace std;
long long n;
forward_list<long long> a;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    long long suma = 0, aux = 0;
    for (long long i = 1; i <= n; i++) {
        long long j;
        cin >> j;
        a.push_front(j);
        aux += j;
        suma = aux;
    }
    a.sort();
    long long s = 0;
    for (long long i = 1; i < n; i++) {
        s+=a.front();
        aux -=a.front();
        suma += aux;
        a.pop_front();
    }
    cout << suma+s;
    return 0;
}