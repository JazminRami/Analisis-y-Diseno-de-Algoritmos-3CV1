#include <stdio.h>

int main() {   
    int suma, n=4, k=2;
    printf("PROBLEMA DE GESTOR DE MEMORIA\n");
    //Arreglo [profit][weght]
    int procesos[][2] = {{300, 0}, {25, 0}, {125, 0}, {50, 0}};
    int memoria[]= {150, 350};

    printf("Los procesos que se tienen son  [num proceso][tamaño KB]:\n");
    for(int i = 0; i < n; i++) {
        printf("\t%d - [%d]\n",i+1, procesos[i][0]);
    }
    
    printf("Los bloques de memoria tienen el siguiente orden y tamaño:\n");
    for(int i = 0; i < k; i++) {
        printf("\t%d - [%d]\n", i+1, memoria[i]);
    }
    
    printf("\nRealizando una estrategia voraz (Enfoque el primero)\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
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
    for(int i = 0; i < k; i++) {
        printf("\t%d - [%d]\n", i+1, memoria[i]);
        suma += memoria[i];
    } 
    printf("Y queda %d de memoria libre\n", suma);
}



