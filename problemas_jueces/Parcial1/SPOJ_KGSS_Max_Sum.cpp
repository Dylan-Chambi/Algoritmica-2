#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define length(x) (sizeof(x) / sizeof(x[0]))
using namespace std;
int arraySize;
int numeros[101010]= {0};

struct node {
    int maxSum[2] = {0, 0};
    int indice;
}segmentTree[1010101];

struct nodePair{
    int max = 0;
    int indice;
};

nodePair calMax(int maximo[]){
    nodePair ans;
    for(int i = 0; i < 2; i++){
        if(ans.max < maximo[i]){
            ans.max = maximo[i];
            ans.indice = i;
        }
    }
    return ans;
}

void init(int ini, int fin, int nodoActual) {
    if(ini == fin) {
        segmentTree[nodoActual].maxSum[0] = numeros[ini];
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

        int max1, max2;
        nodePair Max1 = calMax(segmentTree[hijoIzq].maxSum);
        nodePair Max2 = calMax(segmentTree[hijoDer].maxSum);
        max1 = Max1.max;
        max2 = Max2.max;

        for(int i = 0; i < 2; i++){
            if(Max1.indice != i){
                if(max2 < segmentTree[hijoIzq].maxSum[i]){
                    max2 = segmentTree[hijoIzq].maxSum[i];
                }
            }
            if(Max2.indice != i){
                if(max1 < segmentTree[hijoDer].maxSum[i]){
                    max1 = segmentTree[hijoDer].maxSum[i];
                }
            }
        }
        segmentTree[nodoActual].maxSum[0] = max1;
        segmentTree[nodoActual].maxSum[1] = max2;

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

            int max1, max2;
            nodePair Max1 = calMax(queryIzq.maxSum);
            nodePair Max2 = calMax(queryDer.maxSum);
            max1 = Max1.max;
            max2 = Max2.max;

            for(int i = 0; i < 2; i++){
                if(Max1.indice != i){
                    if(max2 < queryIzq.maxSum[i]){
                        max2 = queryIzq.maxSum[i];
                    }
                }
                if(Max2.indice != i){
                    if(max1 < queryDer.maxSum[i]){
                        max1 = queryDer.maxSum[i];
                    }
                }
            }
            resultado.maxSum[0] = max1;
            resultado.maxSum[1] = max2;
            return resultado;
            }
    }
}

void update(int ini, int fin, int nodoActual, int x, int valor) {
    if(ini == x && fin == x){
        segmentTree[nodoActual].maxSum[0] = valor;
    } else {
        int medio = (ini + fin) / 2;
        int hijoIzq = 2 * nodoActual + 1;
        int hijoDer = 2 * nodoActual + 2;
        if (x <= medio ) {
            update(ini, medio, hijoIzq, x, valor);
        }else if (x > medio){
            update(medio+1,fin,hijoDer,x,valor);
        }
        int max1, max2;
        nodePair Max1 = calMax(segmentTree[hijoIzq].maxSum);
        nodePair Max2 = calMax(segmentTree[hijoDer].maxSum);
        max1 = Max1.max;
        max2 = Max2.max;

        for(int i = 0; i < 2; i++){
            if(Max1.indice != i){
                if(max2 < segmentTree[hijoIzq].maxSum[i]){
                    max2 = segmentTree[hijoIzq].maxSum[i];
                }
            }
            if(Max2.indice != i){
                if(max1 < segmentTree[hijoDer].maxSum[i]){
                    max1 = segmentTree[hijoDer].maxSum[i];
                }
            }
        }
        segmentTree[nodoActual].maxSum[0] = max1;
        segmentTree[nodoActual].maxSum[1] = max2;
    }
}

int main() {
    cin >> arraySize;
    for (int i = 0; i < arraySize; i++)
    {
        cin >> numeros[i];
    }
    init(0,arraySize-1,0);

    int queries;
    cin >> queries;
    while(queries--){
        char q;
        int x, y;
        cin >> q >> x >> y;
        if(q == 'Q'){
            node ans = query(0, arraySize-1, 0, x-1, y-1);
            cout << ans.maxSum[0]+ ans.maxSum[1] << endl;
        }else{
            update(0, arraySize-1, 0, x-1, y);
        }
    }
    return 0;
}
/*
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5

Output:
7
9
11
12
*/