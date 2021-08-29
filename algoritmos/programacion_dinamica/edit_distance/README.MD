# Edit Distance - Programacion Dinamica

![](https://wakicode.files.wordpress.com/2017/09/74bc0fa858652701ff47bfd125c83eeb.png?w=534)

> Creado por [Vladimir Levenshtein](https://es.wikipedia.org/wiki/Vlad%C3%ADmir_Levensht%C3%A9in)
> Implementado por [Dylan Chambi](https://github.com/Dylan-Chambi)

Dadas 3 operaciones (eliminar, adicionar y editar). **Edit Distance** nos permite saber cual es el numero minimo de operaciones para que 2 strings sean iguales.

## Tabla de Contenido

- [Edit Distance](https://github.com/Dylan-Chambi/Algoritmica-2/blob/c347ae2811cd02b3f9b6e23903faf94ab63cb840/algoritmos/programacion_dinamica/digit_dp/digit_dp.cpp)

# Explicacion de la Implementacion

Se crea una matriz dodne cada eje representa una palabra y cada celda es el minimo de operaciones para cada sub-palabras de las palabras originales. De este modo simple tomamos el minimo de operaciones para cada sub-palabra hasta llegar a la palabra completa.


# Explicacion del algoritmo

**Edit Distance** funciona con Programacion Dinamica guardando los minimos para sub-palabras y en base a eso, encontrar el minimo entre las 2 palabras.
Ubicamos 2 punteros el final de cada palabra y hacemos recursividad hasta llegar al caso de que solo tenemos 1 letra de alguna de las palabras. cada operacion tiene un coste de 1, pero si los caracteres son iguales el coste es de 0. Vamos aplicando las 3 operaciones y a esas 3 operaciones tambien aplicamos las 3 operaciones y asi vamos formando un "arbol" de operaciones.
y guardamos esas operaciones en la matriz y asi no los calculamos de nuevo en otro camino del arbol.