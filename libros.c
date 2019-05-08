#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
#include "autores.h"
#include "libros.h"

void harcodeoLibros(eLibros* list)
{

    eLibros x[]=
    {
        {001,"Copa Sudamericana 2017",005,0},
        {002,"Copa Sudamericana 2010",003,0},
        {003,"Suruga Bank 2018",002,0},
        {004,"Copa Libertadores 2018",002,0},
        {005,"Recopa Sudamericana 2018",001,0},
    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = x[i];
    }
};

void viewLibro(eLibros aLibros)
{
    printf(" \nID:%d - Nombre:%s - Codigo Autor:%d\n  ",aLibros.id,aLibros.titulo,aLibros.codigoA);
};

void viewlibros(eLibros list[], int len)
{

    system("cls");

    for(int i=0; i < len; i++)
    {

        if( list[i].isEmpty == 0)
        {
            viewLibro(list[i]);
        }
    }

};

int funcion_opcionesLibros()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES LIBROS ******* \n\n");
    printf(" 1- LISTAR LIBROS \n");
    printf(" 2- ORDENAR LIBROS POR TITULO (DESCENDENTE) \n");
    printf(" 3- SALIR \n");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-3 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 3\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
};
int findLibro(eLibros list[],int len, int file)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {

        if( list[i].id == file && list[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;

};
int findLibroXCodigo(eLibros list[],int len, int file)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {

        if( list[i].id == file && list[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;

};

int sortLibros(eLibros list[], int len)
{
    eLibros auxLibros;

    int ret;


    if(list != NULL && len > 0)
    {

        for(int i = 0; i < len-1; i++)
        {
            for(int j = i+1; j < len; j++)
            {
               if(strcmp(list[j].titulo, list[i].titulo) > 0 && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                {
                    auxLibros = list[i];
                    list[i] = list[j];
                    list[j] = auxLibros;
                }

            }
        }
    }


    else
    {
        ret = -1;
    }


    return ret;

};

