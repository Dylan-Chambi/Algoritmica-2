#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int n;
int x;
int A[100000];

bool f(int number) {
    return number > x;
}

void bs() {
    int ini = 0;
    int fin = n - 1;
    while(fin - ini > 1) {
        int mid = (ini + fin) / 2;
        if(f(A[mid])) {  /// MOdificar la funcion de condicion
            fin = mid;
        } else {
            ini = mid+1;
        }
    }
    if(f(A[fin])) {
        cout<<A[fin]<<endl;
    }else {
        cout<<"No hay elementos mayores"<<endl;
    }
}

int main() {
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    cin>>x;
    bs();
    return 0;
}
/*
13
1 2 3 4 5 6 7 8 9 10 11 12 13
5
*/
/*
6
2 5 7 9 13 17
8
*/