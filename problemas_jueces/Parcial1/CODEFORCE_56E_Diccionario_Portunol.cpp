#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

struct Trie {
    int children[26];
} trieNode[1010101];
int TrieSize;

int suffix[26], ending[26];
void insertTrie(int root, string word) {
    int index = root;
	for(int i = 0; i < word.length(); i++) {
        int character = word[i]-'a';
		if(trieNode[index].children[character] == 0) {
			TrieSize++;
			memset(&trieNode[TrieSize], 0, sizeof(trieNode[0]));
			trieNode[index].children[character] = TrieSize;
		}
		index = trieNode[index].children[character];
	}
}


void insertTrieSuffix(int root, string word) {
	int index = root;
    int L = word.length();
    ending[word[L - 1]-'a']++;
	for(int i = L - 1; i >= 0; i--) {
        int character = word[i]-'a';
		if(trieNode[index].children[character] == 0) {
			TrieSize++;
			memset(&trieNode[TrieSize], 0, sizeof(trieNode[0]));
			trieNode[index].children[character] = TrieSize;
            suffix[character]++;
		}
		index = trieNode[index].children[character];
	}
}
long long ans = 0;
void contarCombinaciones(int index, int root) {
    for (int i = 0; i < 26; i++) {
        if (trieNode[index].children[i] != 0) {
            contarCombinaciones(trieNode[index].children[i], root);
            if (index != root && ending[i] != 0)
                ans++;
        } else {
            if (index != root)
                ans += suffix[i];
        }
    }
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) && n + m != 0) {
        
        memset(suffix, 0, sizeof(suffix));
        memset(ending, 0, sizeof(ending));
        memset(&trieNode[0], 0, sizeof(trieNode[0]));
        memset(&trieNode[1], 0, sizeof(trieNode[1]));

        TrieSize = 1;
        string palabra;
        for (int i = 0; i < n; i++) {
            cin >> palabra;
            insertTrie(0, palabra);
        }
        for (int i = 0; i < m; i++) {
            cin >> palabra;
            insertTrieSuffix(1, palabra);
        }
        ans = 0;
        contarCombinaciones(0, 0);
        printf("%lld\n", ans);
    }
    return 0;
}
/*
Sample Input
3 3
mais
grande
mundo
mas
grande
mundo
1 5
a
aaaaa
aaaaaa
aaaaaaa
a
aaaaaaaaa
1 1
abc
abc
0 0

Sample Output
182
9
8
*/