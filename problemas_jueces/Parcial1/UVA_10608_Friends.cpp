#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int parent[10000];
int rango[10000];
int grupos;

void init() {
    for(int i=0;  i<= grupos; i++) {
        parent[i] = i;
        rango[i] = 0;
    }
}

int findFriends(int x) {
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = findFriends(parent[x]);
        return parent[x];
    }
}

void unionRango(int x,int y) { 
    int xRaiz = findFriends(x);
    int yRaiz = findFriends(y);
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
    int cases;
    cin >> cases;
    while(cases--){
        int nrounionRango;
        cin>> grupos >>nrounionRango;
        init();
        while(nrounionRango--) {
            int x,y;
            cin>>x>>y; 
            unionRango(x,y);
        }
        int ans = 0;
        int conocidos[grupos+1] = {0};
        for (int i = 1; i <= grupos; i++)
        {
            conocidos[findFriends(i)]++;
        }
        for (int i = 1; i <= grupos; i++)
        {
            if(ans < conocidos[i]){
                ans = conocidos[i];
            }
        }
        if(ans == 0){
            cout << 1 << endl;
        }else{
            cout << ans << endl;
        }

    }
    return 0;
}
/*
Sample Input
2
3 2
1 2
2 3
10 12
1 2
3 1
3 4
5 4
3 5
4 6
5 2
2 1
7 1
1 2
9 10
8 9
Sample Output
3
7
*/
/*
1
10 7
4 10
6 4
6 10
7 5
5 1
3 6
7 3
*/