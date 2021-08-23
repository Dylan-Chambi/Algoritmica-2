# Digit DP


## Explicacion del Digit DP 🛠️

Como su nombre indica, Digit DP funciona mediante operaciones en los digitos de un numero (que se guarda para cuando se repita el numero pero con mas digitpos) y guardamos la operacion que deseamos que se cumpla para cuando halla recorrido todos los digitos pregunte si se cumple o no.

## Explicacion de la creacion 🛠️

Se crea mediante recursividad, donde probamos todas las combinacionbes de digitos (que no exceda el limite) y vamos guardando los resultados para ahorrar futuras operaciones.

## Explicacion del algoritmo 🛠️

Digit DP funciona haciendo backtracking agarrando 2 rangos de numeros y calculando para ambos las operaciones que se quieren en la funcion de solve(). Luego de calcular devuelve la diferencia del resultado de ambos rangos de numeros.
