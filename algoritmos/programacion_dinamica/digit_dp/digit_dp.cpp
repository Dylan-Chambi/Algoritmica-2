#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int dp[20][2][20];

int solve_dp(string number, int pos, int mayor,int pares) {
    if(pos > number.size()) { // cuando la posicion exceda al numero dado
        return 0;
    }
    // Modificar de acuerdo al problema
    if(pos == number.size()) {
        if(pares == 2) { // tiene 2 pares el numero 
            return 1;
        }
        else {
            return 0;
        }
    }

    if(dp[pos][mayor][pares] == -1) { // Pregunto si no lo he calculado 
        int tope = 9;
        if(mayor == true) {  // el numero que voy a crear puede llegar a ser mayor
            tope = number[pos]-'0';  // solo podemos usar los numeros de 0 al tope -- '3'-'0' =  51 - 48 = 3 
        }
        dp[pos][mayor][pares] = 0;
        for(int digito = 0; digito <= tope; digito++) {
            int esPar = digito%2 == 0;
            if(digito == tope) {
                dp[pos][mayor][pares] += solve_dp(number, pos+1, true, pares + esPar);
            }
            else { // 0 1 2 
                dp[pos][mayor][pares] += solve_dp(number, pos+1, false, pares + esPar);
            }
        }
    }
    return dp[pos][mayor][pares];
}



int main(){
    // hallar los numeros que tengan 2 pares en su interior del rango 20 hasta 30
    string a = "10";
    string b = "100";
    // calculando f(a)
    memset(dp, -1, sizeof(dp));
    int pares_hasta_a = solve_dp(a, 0, true, 0);
    // calculando f(b)
    memset(dp, -1, sizeof(dp));
    int pares_hasta_b = solve_dp(b, 0, true, 0);
    // total para f(a,b) = f(b) - f(a-1)
    cout<< pares_hasta_b - pares_hasta_a;
    return 0;
}