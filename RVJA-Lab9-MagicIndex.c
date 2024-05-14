#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenamiento(int tam, int arr[]);

int main() {
    
    int n, encontrado=0;
    srand(time(NULL));
    
    n = rand() % 20;
    
    //Arreglo de n numeros aleatorios.
    int A[n];

    //Ciclo que asigna numeros aleatorios a las n posiciones.
    printf("El arreglo A de %d posiciones tiene como numeros aleatorios:\n\n",n);
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 41 - 20;
        printf("\t %d -> %d\n", i, A[i]);
    }

    //Funcion que ordena los numeros de menor a mayor.
    ordenamiento(n, A);
    
    //Imprime el arreglo ordenado
    printf("\nOrdenando los numeros del arreglo:\n");
    for (int i = 0; i < n; i++) {
        printf("\t%d -> %d\n", i, A[i]); 
    }
    
    //Verifica si se tiene un magic index
    for (int i = 0; i < n; i++) {
        if(A[i]==i){
            printf("\n-> Se encontro un MAGIC INDEX --> %d - %d\n", i, A[i]); 
            encontrado=1;
        }
    }
    if(encontrado==0){
        printf("\n-> No se encontro ningun MAGIC INDEX"); 

    }

    return 0;
}

void ordenamiento(int tam, int arr[]){
    int aux;
    for(int i = 0; i < tam - 1; i++) { 
        for(int j = 0; j < tam - i - 1; j++) {
            if(arr[j] > arr[j+1]){
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
}

