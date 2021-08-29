#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int parent[20010];
int rango[20010];
int n;

void init() {
    for(int i=0;  i < 20010; i++) {
        parent[i] = i;
        rango[i] = 1;
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

int enemiesArray(int x) {
    return x+n;
}

int main() {
    while(scanf("%d", &n) == 1) {
        init();
        int operacion, x, y;
        while(scanf("%d %d %d", &operacion, &x, &y) == 3) {
            if(operacion == 0 && x == 0 && y == 0){
                break;
            }
            if(operacion == 1) {
                if(find(x) == find(enemiesArray(y)) || find(y) == find(enemiesArray(x))){
                    cout << -1 << endl;
                }else {
                    unionRango(x, y);
                    unionRango(enemiesArray(x), enemiesArray(y));
                }
            } else if(operacion == 2) {
                if(find(x) == find(y) || find(enemiesArray(x)) == find(enemiesArray(y))){
                    cout << -1 << endl;
                }else {
                    unionRango(x, enemiesArray(y));
                    unionRango(y, enemiesArray(x));
                }
            } else if(operacion == 3) {
                if(find(x) == find(y) || find(enemiesArray(x)) == find(enemiesArray(y))){
                    cout << 1 << endl;
                }else{
                    cout << 0 << endl;
                }
            } else {
                if(find(x) == find(enemiesArray(y)) || find(y) == find(enemiesArray(x))){
                    cout << 1 << endl;
                }
                else{
                    cout << 0 << endl;
                }
            }
        }
    }
    return 0;
}
/*
Sample Input
10
1 0 1
1 1 2
2 0 5
3 0 2
3 8 9
4 1 5
4 1 2
4 8 9
1 8 9
1 5 2
3 5 2
0 0 0
Sample Output
1
0
1
0
0
-1
0
*/