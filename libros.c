#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autores.h"
#include "libros.h"

void showLibro(eLibro list,eAutores listAutor[],int lenAutor)
{
    char apellido[31];
    char nombre[31];


    if(!obtenerAutor(listAutor,5,list.codigoDeAutor.codigoDeAutor,apellido,nombre))
    {
        strcpy(apellido,"Sin definir");
        strcpy(nombre,"Sin definir");
    }

    printf("\n%d\t%s\t%s\t%s\n",list.codigoDelLibro,list.titulo,apellido,nombre);

}

void showLibros(eLibro list[],int len,eAutores listAutor[],int lenAutor)
{
    printf("\n\nCODIGO\tTITULO          APELLIDO    NOMBRE\n");
    printf("      \t                DEL AUTOR   DEL AUTOR\n\n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            showLibro(list[i],listAutor,lenAutor);
        }
    }
}


void hardcodeoLibros(eLibro* list)
{
    eLibro nuevosLibros[] =
    {
        {1,"Volar       ",{1,"Neruda  ","Pablo",0},0},
        {2,"Saltar      ",{4,"Krupo   ","Matias",0},0},
        {3,"Biografia   ",{3,"Lombardo","Mauro",0},0},
        {4,"Programacion",{1,"Neruda  ","Pablo",0},0},
        {5,"Trap        ",{2,"Ysy     ","Alejo",0},0},

    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = nuevosLibros[i];
    }
}

int findLibroById(eLibro list[], int len, int id)
{

    for(int i=0; i < len; i++)
    {

        if( list[i].codigoDelLibro == id)
        {
            return i;
            break;
        }
    }
    return -1;

}

int sortLibros(eLibro list[], int len)
{
    eLibro auxLibro;
    int ret;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len -1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[i].titulo,list[j].titulo) > 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    auxLibro = list[i];
                    list[i] = list[j];
                    list[j] = auxLibro ;
                }

            }

            ret = 1;

        }
    }
    else
    {
        ret = -1;
    }


    return ret;

}

