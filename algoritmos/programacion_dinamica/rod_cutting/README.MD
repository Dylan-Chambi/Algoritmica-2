# Rod Cutting - Programacion Dinamica

![](https://i2.wp.com/techieme.in/wp-content/uploads/01knapsack.png?fit=1213%2C392)

Si bien esta imagen es de una matriz con los tamaños y los cortes. se puede hacer perfectamente en un solo arreglo del tamaño de la barra.

> Implementado por [Dylan Chambi](https://github.com/Dylan-Chambi)

Dados el tamaño de una barra, cortes y ganancias de esos cortes. **Rod Cutting** nos permite encontrar cual es la ganancia maxima para un tamaño de barra dado.

## Tabla de Contenido

- [Rod Cutting](https://github.com/Dylan-Chambi/Algoritmica-2/blob/5fc9b6d23a55952944e14e48b8f6a2a036108fdd/algoritmos/programacion_dinamica/rod_cutting/rod_cutting.cpp)

# Explicacion de la Implementacion

Se necesita un arreglo para guardar la ganancia maxima para cada unidad hasta llegar al tamaño de la barrra. Se usa recursividad para cada corte, lo que crearia un arbol de cortes y estos llegan hasta los casos base. Para cada corte sumamos la ganancia maxima y en base a esa ganancia decidimos con que corte quedarnos.


# Explicacion del algoritmo

**Rod Cutting** funciona con **Programacion Dinamica** con un enfoque Top-Down donde partimos desde el tamaño de la barra y lo vamos dividiendo  hasta llegar a los casos base donde no se pueda dividir mas y vamos calculando los siguientes en base a los calculados previamente hasta llegar al resultado.
Cada corte que se hace puede haber sido calculado previamente y ahi entra la **Programacion Dinamica** ya que nos ahorra ese calculo.