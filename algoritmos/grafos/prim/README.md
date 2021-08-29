# Kruskal - Teoria de Grafos

![](https://upload.wikimedia.org/wikipedia/commons/9/9b/PrimAlgDemo.gif)

> Creador por [Vojtěch Jarník](https://es.wikipedia.org/wiki/Vojt%C4%9Bch_Jarn%C3%ADk)

> Implementado por [Dylan Chambi](https://github.com/Dylan-Chambi)

**Prim** es un algoritmo de la teoria de grafos, que nos permite saber cual es el arbol de expansion minimo. Osea que exista un camino para llegar a cada vertice sin visitar un vertice que ya se visito antes.

## Tabla de Contenido

- [Prim](https://github.com/Dylan-Chambi/Algoritmica-2/blob/3b6efc3854dbecfc5fcbe070ef9496051b7bc0df/algoritmos/grafos/prim/prim.cpp)


# Explicacion de la Implementacion

Usamos la misma logica de [Dijkstra](https://es.wikipedia.org/wiki/Algoritmo_de_Dijkstra), usamos un vector de pares con (peso y vertice), un arreglo de visitados y una cola prioridad ordenada por los pesos añadidos de los vertices visitados.


# Explicacion del algoritmo

**Prim** funciona de la misma forma que funciona [Dijkstra](https://es.wikipedia.org/wiki/Algoritmo_de_Dijkstra), solo que simplemente vamos sumando el peso de los vecinos (el minimo de ellos) y cada vez que sumamos alguno, vemos sus vecinos y lo añadimos a la cola de prioridad. Esto se hace hasta que la cola de prioridad queda vacia.