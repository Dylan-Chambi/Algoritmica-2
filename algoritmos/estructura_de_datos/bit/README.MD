# BIT (Binary Indexed Tree) - Estructura de Datos

![](https://miro.medium.com/max/700/0*E9BYdnnPHkXVIiFK.gif)

> Creador por [Boris Ryabko](https://boris.ryabko.net/)

> Implementado por [Dylan Chambi](https://github.com/Dylan-Chambi)

**BIT** es una estructura de datos que almacena las consultas en potencias de 2.tas para operaciones (Monoides) en un determinado rango 'a' - 'b'.

## Tabla de Contenido

- [BIT](https://github.com/Dylan-Chambi/Algoritmica-2/blob/main/algoritmos/estructura_de_datos/bit/bit.cpp)

# Explicacion de la Implementacion

Se crea mediante un array que almacena los datos de un rango cada vez mas pequeño (de potencias de 2). Teniendo un arbol diferente para consultas y para updates.


# Explicacion del algoritmo

**BIT** simplemente agarra nuestro arreglo, y mediante el (Bit menos significativo), este almacena los datos en rangos de potencias de 2. Lo que hace que ocupe menos memoria que el Segment Tree.