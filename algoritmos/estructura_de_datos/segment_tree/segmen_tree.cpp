#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define length(x) (sizeof(x) / sizeof(x[0]))
using namespace std; 
int numeros[] = {1,2,3,4,5,6,7,8};

struct node {
    int maximo;
    int minimo;
}segmentTree[1000000];

void init(int ini, int fin, int nodoActual) {
    if(ini == fin) {
        segmentTree[nodoActual].maximo = numeros[ini];
        segmentTree[nodoActual].minimo = numeros[ini];
    }
    else {
        int medio = (ini + fin) / 2;
        int hijoIzq = 2 * nodoActual + 1;
        int hijoDer = 2 * nodoActual + 2;
        // Ir por el hijo Izq 
        init(ini, medio, hijoIzq);
        // Ir por el hijo Der
        init(medio + 1, fin, hijoDer);
        // Actualizar el nodo actual
        segmentTree[nodoActual].maximo = max(segmentTree[hijoIzq].maximo, segmentTree[hijoDer].maximo);
        segmentTree[nodoActual].minimo = min(segmentTree[hijoIzq].minimo, segmentTree[hijoDer].minimo);
    }
}

node query(int ini, int fin, int nodoActual, int i, int j) {
    if(ini >= i && fin <= j){ 
        return segmentTree[nodoActual];
    }
    else {
        int medio = (ini + fin) / 2;
        int hijoIzq = 2 * nodoActual + 1;
        int hijoDer = 2 * nodoActual + 2;
        if ( j <= medio ) {
            return query(ini, medio, hijoIzq, i, j);
        }else if (i > medio){
            return query(medio+1,fin,hijoDer,i,j);
        } else {
            node queryIzq = query(ini,medio,hijoIzq,i,j);
            node queryDer = query(medio+1,fin,hijoDer,i,j);
            node resultado; 
            resultado.maximo = max(queryIzq.maximo, queryDer.maximo);
            resultado.minimo = min(queryIzq.minimo, queryDer.minimo);
            return resultado;
        }
    }
}

void update(int ini, int fin, int nodoActual, int x, int valor) {
    if(ini == x && fin == x){
        segmentTree[nodoActual].minimo = valor;
        segmentTree[nodoActual].maximo = valor;
    } else {
        int medio = (ini + fin) / 2;
        int hijoIzq = 2 * nodoActual + 1;
        int hijoDer = 2 * nodoActual + 2;
        if (x <= medio ) {
            update(ini, medio, hijoIzq, x, valor);
        }else if (x > medio){
            update(medio+1,fin,hijoDer,x,valor);
        }
        segmentTree[nodoActual].minimo = min(segmentTree[hijoIzq].minimo, segmentTree[hijoDer].minimo);
        segmentTree[nodoActual].maximo = max(segmentTree[hijoIzq].maximo, segmentTree[hijoDer].maximo);
    }
}

int main() {
    init(0,7,0);
    cout << query(0,7,0,0,7).maximo << endl;
    update(0,7,0,4,200);
    cout << query(0,7,0,0,7).maximo << endl;
    return 0;
}