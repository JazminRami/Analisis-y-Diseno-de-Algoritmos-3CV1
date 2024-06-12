import random
import time

# Definimos el sistema de ecuaciones
def check_solution(x, y, z, t):
    eq1 = (x + 2*y - z + 3*t) == -8
    eq2 = (2*x + 2*z - t) == 13
    eq3 = (-x + y + z - t) == 8
    eq4 = (3*x + 3*y - z + 2*t) == -1
    return eq1 and eq2 and eq3 and eq4

# Inicializamos las variables
found_solution = False
iterations = 10_000_000

# Medimos el tiempo de inicio
start_time = time.time()

# Ciclo para encontrar la mejor solución
for _ in range(iterations):
    # Generamos valores aleatorios para x, y, z, t
    x = random.randint(-5, 5)
    y = random.randint(-5, 5)
    z = random.randint(-5, 5)
    t = random.randint(-5, 5)
    
    # Verificamos si estos valores satisfacen el sistema de ecuaciones
    if check_solution(x, y, z, t):
        best_solution = [x, y, z, t]
        found_solution = True
        break

# Medimos el tiempo de finalización
end_time = time.time()

# Calculamos el tiempo de ejecución
execution_time = end_time - start_time

# Verificamos si se encontró una solución
if found_solution:
    print(f"Solución exacta encontrada: x={best_solution[0]}, y={best_solution[1]}, z={best_solution[2]}, t={best_solution[3]}")
else:
    print("No se encontró una solución exacta en 10 millones de iteraciones.")

# Imprimimos el tiempo de ejecución
print(f"Tiempo de ejecución: {execution_time:.3f} segundos")

