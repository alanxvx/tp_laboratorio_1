#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int menu( float num1, float num2)
{
    int opcion;

    printf("1. Ingresar Primer operando (A= %.2f)\n", num1);
    printf("2. Ingresar Segundo operando (B= %.2f)\n", num2);
    printf("3. Calcular la Suma (A+B)\n");
    printf("4. Calcular la Resta (A-B)\n");
    printf("5. Calcular la Division (A/B)\n");
    printf("6. Calcular la Multiplicacion (A*B)\n");
    printf("7. Calcular el Factorial (A!)(B!)\n");
    printf("8. Calcular Todas las operaciones\n");
    printf("9. Salir \n\n");
    printf("Ingrese el numero de una opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

float sumar(float operando1, float operando2)
{
    float resultado;
    resultado = operando1 + operando2;
    return resultado;
}

float restar(float operando1, float operando2)
{
    float resultado;
    resultado = operando1 - operando2;
    return resultado;
}

float multiplicar(float operando1, float operando2)
{
    float resultado;
    resultado = operando1 * operando2;
    return resultado;
}

float dividir(float operando1, float operando2)
{
    float resultado;
    resultado = operando1 / operando2;
    return resultado;
}

float factorial(float n)
{
   float resp;
   if(n==1)
   return 1;
   resp=n* factorial(n-1);
   return (resp);
}

