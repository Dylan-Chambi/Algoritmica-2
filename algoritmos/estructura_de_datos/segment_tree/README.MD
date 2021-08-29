# Segment Tree - Estructura de Datos

![](https://java2blog.com/wp-content/webpc-passthru.php?src=https://java2blog.com/wp-content/uploads/2018/10/SegmentTreeTC.jpg&nocache=1)

> Creador por [Jon Louis Bentley](https://en.wikipedia.org/wiki/Jon_Bentley_(computer_scientist))

> Implementado por [Dylan Chambi](https://github.com/Dylan-Chambi)

**Segment Tree** es una estructura de datos que nos ayuda a la hora de realizar consultas para operaciones (Monoides) en un determinado rango 'a' - 'b'.

## Tabla de Contenido

- [Segment Tree](https://github.com/Dylan-Chambi/Algoritmica-2/blob/main/algoritmos/estructura_de_datos/segment_tree/segmen_tree.cpp)

# Explicacion de la Implementacion

Se crea mediante un array que almacena los datos de un rango cada vez mas pequeño.


# Explicacion del algoritmo

**Segment Tree** simplemente agarra nuestro arreglo, y gracias a la recursividad, puede crear un el arreglo del Segment Tree con Lazy Propagation, lo que nos permite que cualquier actualizacion / consulta sea en tiempo aproximado a O(log(n)).
