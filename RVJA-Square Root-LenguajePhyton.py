import random

def square_root(x):
    if x == 1 or x == 0:
        return x
    
    l, r = 0, x // 2
    ans = 0

    # Búsqueda binaria
    while l <= r:
        mid = (l + r) // 2  # Punto medio
        square = mid * mid  # Cuadrado del punto medio
        
        if square == x:  # Devuelve el punto medio si el cuadrado es igual a x
            return mid
        elif square < x:  # Busca en la segunda mitad
            ans = mid
            l = mid + 1
        else:  # Primera mitad
            r = mid - 1
        
    print(f"La raiz cuadrada de {x} es una aproximacion.")
    return ans

def main():
    num = random.randint(0, 99)
    print(f"El numero para calcular la raiz cuadrada es '{num}'")
    print(f"El resultado es: {square_root(num)}")

if __name__ == "__main__":
    main()



