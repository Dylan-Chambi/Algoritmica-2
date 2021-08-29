# Kruskal - Teoria de Grafos

![](https://miro.medium.com/max/1838/1*8KdxxE3sybLcPrPN-hAQnA.png)

> Creador por [Joseph Kruskal](https://es.wikipedia.org/wiki/Joseph_Kruskal)

> Implementado por [Dylan Chambi](https://github.com/Dylan-Chambi)

**Kruskal** es un algoritmo de la teoria de grafos, que nos permite saber cual es el arbol de expansion minimo. Osea que exista un camino para llegar a cada vertice sin formar ciclos (osea un arbol) y con el peso minimo.

## Tabla de Contenido

- [Kruskal](https://github.com/Dylan-Chambi/Algoritmica-2/blob/main/algoritmos/estructura_de_datos/bit/bit.cpp)

- [Kruskal - Lost Map](https://github.com/Dylan-Chambi/Algoritmica-2/blob/main/algoritmos/estructura_de_datos/bit/bit.cpp)


# Explicacion de la Implementacion

Usamos la estructura de datos de [Union-Find](https://github.com/Dylan-Chambi/Algoritmica-2/blob/5fc9b6d23a55952944e14e48b8f6a2a036108fdd/algoritmos/estructura_de_datos/union_find/README.MD) para las conexiones y lo hacemos con un arreglo con los vertices ordenados por peso.


# Explicacion del algoritmo

**Kruskal** funciona gracias a que ordenamos los vertices segun el peso mediante una funcion sort, despues usamos [Union-Find](https://github.com/Dylan-Chambi/Algoritmica-2/blob/5fc9b6d23a55952944e14e48b8f6a2a036108fdd/algoritmos/estructura_de_datos/union_find/README.MD) para saber si no formamos un ciclo. Si se forma un ciclo no se hace nada, pero si no se forma, los conectamos con un union() y asi hasta revisar todos los vertices.

![](https://upload.wikimedia.org/wikipedia/commons/a/a3/UnionFindKruskalDemo.gif)