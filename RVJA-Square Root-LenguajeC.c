#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int SquareRoot(int x);

int main()
{
    int num;
    srand(time(NULL));
    num= rand() % 100;
    
    printf("El numero a obtener la raiz cuadrada es '%d' \n",num);
    printf("El resultado es: %d", SquareRoot(num));
    
    return 0;
}

int SquareRoot(int x){
    //Caso base
    if(x==1 || x==0){
        return x;
    }
    
    int l=0, r=x/2, ans=0;
    
    // Bucle de búsqueda binaria
    while (l <= r) {
        int mid = (l+r)/2;      //Punto medio
        int square = mid * mid;     //Cuadrado del punto medio
        
        if (square == x) {
            return mid;
        }else
        if (square < x) {     //Busca en la segunda mitad
            l = mid + 1;
            ans = mid;
        }
        else {      //Primera mitad
            r = mid - 1;
        }
    }
    
    printf("La raiz cuadrada de %d es una aproximacion.\n", x);
    return ans;
}



