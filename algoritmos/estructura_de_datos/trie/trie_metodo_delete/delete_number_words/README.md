# TRIE - Método 'delete' para varias palabras


## Explicacion 🛠️

Mi método funciona incorporando un contador de número de palabras para poder ver el número total de palabras y simplemente si disminuimos en 1 la cantidad de palabras SÓLO si el número de palabras es mayor a 0.

### Ejemplo de Output 📄

_Este es un ejemplo que está en el mismo código_

```
Existen 1 palabras de 'auto' en el trie
Existen 1 palabras de 'automoviles' en el trie
Existen 2 palabras de 'segment' en el trie
Existen 1 palabras de 'bit' en el trie
Se elimino una palabra 'auto' del trie
No Existen palabras de 'auto' en el trie
Se elimino una palabra 'segment' del trie
Existen 1 palabras de 'segment' en el trie
No se puede borrar 'segmento' porque no existe en el trie
No se puede borrar 'segmento' porque no existe en el trie
Existen 1 palabras de 'segment' en el trie
```
