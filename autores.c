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

