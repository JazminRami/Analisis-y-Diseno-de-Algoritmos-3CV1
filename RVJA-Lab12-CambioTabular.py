import time
import resource

def count(coins, n, sum):
    # dp[i] almacenará el número de soluciones para el valor i.
    dp = [0 for k in range(sum+1)]
    # Caso base (si el valor dado es 0)
    dp[0] = 1
    # Tomar todas las monedas una por una y actualizar los valores dp[]
    # después del índice mayor o igual al valor de la moneda tomada
    for i in range(n):
        for j in range(coins[i], sum+1):
            dp[j] += dp[j - coins[i]]
    return dp[sum]

if __name__ == '__main__':
    # Iniciar la medición del tiempo y memoria
    start_time = time.time()
    start_memory = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss

    # Inicializar las monedas y el objetivo
    coins = [1, 2, 3]
    n = len(coins)
    sum = 5

    # Llamada a la función count y mostrar el resultado
    res = count(coins, n, sum)
    print(f"Para la cantidad de {sum}, se puede dar cambio de {res} maneras distintas")

    # Finalizar la medición y calcular la diferencia
    end_time = time.time()
    end_memory = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
    execution_time = end_time - start_time
    memory_used = end_memory - start_memory

    # Imprimir los resultados
    print(f"El tiempo de ejecución es: {execution_time:.6f} segundos")
    print(f"La memoria utilizada es: {memory_used} bytes")


