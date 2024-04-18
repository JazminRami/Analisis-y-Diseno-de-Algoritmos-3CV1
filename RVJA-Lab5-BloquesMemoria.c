#include <stdio.h>

int main() {   
    int suma, n=4;
    printf("PROBLEMA DE GESTOR DE MEMORIA\n");
    //Arreglo [profit][weght]
    int procesos[][2] = {{212, 0}, {417, 0}, {112, 0}, {426, 0}};
    int memoria[5]= {100, 500, 200, 300, 600};

    printf("Los procesos que se tienen son  [num proceso][tamaño KB]:\n");
    for(int i = 0; i < n; i++) {
        printf("\t%d - [%d]\n",i+1, procesos[i][0]);
    }
    
    printf("Los bloques de memoria tienen el siguiente orden y tamaño:\n");
    for(int i = 0; i < 5; i++) {
        printf("\t%d - [%d]\n", i+1, memoria[i]);
    }
    
    printf("\nRealizando una estrategia voraz\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            if (procesos[i][0] <= memoria[j]) {
                memoria[j] -= procesos[i][0];
                procesos[i][1] = j + 1; // Almacena el bloque asignado
                break; 
            }
        }
    }
    
    printf("Los procesos con el numero de memoria asignado [num proceso][tamaño KB][bloque asignado]:\n");
    for(int i = 0; i < n; i++) {
        printf("\t%d - [%d] [%d]\n", i + 1, procesos[i][0], procesos[i][1]);
        if(procesos[i][1]==0){
            printf("\t*El proceso %d quedo sin asignar a un espacio de memoria\n",i+1);
        }
    }
    printf("\nY los bloques de memoria terminarian con el sigueinte tamaño:\n");
    for(int i = 0; i < 5; i++) {
        printf("\t%d - [%d]\n", i+1, memoria[i]);
        suma += memoria[i];
    } 
    printf("Y queda %d de memoria libre\n", suma);
}




