#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
vector<pair<int, int> > grafo[100000];
bool visitados[100000];

// Dados un grafo G, sus pesos W y el número de nodos n devuelve el coste del árbol mínimo
// generador usando el algoritmo de Prim
int Prim(int verticeInicial){
    multiset<pair<int, int>> colaPrioridad;
    colaPrioridad.insert(make_pair(0, verticeInicial)); //cola de prioridad de parejas de enteros (-distancia del nodo a F, nodo)
    int answer = 0;
    while (!colaPrioridad.empty()){
        pair<int, int> verticeActual = *colaPrioridad.begin();
        colaPrioridad.erase(colaPrioridad.begin()); //lo quitamos de la cola

        int vertice = verticeActual.second; //vértice de Q a menor distancia de F
        int peso = verticeActual.first; //distancia entre F y v

        if (!visitados[vertice]){ //si no lo hemos visitado
            visitados[vertice] = true;
            answer += peso;
            for (int i = 0; i < grafo[vertice].size(); ++i){ //miramos sus vecinos
                int verticeVecino = grafo[vertice][i].second;
                int pesoVecino = grafo[vertice][i].first;
                colaPrioridad.insert(make_pair(pesoVecino, verticeVecino)); // añadimos los vecinos conectados con u
            }
        }   
    }

    return answer; // devolvemos el coste
}

int main()
{
    int vertices, aristas;
    cin >> vertices >> aristas;
    for (int i = 0; i < aristas; i++)
    {
        int ini,fin,peso; 
        cin>>ini>>fin>>peso;
        grafo[ini].push_back(make_pair(peso,fin));
        grafo[fin].push_back(make_pair(peso,ini));
    }
    cout <<  Prim(1) << endl;
    return 0;
}
/*
Input:
9 16
0 1 2
1 2 9
2 3 11
2 4 10
1 4 8
3 5 5
4 6 7
6 5 2
5 9 1
5 8 4
8 9 5
7 8 9
7 6 3
0 7 7
4 3 6
6 8 6

Output:
39
*/

/*
12 16
1 3 15
2 3 7
12 10 14
8 3 9
8 2 10
3 2 8
2 1 27
10 4 13
1 4 17
1 5 20
4 5 20
4 9 23
5 9 18
2 7 21
7 11 30
5 11 25
*/