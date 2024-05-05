# Bibliotecas
import heapq
import os

# Definición de la estructura del nodo del árbol de Huffman
class NodoHuffman:
    def __init__(self, caracter, frecuencia):
        self.caracter = caracter
        self.frecuencia = frecuencia
        self.izquierda = None
        self.derecha = None

    # Compara nodos
    def __lt__(self, otro): 
        return self.frecuencia < otro.frecuencia

# Realiza el conteo de las frecuencias
def contar_frecuencias(texto):
    frecuencias = {}
    for caracter in texto:
        if caracter.isalpha() or caracter.isspace():
            if caracter in frecuencias:
                frecuencias[caracter] += 1
            else:
                frecuencias[caracter] = 1
    return frecuencias

# Función para construir el árbol de Huffman a partir de un conjunto de nodos
def construir_arbol_huffman(frecuencias):
    heap = [NodoHuffman(caracter, frecuencia) for caracter, frecuencia in frecuencias.items()]
    heapq.heapify(heap)
    while len(heap) > 1:
        izquierda = heapq.heappop(heap)
        derecha = heapq.heappop(heap)
        padre = NodoHuffman(None, izquierda.frecuencia + derecha.frecuencia)
        padre.izquierda = izquierda
        padre.derecha = derecha
        heapq.heappush(heap, padre)
    return heap[0]

# Función que genera los códigos de Huffman recursivamente
def generar_codigos(raiz, codigo_actual, codigos):
    if raiz.caracter is not None:
        codigos[raiz.caracter] = codigo_actual
        return
    generar_codigos(raiz.izquierda, codigo_actual + '0', codigos)
    generar_codigos(raiz.derecha, codigo_actual + '1', codigos)

# Función que codifica el texto ingresado
def codificar_texto(texto, codigos):
    texto_codificado = ''
    for caracter in texto:
        if caracter == ' ':
            texto_codificado += ' '  # Agregar espacio entre palabras
        else:
            texto_codificado += codigos[caracter]
    return texto_codificado

# Función que decodifica el código creado
def decodificar_texto(texto_codificado, raiz):
    texto_decodificado = ''
    nodo_actual = raiz
    for bit in texto_codificado:
        if bit == ' ':
            texto_decodificado += ' '  # Agregar espacio entre palabras
            continue
        if bit == '0':
            nodo_actual = nodo_actual.izquierda
        elif bit == '1':
            nodo_actual = nodo_actual.derecha

        if nodo_actual.caracter is not None:
            texto_decodificado += nodo_actual.caracter
            nodo_actual = raiz

    return texto_decodificado

# Función que guarda el contenido proporcionado
def guardar_texto(nombre_archivo, contenido):
    with open(nombre_archivo, 'w') as archivo:
        archivo.write(contenido)

def main():
    
    # Solicitar texto válido
    print("\tCODIFICACION DE HUFFMAN\n")
    while True:
        texto = input("Ingresa el texto a codificar\n*No se permiten caracteres especiales\n\n\t-> ")
        if texto.isalpha() or ' ' in texto:
            break
        else:
            # Limpiar pantalla
            os.system('cls' if os.name == 'nt' else 'clear')
            print("*Texto inválido. No se permiten caracteres especiales.\n")
            
    # Convertir a mayúsculas
    texto = texto.upper()

    # Obtener frecuencias de caracteres
    frecuencias = contar_frecuencias(texto)

    # Construir árbol de Huffman
    raiz = construir_arbol_huffman(frecuencias)

    # Generar códigos Huffman
    codigos = {}
    generar_codigos(raiz, '', codigos)

    # Codificar texto
    texto_codificado = codificar_texto(texto, codigos)

    # Decodificar texto codificado
    texto_decodificado = decodificar_texto(texto_codificado, raiz)

    # Guardar el texto original en un archivo de texto
    contenido_texto_original = f'Texto original: \n{texto}\n\nFrecuencia de letras:\n'
    for caracter, frecuencia in sorted(frecuencias.items()):
        contenido_texto_original += f"{caracter}: {frecuencia}\n"
    guardar_texto('texto_original.txt', contenido_texto_original)

    # Guardar codificación y texto codificado en otro archivo de texto
    with open('codificacion.txt', 'w') as archivo:
        archivo.write('Letras con su codigo:\n')
        for caracter, codigo in codigos.items():
            archivo.write(f'{caracter}: {codigo}\n')
        archivo.write('\nTexto codificado:\n')
        archivo.write(texto_codificado)

    # Guardar decodificación y texto decodificado en otro archivo de texto
    with open('decodificacion.txt', 'w') as archivo:
        archivo.write('El texto codificado es: \n')
        archivo.write(texto_codificado)
        archivo.write('\n\nEl texto decodificado es:\n')
        archivo.write(texto_decodificado)

    print("\n\nSe ha generado la codificacion y decodificacion de Huffman, los resultados han sido guardados en archivos de texto (.txt).")

if __name__ == "__main__":
    main()

