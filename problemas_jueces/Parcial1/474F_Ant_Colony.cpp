#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define length(x) (sizeof(x) / sizeof(x[0]))
using namespace std;
long long numeros[101010] = {0};
long long arraySize;

struct node {
    int minimo;
    int gcdSegment;
    int countMin;
}segmentTree[1010101];

int gcd(int a , int b){
    if (b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

void init(int ini, int fin, int nodoActual) {
    if(ini == fin) {
        segmentTree[nodoActual].minimo = numeros[ini];
        segmentTree[nodoActual].gcdSegment = numeros[ini];
        segmentTree[nodoActual].countMin = 1;
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
        segmentTree[nodoActual].minimo = min(segmentTree[hijoIzq].minimo, segmentTree[hijoDer].minimo);
        segmentTree[nodoActual].gcdSegment = gcd(segmentTree[hijoIzq].gcdSegment, segmentTree[hijoDer].gcdSegment);
        
        if(segmentTree[hijoIzq].minimo == segmentTree[hijoDer].minimo){
            segmentTree[nodoActual].countMin = segmentTree[hijoIzq].countMin + segmentTree[hijoDer].countMin;

        }else if(segmentTree[hijoIzq].minimo < segmentTree[hijoDer].minimo){
            segmentTree[nodoActual].countMin = segmentTree[hijoIzq].countMin;
        }else{
            segmentTree[nodoActual].countMin = segmentTree[hijoDer].countMin;
        }
    }
}

node query(int ini, int fin, int nodoActual, int i, int j)
{
    if (ini >= i && fin <= j)
    {
        return segmentTree[nodoActual];
    }
    else
    {
        int medio = (ini + fin) / 2;
        int hijoIzq = 2 * nodoActual + 1;
        int hijoDer = 2 * nodoActual + 2;
        if (j <= medio)
        {
            return query(ini, medio, hijoIzq, i, j);
        }
        else if (i > medio)
        {
            return query(medio + 1, fin, hijoDer, i, j);
        }
        else
        {
            node queryIzq = query(ini, medio, hijoIzq, i, j);
            node queryDer = query(medio + 1, fin, hijoDer, i, j);
            node resultado;

            resultado.minimo = min(queryIzq.minimo, queryDer.minimo);
            resultado.gcdSegment = gcd(queryIzq.gcdSegment, queryDer.gcdSegment);

            if (queryIzq.minimo == queryDer.minimo)
            {
                resultado.countMin = queryIzq.countMin + queryDer.countMin;
            }
            else if (queryIzq.minimo < queryDer.minimo)
            {
                resultado.countMin = queryIzq.countMin;
            }
            else
            {
                resultado.countMin = queryDer.countMin;
            }
            return resultado;
        }
    }
}

int main() {
    int queries;
    scanf("%d", &arraySize);
    for(int i = 0; i < arraySize; i++){
        scanf("%d", &numeros[i]);
    }
    init(0, arraySize-1, 0);

    scanf("%d", &queries);
    while(queries--){
        int l, r;
        scanf("%d%d", &l, &r);
        node ans = query(0, arraySize-1, 0, l-1, r-1);;

        if(ans.gcdSegment == ans.minimo){
            printf("%d\n",(r-l+1)-ans.countMin);
        }else{
            printf("%d\n", (r-l+1));
        }
    }
    return 0;
}
/*
Input:

5
1 3 2 4 2
4
1 5
2 5
3 5
4 5

Output:

4
4
1
1
*/