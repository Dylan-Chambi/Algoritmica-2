# TRIE - Método 'delete'


## Explicacion del trie 🛠️

El trie es una estructura de datos que nos ayuda cuando tenemos que realizar consultas rapidas para un conjunto de palabras.

## Explicacion de la creacion 🛠️

Se crea a partir de Nodos, los cuales cada uno tiene hijos los cuales son el siguiente caracter de alguna palabra. Podemos aumentar contadores u otras cosas segun veamos necesario.

## Explicacion del metodo delete 🛠️

El metodo delete simplemente simplemente verifica si nos encontramos en una palabra del trie, calculamos la profundidad del prefijo que pertenece a otra palabra y cambiamos el atributo isWord a false. Y con la profundidad intentamos eliminar el nodo que ya no forma parte del trie.

### Ejemplo de Output 📄

_Este es un ejemplo que está en el mismo código_

```
Si existe 'auto' en el trie
Si existe 'automoviles' en el trie
Si existe 'segment' en el trie
Si existe 'bit' en el trie
Se elimino una palabra 'auto' del trie
No Existe 'auto' en el trie
Se elimino una palabra 'segment' del trie
No Existe 'segment' en el trie
No se puede borrar 'segmento' porque no es una palabra en el trie
No Existe 'segment' en el trie
No se puede borrar 'auto' porque no es una palabra en el trie
No Existe 'auto' en el trie
```
