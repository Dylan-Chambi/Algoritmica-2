#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6+7;
const int TREE_MAX = 1e7+7;
int numeros[MAX];
int divisores[MAX];
long long segmentTree[TREE_MAX];
bool updated[TREE_MAX];


void init(int ini, int fin, int nodoActual) {
    if(ini == fin) {
        segmentTree[nodoActual] = numeros[ini];
        updated[nodoActual] = divisores[segmentTree[nodoActual]] == numeros[ini];
        return;
    }
    int medio = (ini + fin) / 2;
    int hijoIzq = 2 * nodoActual + 1;
    int hijoDer = 2 * nodoActual + 2;
    // Ir por el hijo Izq 
    init(ini, medio, hijoIzq);
    // Ir por el hijo Der
    init(medio + 1, fin, hijoDer);
    // Actualizar el nodo actual
    segmentTree[nodoActual] = segmentTree[hijoIzq]+ segmentTree[hijoDer];
    updated[nodoActual] = updated[hijoIzq] & updated[hijoDer];
}

long long query(int ini, int fin, int nodoActual, int i, int j) {
    if(j < ini || fin < i){
        return 0;
    }
    if(i <= ini && fin <= j){ 
        return segmentTree[nodoActual];
    }
    int medio = (ini + fin) / 2;
    int hijoIzq = 2 * nodoActual + 1;
    int hijoDer = 2 * nodoActual + 2;
    long long Qizq = query(ini, medio, hijoIzq, i, j);
    long long Qder = query(medio + 1, fin, hijoDer, i, j);
    return Qizq + Qder;
}

void update(int ini, int fin, int nodoActual, int i, int j) {
    if(updated[nodoActual]){
        return;
    }
    if(j < ini || fin < i){
        return;
    }
    if(ini == fin) {
        segmentTree[nodoActual] = divisores[numeros[ini]];
        updated[nodoActual] = divisores[segmentTree[nodoActual]] == segmentTree[ini];
        return;
    }
    int medio = (ini + fin ) / 2; 
    int hijoIzq = 2 * nodoActual + 1; 
    int hijoDer   = 2 * nodoActual + 2;
    update(ini, medio, hijoIzq, i, j);
    update(medio+1,fin,hijoDer,i,j);
    segmentTree[nodoActual] = segmentTree[hijoDer] + segmentTree[hijoIzq];
}

int main() { 
    for (int i = 1; i < MAX; i++){
        for(int j = i; j < MAX; j += i){
            divisores[j]++;
        }
    }

    int queries, arraySize;
    scanf("%d%d", &arraySize, &queries);
    for (int i = 0; i < arraySize; i++)
    {
       scanf ("%d", &numeros[i]);
    }
    init(0,arraySize-1,0);


    while(queries--){
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        if(t == 1){
            update(0,arraySize-1, 0, l-1, r-1);
        }else{
            printf("%d\n", query(0,arraySize-1,0,l-1,r-1));
        }
    }
    return 0;
}
/*
Input:

7 6
6 4 1 10 3 2 4
2 1 7
2 4 5
1 3 5
2 4 4
1 5 7
2 1 7

Output:

30
13
4
22
*/
/*
7 1
6 4 1 10 3 2 4
2 4 5
*/