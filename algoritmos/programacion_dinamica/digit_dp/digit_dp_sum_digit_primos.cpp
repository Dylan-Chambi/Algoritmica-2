#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int dp[20][2][20][20];
string number;

bool isPrime(int n){
    
    if(n == 2) {
        return true;
    } 
    if(n < 2 || n % 2 == 0) {
        return false;
    }
    for(int i = 3; i*i<=n; i+=2) {
        if( n%i == 0) {
            return false;
        }
    }
    return true;
}

int solve_dp(int pos, int mayor,int sumaDigitos, int suma) {
    if(pos > number.size()) { // cuando la posicion exceda al numero dado
        return 0;
    }
    // Modificar de acuerdo al problema
    if(pos == number.size()) {
        // cout<<pares<<endl;
        if(isPrime(sumaDigitos)) { // tiene 2 pares el numero 
            return 1;
        }
        else {
            return 0;
        }
    }
    if(dp[pos][mayor][sumaDigitos][suma] == -1) { // Pregunto si no lo he calculado 
        int tope = 9;
        if(mayor == true) {  // el numero que voy a crear puede llegar a ser mayor
            tope = number[pos]-'0';  // solo podemos usar los numeros de 0 al tope -- '3'-'0' =  51 - 48 = 3 
        }
        dp[pos][mayor][sumaDigitos][suma] = 0;
        for(int digito = 0; digito <= tope; digito++) {
            if(digito == tope ) {
                dp[pos][mayor][sumaDigitos][suma] += solve_dp(pos+1, true, suma+digito > 0? sumaDigitos+digito: 0, suma+digito);
            }
            else {
                dp[pos][mayor][sumaDigitos][suma] += solve_dp(pos+1, false, suma+digito > 0? sumaDigitos+digito: 0, suma+digito);
            }
        }
    }
    return dp[pos][mayor][sumaDigitos][suma];
}
int main(){
    int a, b;
    cin >> a >> b;
    // calculando f(a)
    number = to_string(a-1);
    memset(dp, -1, sizeof(dp));
    int pares_hasta_a = solve_dp(0, true, 0, 0);
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