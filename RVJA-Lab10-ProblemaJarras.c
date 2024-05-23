#include <stdio.h>
#include <stdbool.h>

// Función para llenar una jarra
void llenarJarra(int jarra[]) {
    jarra[1] = jarra[0];
}

// Función para vaciar una jarra
void vaciarJarra(int jarra[]) {
    jarra[1] = 0;
}

// Función para verter agua de una jarra a otra
void verterAgua(int jarraDesde[], int jarraHasta[]) {
    int cantidadVertida = jarraHasta[0] - jarraHasta[1];
    if (jarraDesde[1] < cantidadVertida) {
        cantidadVertida = jarraDesde[1];
    }
    jarraDesde[1] -= cantidadVertida;
    jarraHasta[1] += cantidadVertida;
}

int main() {
    int jarra5l[2] = {5, 0}; // {capacidad, cantidad_actual}
    int jarra3l[2] = {3, 0}; // {capacidad, cantidad_actual}

    printf("Estado inicial: Jarra de 5L = %d, Jarra de 3L = %d\n\n", jarra5l[1], jarra3l[1]);

    // Llena la jarra de 5L
    llenarJarra(jarra5l);
    printf("Llenar jarra de 5L: \n\t->Jarra de 5L = %d, Jarra de 3L = %d\n\n", jarra5l[1], jarra3l[1]);

    // Vierte agua de la jarra de 5L a la jarra de 3L
    verterAgua(jarra5l, jarra3l);
    printf("Verter jarra de 5L a jarra de 3L: \n\t->Jarra de 5L = %d, Jarra de 3L = %d\n\n", jarra5l[1], jarra3l[1]);

    // Vacía la jarra de 3L
    vaciarJarra(jarra3l);
    printf("Vaciar jarra de 3L: \n\t->Jarra de 5L = %d, Jarra de 3L = %d\n\n", jarra5l[1], jarra3l[1]);

    // Vierte agua de la jarra de 5L a la jarra de 3L
    verterAgua(jarra5l, jarra3l);
    printf("Verter jarra de 5L a jarra de 3L: \n\t->Jarra de 5L = %d, Jarra de 3L = %d\n\n", jarra5l[1], jarra3l[1]);

    // Llena la jarra de 5L nuevamente
    llenarJarra(jarra5l);
    printf("Llenar jarra de 5L: \n\t->Jarra de 5L = %d, Jarra de 3L = %d\n\n", jarra5l[1], jarra3l[1]);

    // Vierte agua de la jarra de 5L a la jarra de 3L hasta llenar la jarra de 3L
    verterAgua(jarra5l, jarra3l);
    printf("Verter jarra de 5L a jarra de 3L: \n\t->Jarra de 5L = %d, Jarra de 3L = %d\n\n", jarra5l[1], jarra3l[1]);

    // Ahora la jarra de 5L tiene 4 litros
    printf("Resultado final: Jarra de 5L = %d, Jarra de 3L = %d\n\n", jarra5l[1], jarra3l[1]);

    return 0;
}




