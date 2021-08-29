  
#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int main() {
    for (int i = 0; i < 100; i++){
        cout << "Para "<< i << ": " << (i - (i&-i)) << endl;
    }
}