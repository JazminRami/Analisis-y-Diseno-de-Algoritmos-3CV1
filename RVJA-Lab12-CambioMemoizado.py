import time
import resource

def count(coins, sum, n, dp) :
    # Base Case
    if (sum == 0):
        dp[n][sum] = 1
        return dp[n][sum]
    # If number of coins is 8 or sum is less than @ then there is no way to make the sum.
    if (n == 0 or sum < 0):
        return 0
    # If the subproblem is previously calculated then simply return the result
    if (dp[n][sum] != -1):
        return dp[n][sum]
    # Two options for the current coin
    dp[n][sum] = count(coins, sum - coins[n - 1], n, dp) + \
        count(coins, sum, n - 1, dp)
    return dp[n][sum]

# Driver code
if __name__ == '__main__':
    
    # Iniciar la medición del tiempo y memoria
    start_time = time.time()
    start_memory = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss

    tc = 1
    while (tc != 0):
        n = 3
        sum = 5
        coins = [1, 2, 3]
        dp = [[-1 for i in range(sum+1)] for j in range(n+1)]
        res = count(coins, sum, n, dp)
        print(f"Para la cantidad de {sum}, se puede dar cambio de {res} maneras distintas")
        tc -= 1
        
    # Finalizar la medición y calcular la diferencia
    end_time = time.time()
    end_memory = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
    execution_time = end_time - start_time
    memory_used = end_memory - start_memory

    print(f"El tiempo de ejecución es: {execution_time:.6f} segundos")
    print(f"La memoria utilizada es: {memory_used} bytes")






