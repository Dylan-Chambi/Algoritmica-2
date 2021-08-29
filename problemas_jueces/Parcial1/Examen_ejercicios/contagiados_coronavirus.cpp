#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int parent[10000];
int rango[10000];
map <string, int> personas;

void init(int n) {
    for(int i=0;  i<= n; i++) {
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

int main() {
    int n, m;
    cin>>n >> m;
    init(n);
    for(int i = 0; i < n; i++) {
        string persona;
        cin >> persona;
        personas[persona] = i;
    }
    while(m--) {
        string x,y;
        cin>>x>>y; 
        unionRango(personas[x],personas[y]);
    }
    string contagiado;
    cin >> contagiado;
    int ans = -1;
    for(int i = 0; i < n; i++){
        if(find(personas[contagiado]) == find(i)){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
/*
5 3
Paul Juan Monica Lucas Eliana
Paul Juan
Juan Monica
Lucas Eliana
Paul
*/