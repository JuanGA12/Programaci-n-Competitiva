/*
 * Complejidad Espacial: O( sizeof(int)*N )
 * Complejidad Temporal: O( n! ) En este caso n es 5 por que probamos todos
 *                               las formas posibles
 *
 * Idea: Nos basamos en backtracking, vamos probando primero con todo +
 *       si no llegamos a la respuesta ahora usamos + + + -, si no llegamos a
 *       la respuesta usamos + + - + y asi sucesivamente con todos los signos
 *       con todos los numeros. Nos vamos por una rama y si no encontramos la
 *       respuesta regremos un paso y vamos por la otra opcion, asi sucesivamente
 *       hasta encontrar la respuesta (si es que exsite.)
 * */

#include <iostream>

using namespace std;
const int N = 51;
const int result = 23;
int rpta, numbers[N];

void recursive(int n, int partial){
    if(n == 5 and partial == result){
        rpta = partial;
        return;
    } else{
        for(int i = 0; i < 5; ++i){
            if(numbers[i] != 0){
                int temp = numbers[i];

                int partial_sum = partial + numbers[i];
                //cout<<a;
                numbers[i] = 0;
                recursive(n+1,partial_sum);
                numbers[i] = temp;
                //partial-=numbers[i];

                int partial_rest = partial - numbers[i];
                //cout<<b;
                numbers[i] = 0;
                recursive(n+1,partial_rest);
                numbers[i] = temp;
                //partial+=numbers[i];

                int partial_mul = partial * numbers[i];
                //cout<<c;
                numbers[i] = 0;
                recursive(n+1,partial_mul);
                numbers[i] = temp;
                //partial/=numbers[i];
            }
        }
    }
}

int main() {

    for (int i = 0; i < 5; ++i){//k
        cin>>numbers[i];
    }
    for(int i = 0; i < 5; ++i){//k
        int temp = numbers[i];
        numbers[i] = 0;
        recursive(1,temp);
        numbers[i] = temp;
    }
    if(rpta == result){
        cout<<"Posible";
    }else{
        cout<<"Imposible";
    }
}
