#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar rutas
typedef struct {
    int ruta[10][10]; // Se asume un tamaño máximo de 10x10 para simplificar
    int longitud;
} Ruta;

Ruta caminos[100]; // Array de estructuras Ruta para almacenar múltiples rutas
int conteo_rutas = 0;

void almacenarRuta(int sol[10][10], int m, int n) {
    memcpy(caminos[conteo_rutas].ruta, sol, sizeof(int) * 10 * 10);
    caminos[conteo_rutas].longitud = m * n;
    conteo_rutas++;
}

void imprimirRutas(int m, int n) {
    for (int k = 0; k < conteo_rutas; k++) {
        printf("Ruta %d:\n", k + 1);
        printf("\t - - - - \n");
        for (int i = 0; i < m; i++) {
            printf("\t| ");
            for (int j = 0; j < n; j++) {
                if (caminos[k].ruta[i][j] == 2) {
                    printf("X ");
                } else {
                    printf("%d ", caminos[k].ruta[i][j]);
                }
            }
            printf("| \n");
        }
        printf("\t - - - - \n\n");
    }
}


void encontrarRutas(int laberinto[10][10], int m, int n, int x, int y, int sol[10][10]) {
    if (x == m - 1 && y == n - 1 && laberinto[x][y] == 0) {
        sol[x][y] = 2;
        almacenarRuta(sol, m, n);
        sol[x][y] = 0;  // Desmarcar después de almacenar la ruta
        return;
    }
    
    if (x >= 0 && x < m && y >= 0 && y < n && laberinto[x][y] == 0) {
        sol[x][y] = 2;
        
        encontrarRutas(laberinto, m, n, x + 1, y, sol);
        encontrarRutas(laberinto, m, n, x, y + 1, sol);
        
        sol[x][y] = 0;  // Desmarcar el camino
    }
}

int main() {
    int m = 3, n = 3;
    int laberinto[10][10] = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    
    int sol[10][10] = {0};
    
    // Imprimir el laberinto original
    printf("Laberinto:\n");
    printf("\t - - - - \n");
    for (int i = 0; i < m; i++) {
        printf("\t| ");
        for (int j = 0; j < n; j++) {
            if (laberinto[i][j] == 2) {
                printf("X ");
            } else {
                printf("%d ", laberinto[i][j]);
            }
        }
        printf("| \n");
    }
    printf("\t - - - - \n");
    
    // Encontrar y almacenar todas las rutas
    encontrarRutas(laberinto, m, n, 0, 0, sol);
    
    // Imprimir las rutas encontradas en texto y en el laberinto
    printf("Las rutas encontradas son: %d\n\n", conteo_rutas);
    imprimirRutas(m, n);
    
    return 0;
}
