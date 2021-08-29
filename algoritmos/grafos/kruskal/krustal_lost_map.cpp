#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
// Variables
#define MAX_N 10000    // Maximo numero de vertices o nodos

using namespace std; 

// parent y rango sirven para el union find 
int parent[MAX_N];
int rango[MAX_N];

int n; // n numero de nodos y m numero de aristas s

void init() {
    for(int i=0;  i< MAX_N; i++) {
        parent[i] = i;
        rango[i] = 0;
    }
}

int find(int x) {
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

bool sameComponent(int nodeA,int nodeB) {
    return find(nodeA) == find(nodeB);
}

void unionRango(int x,int y) {
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
    } else {
        parent[xRaiz] = yRaiz;
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

struct Arista{
    long long origen;
    long long destino; 
    long double peso; 
    Arista(){}
    bool operator<(const Arista &a) const {
        if(peso == a.peso) {
            return origen < a.origen;
        } else {
            return peso < a.peso;
        }
    }
}aristas[MAX_N];

Arista MST[MAX_N]; // n-1 aristas 

int numAristasArbol = 0;
double kruskal(int nroNodos, int nroAristas) {
    
    int origen, destino;
    double peso;
    double total = 0;
    numAristasArbol = 0;
    init();
    sort(aristas,aristas + nroAristas);

    for (int i = 0; i < nroAristas; i++)
    {
        origen = aristas[i].origen;
        destino = aristas[i].destino;
        peso = aristas[i].peso;

        if(!sameComponent(origen,destino)) { // estos 2 dos nodos forman un ciclo 
            total += peso; 
            unionRango(origen,destino);  // unimos los nodos
            MST[numAristasArbol] = aristas[i]; // Guardamos la arista agregada
            numAristasArbol++; // incrementados la posicion para la futura arista
            
        }
    }
    return total;
}


int main()
{
    cin >> n;
    int contador = 0;
    int grafo[n+1][n+1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
                cin >> grafo[i][j];
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            aristas[contador].origen = i;
            aristas[contador].destino = j;
            aristas[contador].peso = grafo[i][j];
            contador++;
        }
    }
    kruskal(n, contador);
    for (int i = 0; i < numAristasArbol; i++)
    {

        cout << MST[i].origen << " " << MST[i].destino<< endl;
    }
    return 0;
}
/*
4
0 1 1 2
1 0 2 3
1 2 0 3
2 3 3 0

1 2
1 3
1 4
*/
/*
7
0 2 9 1 4 3 3
2 0 11 1 6 3 3
9 11 0 10 5 12 12
1 1 10 0 5 2 2
4 6 5 5 0 7 7
3 3 12 2 7 0 4
3 3 12 2 7 4 0
*/