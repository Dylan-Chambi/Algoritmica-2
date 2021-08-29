#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std;
int n, m;
vector<int> b(10000);


void kmpProcess(string patron)
{
    int i = 0, j = -1;
    b[0] = -1;
    while (i < m)
    {
        while ((j >= 0) && (patron[i] != patron[j]))
        {
            j = b[j];
        }
        i++;
        j++;
        b[i] = j;
    }
}

int kmpSearch(string texto, string patron)
{
    int freq = 0;
    int i = 0, j = 0;
    while (i < m)
    {
        while ((j >= 0) && (texto[i] != patron[j]))
        {
            j = b[j];
        }
        ++i;
        ++j;
        if (j == m)
        {
            ++freq;
            j = b[j];
        }
    }
    return freq;
}

int main()
{
   int casos;
   cin >> casos;
    while (casos--){
        cin >> n;
        bool consistente = true;
        vector<string> numeros;
        for (int i = 0; i < n; i++){
            string temp;
            cin >> temp;
            numeros.push_back(temp);            
        }
        sort(numeros.begin(), numeros.end());

        for (int i = 0; i < n-1; i++){
            m = numeros[i].size();
            kmpProcess(numeros[0]);
            if(kmpSearch(numeros[i+1], numeros[i]) > 0){
                cout << "NO" << endl;
                consistente = false;
                break;
            }
        }
        if (consistente){
            cout << "YES" << endl;
        }
    }
}
/*
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346

NO
YES
*/