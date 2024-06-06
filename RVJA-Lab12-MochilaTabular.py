import time
import resource

def knapSack(W, wt, val, n):
    K = [[0 for x in range(W + 1)] for x in range(n + 1)]
    
    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif wt[i-1] <= w:
                K[i][w] = max(val[i-1] + K[i-1][w - wt[i-1]], K[i-1][w])
            else:
                K[i][w] = K[i-1][w]
    
    return K[n][W]

if __name__ == '__main__':
    
    # Iniciar la medición del tiempo y memoria
    start_time = time.time()
    start_memory = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
    
    profit = [60, 100, 120]
    weight = [10, 20, 30]
    W = 50
    n = len(profit)
    
    total_value = knapSack(W, weight, profit, n)
    print(f"El valor total de la mochila es: {total_value}")
    
    # Finalizar la medición y calcular la diferencia
    end_time = time.time()
    end_memory = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
    execution_time = end_time - start_time
    memory_used = end_memory - start_memory
    
    print(f"El tiempo de ejecución es: {execution_time:.6f} segundos")
    print(f"La memoria utilizada es: {memory_used} bytes")
    
    


