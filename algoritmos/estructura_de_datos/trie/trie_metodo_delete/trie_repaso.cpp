#include <bits/stdc++.h> 

using namespace std; 

struct node {
    char currentCharacter;       
    bool isWord = false;
    int contadorLetras = 0;
   //  int priority = 0;            
    struct node *children[10];  // [null,null,null,......,null]
}*trie;

// Inicializar 

void init() {
    trie = new node();  // Instanciar el objeto trie
}

int palabrasConPrefijo(string prefijo){
    node *currentNode =  trie; 
    for (int i = 0; i< prefijo.length(); i++) { // alba
        int character = prefijo[i] -  '0';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL) {
            return 0;
        }
        currentNode = currentNode->children[character];
    }
    return currentNode->contadorLetras;
}

void insertWord(string word) {   // alba 
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) { // alba
        int character = word[i] -  '0';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL ) {
            currentNode->children[character] = new node();
           // currentNode->isWord = false;
        }
      //   currentNode = max(currentNode->priority,priority);
        currentNode = currentNode->children[character];
        currentNode->currentCharacter = word[i];
        currentNode->contadorLetras++;
    }
    currentNode->isWord = true;
}

bool searchWord(string word) {   // alto 
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) {
        int character = word[i] -  '0';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL ) {
           return false;
        }
        currentNode = currentNode->children[character];
    }
    return currentNode->isWord;
}

void isThereWord(string word) {
    if(searchWord(word)) {
        cout<<"Si existe "<< "'" << word << "'"<< " en el trie"<<endl;
    } else {
        cout<<"No Existe "<< "'" << word << "'"<< " en el trie"<<endl;
    }
}

void deleteWord(string word){
    if(searchWord(word)){
        node *currentNode =  trie;
        int depthNodeDelete = 1;

        int tempDepth = 0;
        for (int i = 0; i< word.length(); i++) {
            int character = word[i] -  '0';
            if(currentNode->children[character]->isWord && word.length() != i+1) {
                depthNodeDelete+= tempDepth;
            }
            currentNode = currentNode->children[character];
            tempDepth++;
        }
        currentNode->isWord = false;
        currentNode =  trie;
        for (int i = 0; i< depthNodeDelete; i++) {
            int character = word[i] -  '0';
            currentNode = currentNode->children[character];
        }
        currentNode = NULL;
        delete currentNode;
        cout << "Se elimino una palabra " << "'" << word <<  "'" << " del trie" << endl;
    }else{
        cout << "No se puede borrar " << "'" << word <<  "'" << " porque no es una palabra en el trie"<< endl;
    }
}

int main() {
    // Inicializar Trie
    init();
    insertWord("2350");
    insertWord("2150");
    insertWord("2210");
    insertWord("2211");

    cout << palabrasConPrefijo("2210") << endl;

    return 0;
}