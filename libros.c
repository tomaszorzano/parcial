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

