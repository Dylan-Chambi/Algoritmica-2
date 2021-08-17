#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int reinas = 4;
// El algoritmo no esta terminado :(

void backTracking(int posicion, int solucion[]){
    for(int i = 0; i < reinas; i++){
        solucion[posicion] = i;
        if(i == 0){
            if(solucion[posicion] == 0 && solucion[posicion] == i){
                return;
            }
        }else if(i == reinas-1){
            if(solucion[posicion] == i && solucion[posicion] == i){
                return;
            }
        }else{
            if(solucion[posicion] == reinas-1 || solucion[posicion]-1 == i || solucion[posicion]+1 == i){
                return;
            }
        }
        solucion[posicion] = i;
        if(posicion = 3){
            return;
        }
        return backTracking(posicion+1, solucion);
    }
}


int main(){
    int arreglo[reinas];
    backTracking(0, arreglo);

    for(int i = 0; i < reinas; i++){
        cout << arreglo[i] << endl;
    }
}