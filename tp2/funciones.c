#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define Tam 20

void Inicializar(EPersona persona[])
{
    int i;
    for(i=0;i<Tam;i++)
    {
        strcpy(persona[i].nombre,"\0");
        persona[i].dni=0;
        persona[i].edad=0;
        persona[i].Vacio=0;
    }
}

void Agregar(EPersona persona[])
{
    int i, indice=-1, flag=0, edad;
    long int dni;
    char auxNom[75];
    indice=Libre(persona);

    if(indice!=-1)
    {
        printf("Ingrese DNI: ");
        scanf("%ld",&dni);

        while(dni<1000000||dni>99000000)
        {
            printf("Ingrese un DNI correcto: ");
            scanf("%ld",&dni);
        }

        for(i=0;i<Tam;i++)
        {
            while(dni==persona[i].dni)
            {
                printf("Ingrese DNI nuevamente: ");
                scanf("%ld",&dni);

                while(dni<1000000||dni>99000000)
                {
                    printf("Ingrese un DNI correcto: ");
                    scanf("%ld",&dni);
                }
            }
        }

        if(flag==0)
        {
            persona[indice].dni=dni;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxNom);
            strcpy(persona[indice].nombre, auxNom);
            printf("Ingrese edad: ");
            scanf("%d",&edad);

            while(edad<1 || edad>99)
            {
                printf("Reingrese edad: ");
                scanf("%d",&edad);
            }

            persona[indice].edad=edad;
            persona[indice].Vacio=1;
        }
    }
    else
        printf("Sin espacio!");
}

void Baja(EPersona persona[])
{
    int i, flag=0;
    long int dni;
    char rta='n';

    printf("Ingrese el DNI que quiere dar de baja: ");
    scanf("%ld",&dni);

    flag=Buscar(persona,dni);

    for(i=0;i<Tam;i++)
    {
        if(dni==persona[i].dni)
        {
            printf("NOMBRE: %s\nDNI: %ld\nEDAD: %d",persona[i].nombre, persona[i].dni, persona[i].edad);
            printf("\nDesea borrarlo? <s/n>: ");
            rta=tolower(getch());
            while(rta!='s'&&rta!='n')
            {
                printf("\nResponda con s/n: ");
                rta=tolower(getch());
            }
        }
    }
    if(flag && rta=='s')
    {

        for(i=0;i<Tam;i++)
        {
            if(dni==persona[i].dni)
            {
                persona[i].edad=0;
                persona[i].dni=0;
                strcpy(persona[i].nombre,"\0");
                persona[i].Vacio=0;
                break;
            }
        }
    }

    if(rta=='n')
        printf("\n-");
    if(persona[i].dni!=dni)
        printf("\El dni no existe.\n");


}

int Buscar(EPersona persona[],long int dni)
{
    int i, flag=0;

    for(i=0;i<Tam;i++)
    {
        if(persona[i].dni==dni)
        {
            flag=1;
            break;
        }
    }
    return flag;
}


int Libre(EPersona persona[])
{
    int i, indice=-1;

    for(i=0;i<Tam;i++)
    {
        if(persona[i].Vacio==0)
        {
            indice=i;
            break;
        }

    }
    return indice;
}


void Imprimir(EPersona persona[])
{
    int i, j;
    EPersona auxPer;
    for(i=0;i<Tam-1;i++)
    {
        if(persona[i].Vacio==1)
        {
            for(j=i+1;j<Tam;j++)
            {
                if(strcmp(persona[i].nombre,persona[j].nombre)>0)
                {
                    auxPer=persona[i];
                    persona[i]=persona[j];
                    persona[j]=auxPer;
                }
            }
        }
    }
    for(i=0;i<Tam;i++)
    {
        if(persona[i].Vacio!=0)
            printf("  DNI:%ld\n  NOMBRE:%s\n  EDAD:%d\n",persona[i].dni,persona[i].nombre, persona[i].edad);
    }
}


void Grafico(EPersona persona[])
{
    int i, h18=0, e19y35=0, my35=0, may=0, flag=0;

    for(i=0;i<Tam;i++)
    {
        if(persona[i].Vacio!=0)
        {
            if(persona[i].edad<=18)
                h18++;

            else if(persona[i].edad>18 && persona[i].edad<=35)
                e19y35++;

            else
                my35++;
        }
    }

    if(h18>=e19y35 && h18>=my35)
        may=h18;

    else if(e19y35>=h18 && e19y35>=my35)
        may=e19y35;

    else
        may=my35;

    for(i=may;i>0;i--)
    {
        if(h18>=may)
            printf(" *");

        if(e19y35>=may)
        {
            printf("\t*");
            flag=1;
        }

        if(my35>=may)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag)
                printf("\t*");
        }

        printf("\n");
        may--;
    }
    printf("<18  19-35    >35 ");
}

char Salir(EPersona persona[])
{
    char rta='n';

    printf("\nDesea salir? <s/n>: ");
    rta=tolower(getch());

    while(rta!='s'&&rta!='n')
    {
        printf("\nResponda con s/n: ");
        rta=tolower(getch());
    }

    if(rta=='s')
        rta='n';

    else
        rta='s';

    return rta;
}


