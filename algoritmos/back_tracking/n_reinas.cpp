#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
bool encontrado = false;
// El algoritmo terminado :)

bool esValido(int posicion, int solucion[], int reinas)
{
    for (int i = 0; i < posicion; i++)
    {
        if (solucion[i] == solucion[posicion] || abs(solucion[i] - solucion[posicion]) == abs(i - posicion))
        {
            return false;
        }
    }
    return true;
}

void backTracking(int posicion, int solucion[], int reinas)
{
    if (!encontrado)
    {
        if (posicion > reinas - 1)
        {
            cout << "Termine" << endl;
            for (int i = 0; i < reinas; i++)
            {
                for(int j = 0; j < reinas; j++){
                    if(solucion[j] == i){
                    cout << "[" << solucion[j]+1 << "]";
                    }else{
                         cout << "[ ]";
                    }
                }
                cout << endl;
            }
            cout << endl;
            encontrado = true;
            return;
        }

        for (int i = 0; i < reinas; i++)
        {
            solucion[posicion] = i;
            if (esValido(posicion, solucion, reinas))
            {
                backTracking(posicion + 1, solucion, reinas);
            }
        }
    }
}

int main()
{
    while (true)
    {
        int numeroDeReinas;
        cout << "Escribe '0' para salir o ingrese numero de reinas: " << endl;
        cin >> numeroDeReinas;
        if(numeroDeReinas == 0){
            break;
        }else if(numeroDeReinas < 0){
            cout << "Numero no valido" << endl << endl;
            continue;
        }
        encontrado = false;
        int arreglo[numeroDeReinas];
        backTracking(0, arreglo, numeroDeReinas);
        if(!encontrado){
            cout << "No se pudo encontrar una solucion para ese numero" << endl << endl;
        }
    }
}
/*
Input:
4


Output:
[ ][ ][1][ ]
[2][ ][ ][ ]
[ ][ ][ ][3]
[ ][4][ ][ ]
*/
