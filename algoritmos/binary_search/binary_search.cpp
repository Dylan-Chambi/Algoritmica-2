#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int n, x;
int arreglo[100000+1];

bool f(int mid) {
    return x > arreglo[mid];
}


int binarySearch() {
    int ini  = 0;
    int fin = n;
    int ans = -1;
    while(fin - ini > 1) {
        int mid = (fin + ini)/2;
        if(x > arreglo[mid]) {    //la izquierda es mas pequena que mid
            ini = mid + 1;
        }
        else{
            if(x < arreglo[mid]){    //la derecha es mas pequeno que mid
            fin = mid - 1;
            }else{      // Le medio es igual al numero
                ans = mid;
                break;
            }
        }
    }
    return ans;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin>>arreglo[i];
    }
    cin >> x;
    cout<<binarySearch()<<endl;
    return 0;
}
/*
10
2 4 6 8 10 12 14 16 18 20
12
*/