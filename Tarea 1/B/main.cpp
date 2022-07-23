/*
 * Complejidad Espacial: O ( a )
 * Complejidad Temporal: O( cantidad * (plop + s*(loga) + a) )
 * Idea: Guardamos en un map las ocurrencias de los caracteres de p.
 *       Luego iteramos por s y vamos comprobando sus caracteres con
 *       los caracteres de t, luego vamos haciendo operaciones (insertando en s y
 *       decrementando la cantidad de ocurrencias de cada caracter de p) en
 *       base a los casos. Finalmente limpiamos el map para futuros inputs y
 *       comprobamos si s == t, en base a eso imprimimo Yes o No.
 * */

#include <iostream>
#include <map>
using namespace std;
int cantidad;
string s;
string t;
string p;
map<char,int> a;

void task(){ // plogp + s(loga) + a

    for(auto &i : p){   //p
        a[i]++; // log p
    }
    for(int j = 0; j<s.size()+1;j++){ //s
        if(s[j] == t[j]){
            continue;
        }else{
            auto g = a.find(t[j]); //log a
            if(g!=a.end() and a[t[j]]>0 ){ //log a
                if(s[j] == '\0'){
                    s+=t[j]; //s
                }else{
                    s.insert(j,1,t[j]);//s
                }
                a[t[j]]--; //log a
            }
        }
    }
    a.clear(); // a
    if(s == t){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}
int main() {

    cin>>cantidad;
    while (cantidad--) {//cantidad
        cin >> s >> t >> p;
        task();
        if(cantidad != 0){
            cout<<endl;
        }
    }
}
