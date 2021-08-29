#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define length(x) (sizeof(x) / sizeof(x[0]))
using namespace std;

int padres[10000];
int rango[10000];

void init(int n) {
    for(int i=0;  i<= n; i++) {
        padres[i] = i;
    }
}

int findFriends(int x) {
    if(x == padres[x]) {
        return x;
    }
    else {
        padres[x] = findFriends(padres[x]);
        return padres[x];
    }
}

void unionRango(int x,int y) { 
    int xRaiz = findFriends(x);
    int yRaiz = findFriends(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        padres[yRaiz] = xRaiz;
    } else {
        padres[xRaiz] = yRaiz;
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

double dist(int x1, int y1, int x2, int y2){ 
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}


int main() {
	int cases;
	cin >> cases;

	for (int i = 0; i < cases; i++){
		int n;
		cin >> n;
		init(n);

		vector<pair<double, pair<int, int>>> aristas;
		vector<pair<double, double>> coordenadas;

		for (int i = 0; i < n; i++){
            double x, y;
			cin >> x >> y;
			coordenadas.push_back(make_pair(x, y));

			for (int j = 0; j < i; j++){
				aristas.push_back(make_pair(dist(x, y, coordenadas[j].first,coordenadas[j].second), make_pair(i,j)));
			}
		}
        //Ordena de maypr a menor segun la distancia de cada arista
		sort(aristas.begin(), aristas.end());
        double distance = 0;

		for (int i = 0; i < aristas.size(); i++){
			if (findFriends(aristas[i].second.first) != findFriends(aristas[i].second.second)){
				distance += aristas[i].first;
				unionRango(aristas[i].second.first, aristas[i].second.second);
			}
		}

		printf("%.2lf\n", distance);
		if(cases > i+1){
             cout << endl;
        }
	}
	return 0;
}
/*
Sample Input
1
3
1.0 1.0
2.0 2.0
2.0 4.0
Sample Output
3.41
*/