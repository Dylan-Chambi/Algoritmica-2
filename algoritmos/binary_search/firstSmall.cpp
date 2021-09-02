#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int n;
int x;
int A[100000];
bool f(int number) {
    return number <= x;
}

void bs() {
    int ini = 0;
    int fin = n - 1;
    int mid = (ini + fin) / 2;
    int pos = -1;
    while(ini <= fin ) {
        if(f(A[mid])) {  /// MOdificar la funcion de condicion
            pos = mid;
            ini = mid + 1;
            
        } else {
            fin = mid - 1;
        }
        mid = (ini + fin) / 2;
    }
    if(f(A[pos])) {
        cout<<A[pos]<<endl;
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
45 5 7 9 13 17 4 9 5 6 2 4 6
8
*/