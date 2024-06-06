import time
import resource

def count(coins, n, sum):
    # Si la suma es 0, hay 1 solución (no incluir ninguna moneda)
    if sum == 0:
        return 1
    # Si la suma es menor que 0, no hay solución
    if sum < 0:
        return 0
    # Si no hay monedas y la suma es mayor que 0, no hay solución
    if n <= 0:
        return 0
    # Contar la suma de soluciones incluyendo y excluyendo la moneda n-1
    return count(coins, n - 1, sum) + count(coins, n, sum - coins[n - 1])

if __name__ == '__main__':
    # Iniciar la medición del tiempo y memoria
    start_time = time.time()
    start_memory = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss

    coins = [1, 2, 3]
    n = len(coins)
    sum = 5

    # Llamada a la función count y mostrar el resultado
    ways_to_change = count(coins, n, sum)
    print(f"Para la cantidad de {sum}, se puede dar cambio de {ways_to_change} maneras distintas")

    # Finalizar la medición y calcular la diferencia
    end_time = time.time()
    end_memory = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
    execution_time = end_time - start_time
    memory_used = end_memory - start_memory

    print(f"El tiempo de ejecución es: {execution_time:.6f} segundos")
    print(f"La memoria utilizada es: {memory_used} bytes")






