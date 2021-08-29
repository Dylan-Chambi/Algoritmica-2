# Trie - Estructura de Datos

![](https://www.askpython.com/wp-content/uploads/2020/10/trie-1024x512.png.webp)

> Creador por [Rene de la Briandais](https://es.wikipedia.org/w/index.php?title=Rene_de_la_Briandais&action=edit&redlink=1) y [Edward Fredkin](https://es.wikipedia.org/w/index.php?title=Edward_Fredkin&action=edit&redlink=1)

> Implementado por [Dylan Chambi](https://github.com/Dylan-Chambi)

**Trie** es una estructura de datos que almacena una vez el prefijo de las palabras (crea uno si no existe), haciendo asi que las consultas deriven de este arbol.

## Tabla de Contenido

- [Trie con Arreglos](https://github.com/Dylan-Chambi/Algoritmica-2/blob/main/algoritmos/estructura_de_datos/trie/trie_array.cpp)
- [Trie con Map](https://github.com/Dylan-Chambi/Algoritmica-2/blob/main/algoritmos/estructura_de_datos/trie/trie_map.cpp)
- [Trie con Arreglo - Metodo 'Delete'](https://github.com/Dylan-Chambi/Algoritmica-2/blob/main/algoritmos/estructura_de_datos/trie/trie_metodo_delete/delete_number_words/trie_array_delete.cpp)
- [Trie con Arreglo - Metodo 'Delete' para varias palabras](https://github.com/Dylan-Chambi/Algoritmica-2/blob/main/algoritmos/estructura_de_datos/trie/trie_metodo_delete/delete_number_words/trie_array_delete.cpp)

# Explicacion de la Implementacion

Se crea mediante nodos que almacenan el o los caracteres de las palabras. si no existe un nodo se crea conectado al prefijo existente.


# Explicacion del algoritmo

Trie agarra las palabras que le pasamos y va creando un arbol de prefijos, donde podemos almacenar distintos atributos. Las consultas son mas rapidas debido a que simplemente se debe seguir las divisiones del arbol.
