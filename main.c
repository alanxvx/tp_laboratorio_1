#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{

    int num, fact1, fact2, resulFac;
    float numero1=0;
    float numero2=0;
    float resultado;
    int continuar=1;

    while(continuar==1)
    {
        system("cls");

        printf("\n         - Calculadora - \n\n");

        num=menu(numero1, numero2);

        if(!(num>=1 && num<=9))
            {
                printf("Error. Ingrese el numero de una opcion: \n");
                scanf("%d", &num);

            }

        switch(num)
        {

            case 1:
            printf("Ingrese un numero: \n");
            scanf("%f", &numero1);
            continuar=1;
            break;

            case 2:
            printf("Ingrese otro numero: \n");
            scanf("%f", &numero2);
            continuar=1;
            break;

            case 3:
            resultado=sumar(numero1, numero2);
            printf("La suma de %.2f + %.2f es: %.2f \n\n", numero1, numero2, resultado);
            continuar=1;
            getch();
            break;

            case 4:
            resultado=restar(numero1, numero2);
            printf("La resta de %.2f - %.2f es: %.2f \n\n", numero1, numero2, resultado);
            continuar=1;
            getch();
            break;

            case 5:
            if(numero2==0)
            {
               printf("Error. No se puede dividir por cero.");

            }
            else
            {
                resultado=dividir(numero1, numero2);
                printf("La division de %.2f / %.2f es: %.2f \n\n", numero1, numero2, resultado);
            }

            getch();
            continuar=1;

            break;

            case 6:
            resultado=multiplicar(numero1, numero2);
            printf("La multiplicacion de %.2f * %.2f es: %.2f \n\n", numero1, numero2, resultado);
            continuar=1;
            getch();
            break;

            case 7:
            fact1 = (int)numero1;
            fact2 = (int)numero2;

            if(fact1<=0)
            {
               printf("Error. Para calcular el factorial debe ingresar un numero positivo.\n");
            }
            else
            {   resulFac=factorial(fact1);
                printf("El factorial de %d es: %d \n", fact1, resulFac);
            }
            if(fact2<=0)
            {
               printf("Error. Para calcular el factorial debe ingresar un numero positivo.\n");
            }
            else
            {   resulFac=factorial(fact2);
                printf("El factorial de %d es: %d \n\n", fact2, resulFac);
            }

                continuar=1;
                getch();
            break;

            case 8:
            resultado=sumar(numero1, numero2);
            printf("La suma de %.2f + %.2f es: %.2f \n", numero1, numero2, resultado);

            resultado=restar(numero1, numero2);
            printf("La resta de %.2f - %.2f es: %.2f \n", numero1, numero2, resultado);

            if(numero2==0)
            {
                printf("Error. No se puede dividir por cero.\n");
            }
            else
            {   resultado=dividir(numero1, numero2);
                printf("La division de %.2f / %.2f es: %.2f \n", numero1, numero2, resultado);
            }
            resultado=multiplicar(numero1, numero2);
            printf("La multiplicacion de %.2f * %.2f es: %.2f \n", numero1, numero2, resultado);

            fact1 = (int)numero1;
            fact2 = (int)numero2;

            if(fact1<=0)
            {
               printf("Error. Para calcular el factorial  ingrese un numero positivo.\n");
            }
            else
            {   resulFac=factorial(fact1);
                printf("El factorial de %d es: %d \n", fact1, resulFac);
            }
            if(fact2<=0)
            {
               printf("Error. Para calcular el factorial ingrese un numero positivo.\n");
            }
            else
            {   resulFac=factorial(fact2);
                printf("El factorial de %d es: %d \n\n", fact2, resulFac);
            }
            continuar=1;
            getch();
            break;

            case 9:
            continuar=0;
            break;

        }


}


    return 0;
}
