#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "autores.h"
#include "Funciones.h"

void harcodeoAutores(eAutores* list)
{

    eAutores x[]={
    {001,"Maximiliano","Meza",0},
    {002,"Nicolas","Figal",0},
    {003,"Alan","Franco",0},
    {004,"Martin","Benitez",0},
    {005,"Martin","Campaña",0},
    };
    for(int i = 0; i< 5;i++)
    {
        list[i] = x[i];
    }
};

void viewAutor(eAutores  aAutores)
{
    printf(" \nCodigo:%d- Nombre:%s- Apellido:%s\n ",aAutores.codigo,aAutores.nombre,aAutores.apellido);
};

void viewAutores(eAutores list[], int len)
{

    system("cls");

    for(int i=0; i < len; i++)
    {

        if( list[i].isEmpty == 0)
        {
            viewAutor(list[i]);
        }
    }

};

int funcion_opcionesAutores()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES AUTORES ******* \n\n");
    printf(" 1- LISTAR AUTORES \n");
    printf(" 2- SALIR \n");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-2 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 2\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
};




