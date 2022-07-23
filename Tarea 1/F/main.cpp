/*
 * Complejidad Espacial: O( sizeof(int)*N )
 * Complejidad Temporal: O( t*nlogn )
 * Idea: Ordenamos s para que sea mas facil de comparar.
 *       Usamos una funcion recusiva de 1 hasta 1025, k puede tomar entre 1 hasta 1024
 *       en cada llamada creamos un nuevo array (aux). A cada elemento de aux lo
 *       guardamos como xor de i con elemento de s, despues ordenamos ese array
 *       y comprabamos si es igual al array s y en base a eso imprimos i. Si son iguales
 *       terminamos el programa caso contrario llamamos a recursive de i + 1.
 * */


#include <iostream>
#include <bits/stdc++.h>
const int N = 1040;
int t,n,s[N];

using namespace std;

bool isSame(const int *a1, const int *a2){
    for(int j = 0; j < n; ++j){
        if(a1[j] != a2[j]){
            return false;
        }
    }
    return true;
}
void recursive(int i){//nlogn
    if(i == 1025){
        cout<<-1<<"\n";
        return;
    }else{
        int aux[N];
        for(int j = 0; j < n; ++j){ //n
            aux[j] = i^s[j];
        }
        sort(aux,aux+n); //Hacemos un sort para comparar arreglos nlogn
        if(isSame(s,aux)){ //n
            cout<<i<<"\n";
            return;
        }else{
            recursive(i+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0; i < n; ++i)cin>>s[i]; // n
        sort(s,s+n);//Hacemos un sort para comparar arreglos // nlogn
        recursive(1);//k*nlog == nlogn
    }
}
