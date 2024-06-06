import time
import resource

def knapSack(W, wt, val, n):
    if n == 0 or W == 0:
        return 0
    if wt[n-1] > W:
        return knapSack(W, wt, val, n-1)
    else:
        return max(
            val[n-1] + knapSack(W - wt[n-1], wt, val, n-1),
            knapSack(W, wt, val, n-1)
        )

if __name__ == '__main__':
    
    # Iniciar la medición del tiempo y memoria
    start_time = time.time()
    start_memory = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss

    profit = [60, 100, 120]  # Valores de los elementos
    weight = [10, 20, 30]    # Pesos de los elementos
    W = 50                   # Capacidad de la mochila
    n = len(profit)          # Número de elementos

    # Llamada a la función knapSack y mostrar el resultado
    total_value = knapSack(W, weight, profit, n)
    print(f"El valor total de la mochila es: {total_value}")

    # Finalizar la medición y calcular la diferencia
    end_time = time.time()
    end_memory = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
    execution_time = end_time - start_time
    memory_used = end_memory - start_memory

    print(f"El tiempo de ejecución es: {execution_time:.6f} segundos")
    print(f"La memoria utilizada es: {memory_used} bytes")




