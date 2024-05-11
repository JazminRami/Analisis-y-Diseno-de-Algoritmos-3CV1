#include <stdio.h>

int count(int saltos[], int n, int peldanos, char* combinacion, int* contador);

int main() {
    int saltos[] = {1, 2, 3,4};
    int n = sizeof(saltos) / sizeof(saltos[0]);
    int peldanos = 10;
    char combinacion[100] = ""; // Inicializar combinación vacía
    int contador = 0; // Inicializar contador de combinaciones
    printf("RECURSIVIDAD PLANA Y MEMOIZACION\n\n");
    printf("Un niño está subiendo una escalera que tiene n peldaños, el cual puede brincar %d, %d o %d escalones al mismo tiempo.\n",saltos[0],saltos[1],saltos[2]);          
    printf("Cuenta de cuántas maneras posibles se puede subir la escalera.\n\n");
    printf("Las posibles formas de hacerlo son:\n");

    printf("\nEl total de formas posibles son: %d", count(saltos, n, peldanos, combinacion, &contador));
    return 0;
}

int count(int saltos[], int n, int peldanos, char* combinacion, int* contador) {
    if (peldanos == 0) {
        printf("\t%d : %s\n", ++(*contador), combinacion);
        return 1;
    }

    if (peldanos < 0 || n <= 0)
        return 0;

    char new_combinacion[100]; // Tamaño suficiente para contener la cadena
    sprintf(new_combinacion, "%s%d ", combinacion, saltos[n - 1]);

    return count(saltos, n - 1, peldanos, combinacion, contador) + count(saltos, n, peldanos - saltos[n - 1], new_combinacion, contador);
}


