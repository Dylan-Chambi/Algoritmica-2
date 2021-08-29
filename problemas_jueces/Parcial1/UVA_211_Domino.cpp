#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define length(x) (sizeof(x) / sizeof(x[0]))
using namespace std;
int queries;

struct dominos
{
    int x;
    int h;
    int indice;
}axis[100000];

bool ordenarMayorMenor(dominos d1,dominos d2)
{
    return d1.x < d2.x;
}

int main()
{
    queries;
    cin >> queries;
    for (int i = 0; i < queries; i++)
    {
        cin >> axis[i].x >> axis[i].h;
        axis[i].indice = i;
    }
    int drop[queries+5] = {1};
    int ans[queries+5];

    sort(axis, axis + queries, ordenarMayorMenor);
    
    for (int i = queries-1, j; i >= 0; i--){
        for (j = i + 1; j < queries && axis[i].x+ axis[i].h-1 >= axis[j].x;){
            j+=drop[j];
        }
        drop[i]=j-i;
        ans[axis[i].indice]=drop[i];
    }
    for (int i = 0; i < queries; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
/*
4
16 5
20 5
10 10
18 2

3 1 4 1
*/
/*
4
0 10
1 5
9 10
15 10

4 1 2 1 
*/