#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 

struct node {
    char currentCharacter;
    int NumberOfWords = 0;
   //  int priority = 0;            
    struct node *children[27];  // [null,null,null,......,null]
}*trie; 

// Inicializar 

void init() {
    trie = new node();  // Instanciar el objeto trie
}

void insertWord(string word) {   // alba 
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) { // alba
        int character = word[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL ) {
            currentNode->children[character] = new node();
           // currentNode->isWord = false;
        }
      //   currentNode = max(currentNode->priority,priority);
        currentNode = currentNode->children[character];
        currentNode->currentCharacter = word[i];
    }
    currentNode->NumberOfWords++;
}

int searchWord(string word) {   // alto 
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) {
        int character = word[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL) {
           return 0;
        }
        currentNode = currentNode->children[character];
    }
    return currentNode->NumberOfWords;
}


/*
int findWords(string prefix) {   // alto 
    node *currentNode =  trie;  
    for (int i = 0; i< prefix.length(); i++) {
        int character = prefix[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL ) {
           return 0;
        }
        currentNode = currentNode->children[character];
    }
    return currentNode->countWords;
}*/
/*
void showTrie(node currentNode ) {
    node *currentNode =  trie;  
    for (int i =0; i< 27; i++) {
        currentNode = currentCharacter = word[i];
        cout (char(i+'a'));
        showTrie(currentNode)
    }
}*/

void isThereWord(string word) {
    int count = searchWord(word);
    if(count > 0) {
        cout<<"Existen " << count << " palabras de '" << word <<  "'" <<" en el trie"<<endl;
    } else {
        cout<<"No Existen palabras de '" << word <<  "'" << " en el trie"<<endl;
    }
}
void deleteWord(string word){
    node *currentNode =  trie;
    for (int i = 0; i< word.length(); i++) {
        int character = word[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL) {
            if(word.length() != i){
            cout << "No se puede borrar " << "'" << word <<  "'" << " porque no existe en el trie"<< endl;
            }
        }
        currentNode = currentNode->children[character];
    }
    if(currentNode->NumberOfWords > 0){
        currentNode->NumberOfWords--;
        cout << "Se elimino una palabra " << "'" << word <<  "'" << " del trie" << endl;
    }else{
        cout << "No se puede borrar " << "'" << word <<  "'" << " porque no existe en el trie"<< endl;
    }
}

int main() {
    // Inicializar Trie
    init();
    insertWord("auto");
    isThereWord("auto");

    insertWord("automoviles");
    isThereWord("automoviles");

    insertWord("segment");
    insertWord("segment");
    isThereWord("segment");

    insertWord("bit");
    isThereWord("bit");


    deleteWord("auto");
    isThereWord("auto");

    deleteWord("segment");
    isThereWord("segment");

    deleteWord("segment");
    isThereWord("segment");

    return 0;
}