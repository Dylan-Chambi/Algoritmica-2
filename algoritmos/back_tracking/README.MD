# BackTracking

![](https://www.apascualco.com/wp-content/uploads/2020/01/backtrakcing.png)

> Implementado por [Dylan Chambi](https://github.com/Dylan-Chambi)

**BackTracking** es una forma de encontrar soluciones, descartando caminos en cuanto estos no cumplan algun criterio.

## Tabla de Contenido

- [N-Reinas](https://github.com/Dylan-Chambi/Algoritmica-2/blob/d802ddcc82a159278ff628c4d3a4051ff9efec1a/algoritmos/back_tracking/n_reinas.cpp)
- [Sudoku](https://github.com/Dylan-Chambi/Algoritmica-2/blob/ad879c868fc9a6460861f6519a5657ee35360160/algoritmos/back_tracking/sudoku.cpp)

# Explicacion de la Implementacion

Las soluciones mediante Backtraking siempre requiere un lugar donde ir almacenando los pasos a seguir, recursividad y un metodo de verificacion de los pasos realizados.


# Explicacion del algoritmo

**BackTracking** funciona recorriendo pasos uno a uno para llegar a una solucion y, se detiene y vuelve atras cuando el paso no cumple con el criterio de aceptacion de la solucion. del mismo modo este recorrido se podria decir que es "DFS" ya que va aumentando pasos a la solucion anterior siempre que sean validos y termina cuando se llegue al caso base de la recursividad.
