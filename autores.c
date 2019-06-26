#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autores.h"


void hardcodeoAutores(eAutores* list)
{
    eAutores nuevosAutores[] =
    {
        {1,"Neruda  ","Pablo",0},
        {2,"Ysy     ","Alejo",0},
        {3,"Lombardo","Mauro",0},
        {4,"Krupo   ","Matias",0},
        {5,"Figo    ","Lorena",0},
    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = nuevosAutores[i];
    }
}


void showAutor(eAutores list)
{
    printf("\n%d   \t%s\t%s\n",list.codigoDeAutor,list.apellido,list.nombre);

}

void showAutores(eAutores list[],int len)
{
    printf("\n\nCODIGO\tAPELLIDO        NOMBRE\n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            showAutor(list[i]);
        }
    }

}

int obtenerAutor(eAutores list[], int len, int idAutor, char apellido[],char nombre[])
{

    int ret = 0;

    for(int i=0; i < len; i++)    {

        if(idAutor == list[i].codigoDeAutor)
        {

            strcpy(apellido, list[i].apellido);
            strcpy(nombre, list[i].nombre);
            ret = 1;
            break;
        }
    }

    return ret;
}


int sortAutores(eAutores list[], int len)
{
    eAutores auxAutor;
    int ret;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len -1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[i].apellido,list[j].apellido) > 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    auxAutor = list[i];
                    list[i] = list[j];
                    list[j] = auxAutor ;
                }
                else if(strcmp(list[i].apellido,list[j].apellido) == 0 && strcmp(list[i].nombre,list[j].nombre)>0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    auxAutor = list[i];
                    list[i] = list[j];
                    list[j] = auxAutor ;
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
