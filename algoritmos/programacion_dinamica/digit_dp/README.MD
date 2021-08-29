# Digit DP - Programacion Dinamica

> Implementado por [Dylan Chambi](https://github.com/Dylan-Chambi)

Como su nombre indica, **Digit DP** funciona mediante operaciones en los digitos de un numero (que se guarda para cuando se repita el numero pero con mas digitpos) y guardamos la operacion que deseamos que se cumpla para cuando halla recorrido todos los digitos pregunte si se cumple o no.

## Tabla de Contenido

- [Digit DP - Solo 2 digitos pares](https://github.com/Dylan-Chambi/Algoritmica-2/blob/c347ae2811cd02b3f9b6e23903faf94ab63cb840/algoritmos/programacion_dinamica/digit_dp/digit_dp.cpp)
- [Digit DP - Suma de digitos es primo](https://github.com/Dylan-Chambi/Algoritmica-2/blob/c347ae2811cd02b3f9b6e23903faf94ab63cb840/algoritmos/programacion_dinamica/digit_dp/DigitDP_sum_digit_primos.cpp)

# Explicacion de la Implementacion

Se crea mediante recursividad, donde probamos todas las combinacionbes de digitos (que no exceda el limite) y vamos guardando los resultados para ahorrar futuras operaciones.


# Explicacion del algoritmo

**Digit DP** funciona haciendo backtracking agarrando 2 rangos de numeros y calculando para ambos las operaciones que se quieren en la funcion de solve(). Luego de calcular devuelve la diferencia del resultado de ambos rangos de numeros.
Para cada rango **"fabricamos"** numeros a los que deseamos aplicar las operaciones, al final si cumple con la el requisito de la solucion. sumamos 1 en la parte del arreglo de [True] y para numeros que sean casi parecidos a uno calculado previamente, solo consultamos los que ya tenemos y guardamos el resultado.
