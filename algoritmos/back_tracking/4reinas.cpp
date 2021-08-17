#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
bool encontrado = false;
// El algoritmo no esta terminado :(

bool esValido(int posicion, int solucion[], int reinas){
    for(int i = 0; i < posicion; i++){
        if(solucion[i] == solucion[posicion] || abs(solucion[i] - solucion[posicion]) == abs(i - posicion)){
            return false;
        }
    }
    return true;
}

void backTracking(int posicion, int solucion[], int reinas){
    if(posicion > 3 && !encontrado){
        cout << "Termine" << endl;
        for(int i = 0; i < reinas; i++){
            cout << solucion[i] << endl;
        }
        encontrado = true;
        return;
    }

    for(int i = 0; i < reinas; i++){
        solucion[posicion] = i;
        if(esValido(posicion, solucion, reinas)){
            backTracking(posicion+1, solucion, reinas);
        }
    }


}


int main(){
    int numeroDeReinas;
    cin >> numeroDeReinas;
    int arreglo[numeroDeReinas];
    backTracking(0, arreglo, numeroDeReinas);

}