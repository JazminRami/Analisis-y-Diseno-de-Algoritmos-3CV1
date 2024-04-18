#include <stdio.h>

void ordenamiento(int arr[][2], int columnas);

int main() {   
    int W=110, profit=0, Parte_objP,Parte_objW, n=4;
    float operacion;
    printf("PROBLEMA DE LA MOCHILA FRACCIONARIA\n");
    //Arreglo [profit][weght]
    int arr[][2] = {{160, 10}, {60, 50}, {100, 20}, {110, 60}};

    printf("Los articulos tienen el siguiente [beneficio][peso]:\n");
    for(int i = 0; i < n; i++) {
        printf("\t%d- [%d][%d]\n", i+1, arr[i][0], arr[i][1]);
    }
    
    //Ordenamiento dependiedo el beneficio-peso
    printf("\nOrdenando los productos de acuerdo a su [beneficio][peso]:\n");
    ordenamiento(arr, n);
    for(int i = 0; i < n; i++) {
        printf("\t%d- [%d][%d]\n", i+1, arr[i][0], arr[i][1]);
    }
    
    printf("\nEl valor inicial de la mochila es de = %d y su beneficio = %d\n", W, profit);
    printf("\nLlenando la mochila con su peso total tenemos:\n");
    printf("Los articulos que se introduciran [beneficio][peso]:\n");
    for (int i = 0; i < n; i++) {
        if (arr[i][1] <= W) {
            printf("\t%d- [%d][%d]\n", i+1, arr[i][0], arr[i][1]);
            profit += arr[i][0]; 
            W -= arr[i][1];
        } else
        if(arr[i][1]>W){
            operacion = (float)W / arr[i][1];
            Parte_objP=(operacion*arr[i][0]);
            Parte_objW=(operacion*arr[i][1]);
            printf("\t%d- [%d][%d]\n", i+1,Parte_objP , Parte_objW);
            profit = profit + (operacion*arr[i][0]); 
            W = W - (operacion*arr[i][1]);
        }
        
    }
    
    printf("Peso= %d\n", W);
        printf("Beneficio = %d\n", profit);
}

void ordenamiento(int arr[][2], int columnas) {
     int i, j;
    for (i = 0; i < columnas - 1; i++) {
        for (j = 0; j < columnas - i - 1; j++) {
            // Calcular la relación beneficio/peso para cada elemento
            float ratio1 = (float)arr[j][0] / arr[j][1];
            float ratio2 = (float)arr[j + 1][0] / arr[j + 1][1];
            // Si el ratio del elemento actual es menor que el del siguiente, intercambiar
            if (ratio1 < ratio2) {
                int temp0 = arr[j][0];
                int temp1 = arr[j][1];
                arr[j][0] = arr[j + 1][0];
                arr[j][1] = arr[j + 1][1];
                arr[j + 1][0] = temp0;
                arr[j + 1][1] = temp1;
            }
        }
    }   
}

