import random
import time

# Función para generar un punto aleatorio dentro de un círculo unitario
def generar_punto_en_circulo():
    while True:
        # Generar coordenadas x y y aleatorias entre -1 y 1
        coordenada_x = random.uniform(-1, 1)
        coordenada_y = random.uniform(-1, 1)
        
        # Verificar si el punto (x, y) está dentro del círculo unitario
        if coordenada_x**2 + coordenada_y**2 <= 1:
            return (coordenada_x, coordenada_y)

# Medimos el tiempo de inicio
start_time = time.time()

# Generar un punto aleatorio dentro del círculo
punto = generar_punto_en_circulo()

# Medimos el tiempo de finalización
end_time = time.time()
execution_time = end_time - start_time

# Mostrar el punto generado
print(f"Punto generado dentro del círculo unitario: ({punto[0]:.5f}, {punto[1]:.5f})")

# Imprimimos el tiempo de ejecución
print(f"Tiempo de ejecución: {execution_time:.6f} segundos")

