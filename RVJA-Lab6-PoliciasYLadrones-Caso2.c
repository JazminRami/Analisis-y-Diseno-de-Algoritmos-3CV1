#include <stdio.h>
#include <stdlib.h>

int policeThief(char arr[], int n, int k);

int main() {
    char arr1[] = {'T', 'P', 'P', 'T', 'P','P','T','T','P','T'};
    int k = 2;
    int n = sizeof(arr1) / sizeof(arr1[0]);
    printf("POLICIAS Y LADRONES\nEl arreglo es:\n\n\t");
    for(int i=0; i<n; i++){
        printf("%c  ",arr1[i]);
    }
    printf("\n\t");
    for(int i=0; i<n; i++){
        printf("%d  ",i+1);
    }
    printf("\n\nCon K= %d tenemos lo siguiente:\n",k);
    printf("\n\nTotal de ladrones capturados: %d\n",policeThief(arr1, n, k));

    return 0;
}

int policeThief(char arr[], int n, int k) {
    int totalCapturados = 0; // Total de ladrones capturados

    for (int i = 0; i < n; i++) {
        if (arr[i] == 'P') { // Si el elemento actual es un policía
            for (int j = i - k; j <= i + k; j++) {
                if (j >= 0 && j < n && arr[j] == 'T') {
                    printf("-Policia en la posicion %d atrapo al ladron de la posicion %d\n", i + 1, j + 1);
                    totalCapturados++; // Incrementamos el contador de ladrones capturados
                    arr[j] = 'C'; // Marcamos al ladrón como capturado 
                    break; // Salimos del bucle 
                }
            }
        }
    }
    
    return totalCapturados;
}


