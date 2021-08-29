#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
string number;
int dp[2000][2][200][200];

// modificar el 3er parametro de acuerdo al problema
// 0 true 0
// 0 ....... number
long long solve_dp(int pos, int mayor,int impares, int suma) {
    if(pos > number.size()) { // cuando la posicion exceda al numero dado
        return 0;
    }
    // Modificar de acuerdo al problema
    if(pos == number.size()) {
        cout<<impares<<endl;
        if(impares >= 2) { 
            return 1;
        }
        else {
            return 0;
        }
    }
    if(dp[pos][mayor][impares][suma] == -1) { // Pregunto si no lo he calculado 
        int tope = 9;
        if(mayor == true) {  // el numero que voy a crear puede llegar a ser mayor
            tope = number[pos]-'0';  // solo podemos usar los numeros de 0 al tope -- '3'-'0' =  51 - 48 = 3 
        }
        dp[pos][mayor][impares][suma] = 0;
        for(int digito = 0; digito <= tope; digito++) {
            if(digito == tope ) {
                // cout<<pares<<" "<<digito<<" "<< (digito%2 == 0) <<endl;
                int total= suma + digito;
                int esImpar = 0;
                if(total > 0){
                    if (digito%2 != 0){
                        esImpar = 1;
                    }
                }
                dp[pos][mayor][impares][suma] += solve_dp(pos+1, true, impares + esImpar, total);
            }
            else { // 0 1 2 
                //cout<<pares<<" "<<digito<<" "<< (digito%2 == 0) <<endl;
                int total = suma + digito;
                int esImpar = 0;
                if(total > 0){
                    if (digito%2 != 0){
                        esImpar = 1;
                    }
                }
                dp[pos][mayor][impares][suma] += solve_dp(pos+1, false, impares + esImpar, total);
            }
        }
    }
    return dp[pos][mayor][impares][suma];
}



int main(){

    // hallar los numeros que tengan 2 pares en su interior del rango 20 hasta 30

    int a, b;
    cin >> a >> b;
    // calculando f(a)
    number = to_string(a-1);
    memset(dp, -1, sizeof(dp));
    int pares_hasta_a = solve_dp(0, true, 0,0);
    // calculando f(b)
    memset(dp, -1, sizeof(dp));
    number = to_string(b);
    int pares_hasta_b = solve_dp(0, true, 0, 0);
    // total para f(a,b) = f(b) - f(a-1)
    cout<< pares_hasta_b-pares_hasta_a;
    return 0;
}
/*
120 150
*/