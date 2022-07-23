/*
* Complejidad Espacial: O( s )
* Complejidad Temporal: O( n! ) mismo que el problema general de reinas.
* Idea: Backtracking
 *      llamamos a recursive n veces y en cada llamada
 *      iteramos de 1 hasta 8. En cada iteracion comprobamos si row == r
 *      si, cumple llamamos a recursive de row + 1 y luego hacemos break.
 *      Si row != r, tenemos que comprobar ciertos criterios para poder
 *      colocar la reina en esa columna. Si es posible colocar entonces
 *      ponemos 1 en los array de col, dia1 y dia2 y guardamos en nuestra
 *      respuesta. Volvemos a llamar a recursive de row + 1.
 *      Nos vamos por una rama y si no encontramos la respuesta regremos
 *      un paso y vamos por la otra opcion, asi sucesivamente hasta
 *      encontrar la respuesta
* */
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
const int N = 20;
int r,c;
int col[N];
int dia1[N];
int dia2[N];
vector<int>rpta(N,0);
vector<vector<int>> s;
 void recursive(int row){
    if(row == 9) {
        s.push_back(rpta);
        rpta[c]=r;
        return;
    }
    for(int i = 1; i <= 8;i++){
        if(row == r ){  // en caso sean iguales, el if de la linea 24 siempre sera true y no pasara ese if y llamara a recursive(+1)
            recursive(row+1);
            break;
        }else {
            if (col[i] or dia1[i + row] or dia2[i - row + 8]) continue;
            col[i] = dia1[i + row] = dia2[i - row + 8] = 1;
            rpta[i] = row;
            recursive(row + 1);
            col[i] = dia1[i + row] = dia2[i - row + 8] = 0;
        }
    }
}
int main() {
    cin >> r >> c;
    rpta[c]=r;
    col[c] = dia1[c + r] = dia2[c - r + 8] = 1;
    recursive(1);
    sort(s.begin(),s.end());
    for(int i = 0; i <s.size(); ++i){
        auto d = s[i];
        for(int j = 1; j<=8; ++j){
            if(j == 8){
                cout<<d[j];
            }else {
                cout << d[j] << " ";
            }
        }
        cout<<endl;
    }
}
