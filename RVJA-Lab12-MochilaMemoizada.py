import time
import resource

def knapsack(wt, val, W, n):
    if n == 0 or W == 0:
        return 0
    
    if t[n][W] != -1:
        return t[n][W]

    if wt[n-1] <= W:
        t[n][W] = max(
            val[n-1] + knapsack(wt, val, W - wt[n-1], n-1),
            knapsack(wt, val, W, n-1)
        )
        return t[n][W]
    else:
        t[n][W] = knapsack(wt, val, W, n-1)
        return t[n][W]

if __name__ == '__main__':
    
    # Iniciar la medición del tiempo y memoria
    start_time = time.time()
    start_memory = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
    
    profit = [60, 100, 120]  # Valores de los elementos
    weight = [10, 20, 30]    # Pesos de los elementos
    W = 50                   # Capacidad de la mochila
    n = len(profit)          # Número de elementos

    t = [[-1 for _ in range(W + 1)] for _ in range(n + 1)]

    # Llamada a la función knapsack y mostrar el resultado
    total_value = knapsack(weight, profit, W, n)
    print(f"El valor total de la mochila es: {total_value}")

    # Finalizar la medición y calcular la diferencia
    end_time = time.time()
    end_memory = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
    execution_time = end_time - start_time
    memory_used = end_memory - start_memory

    print(f"El tiempo de ejecución es: {execution_time:.6f} segundos")
    print(f"La memoria utilizada es: {memory_used} bytes")








