# Edmonds-Karp - Teoria de Grafos

![](https://slidetodoc.com/presentation_image_h/c8144c38b8b0a5dcc687c92d677c8d93/image-58.jpg)

> Creador por [Jack Edmonds](https://en.wikipedia.org/wiki/Jack_Edmonds) y [Richard Karp](https://en.wikipedia.org/wiki/Richard_Karp)

> Implementado por [Dylan Chambi](https://github.com/Dylan-Chambi)

**Edmonds-Karp** es un algoritmo de la teoria de grafos donde dado un arreglo dirigido, un inicio **s** y un final **t**. Encuentra el maximo flujo de **s** a **t**.

## Tabla de Contenido

- [Edmonds-Karp](https://github.com/Dylan-Chambi/Algoritmica-2/blob/ce21c4af6bea4c18cf3bfcdffda0cac307707ba3/algoritmos/grafos/edmonds_karp/edmonds_karp.cpp)


# Explicacion de la Implementacion

Usamos una matriz para guardar el grafo a utilizar con sus respectivos pesos, usamos BFS para hallar el camino (en vertices) mas corto hasta t. Y por ultimo un arreglo para guardar el camino de cada flujo.


# Explicacion del algoritmo

**Edmons-Karp** funciona haciendo un recorrido BFS desde s hasta llegar a visitar t, seguarda el camino y se le resta a las pesos el minimo de todos los vertices del camino, y se suma al contra grafo de residuos. y Sumamos el minimo al **Maximo Flujo** se hace esto hasta que en algun momento no encuentre ningun camino a t (osea t == -1).

Al final se tendra el maximo flujo del grafo.
