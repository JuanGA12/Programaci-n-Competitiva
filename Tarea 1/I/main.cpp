/*
* Complejidad Espacial: O( sizeof(int)*N )
* Complejidad Temporal: O( n! ) 
* Idea: Backtracking
 *      llamamos a recursive y en cada llamada
 *      iteramos de 1 hasta n. En cada iteracion sumamos el
 *      elemento actual con el anterior y vemos si esa suma es prima.
 *      Si la suma es prima entonces agregamos el elemento actual
 *      a nuestro vector de sol y llamamos a recursive de i + 1.
 *      Nos vamos por una rama y si no encontramos la respuesta regremos
 *      un paso y vamos por la otra opcion, asi sucesivamente hasta
 *      encontrar la respuesta
* */

#include <iostream>
#include <vector>
using namespace std;
const int N = 17;
int n,num[N];
vector<int> sol;

bool isPrim(int i){
    if(i>1){
        for(int j = 2; j<i;j++){
            if(i%j ==0){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}
void recursive(int i){
    if(i == n){
        int n1 = sol[0];
        int n2 = sol[n-1];
        sol[0] = 1;
        if(isPrim(n1+n2)){
            for(int j = 0; j<sol.size();j++) {
                if (j == sol.size()-1) {
                    cout << sol[j];
                } else {
                    cout << sol[j] << " ";
                }
            }
            cout<<"\n";
        }
        return;
    }else{
        for(int k = 1; k<=n;k++){
            if(num[k] != 0) {
                int n1 = sol[i - 1];
                int n2 = num[k];
                if (isPrim(n1+n2)) {
                    sol.push_back(num[k]);
                    int temp = num[k];
                    num[k] = 0;
                    recursive(i + 1);
                    num[k] = temp;
                    sol.pop_back();
                }
            }else continue;
        }
    }
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    for(int i = 1; i<=n;i++){//n
        num[i-1] = i;
    }
    sol.push_back(1);//1
    recursive(1);

}