/*
 * Complejidad Espacial: O( sizeof(int)*N )
 * Complejidad Temporal: O( n + m*(r-l) )
 * Idea: La idea comun hubiera sido ordenar el sub arreglo de l hasta r,
 *       pero esto hacia que excediera el Time Limit. Decidí contar
 *       cuantos mayores a arr[x] habien entre l hasta r, asi luego restaba
 *       r con la cantidad de mayores (este resultado me daria la nueva posicion del elemento
 *       arr[x]) luego comprobaba si la poscion nueva era igual a la inicial y en base
 *       a eso imprimia Yes o No
 *
 * */

#include <iostream>
using namespace std;
const int N = 1e4+10;
int n,m,l,r,x;
int arr[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i = 1; i<=n; ++i) cin>>arr[i];// n
    while(m){   // m
        cin>>l>>r>>x;
        int cnt = 0;
        for(int i = l; i<=r;++i){ // r - l
            if(arr[i] > arr[x] ) cnt++;
        }
        int pos = r-cnt;
        if(pos==x){
            m==1 ? cout<<"Yes" : cout<<"Yes"<<"\n";
        }else {
            m==1 ? cout<<"No" : cout<<"No"<<"\n";
        }
        m--;
    }
}
