#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int Vacio;
    long int dni;

}EPersona;

void Inicializar(EPersona persona[]);
void Agregar(EPersona persona[]);
void Baja(EPersona lista[]);
int Buscar(EPersona lista[],long int dni);
void Imprimir(EPersona lista[]);
int Libre(EPersona lista[]);
void Grafico(EPersona lista[]);
char Salir(EPersona lista[]);
