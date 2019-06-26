#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "fecha.h"
#include "autores.h"
#include "libros.h"
#include "socios.h"
#include "prestamos.h"

int menuInformes()
{
    char auxOption[2];
    int option;
    system("cls") ;
    printf("\n\t\t*** MENU INFORMES ***\n\n");
    printf("3-Listar todos los socios que solicitaron un prestamo\nde un libro determinado(punto C)\n") ;
    printf("4-Listar todos los libros que fueron solicitados a prestamo\npor un socio determinado (punto D)\n") ;
    printf("7-Listar todos los libros solicitados a prestamo en una\nfecha determinada(punto G)\n") ;
    printf("8-Listar todos los socios que realizaron al menos una solicitud\na prestamo en una fecha determinada(punto H)\n") ;
    printf("9-Listar todos los libros ordenados por titulo(descendente),\nutilizando el metodo de burbujeo mas eficiente.(punto I)\n") ;
    printf("10-Listar todos los socios ordenados por apellido(ascendente),\nutilizando el metodo de insercion.(punto J)\n\n") ;
    printf("11-VOLVER AL MENU PRINCIPAL\n\n") ;
    while(!function_getStringNumeros("Ingresar opcion: ",auxOption))
    {
        printf("\n*** ERROR *** Debe ingresar un numero del 1 al 3. \n") ;
        system("pause") ;

    }
    option = atoi(auxOption) ;
    return option;
}

void listarSociosDeLibro(eLibro list[],int lenLibro,eSocios listSoc[],int lenSocios,eAutores listAu[],int lenAut,ePrestamos listPrest[],int lenPrest)
{
    char auxCodigoLibro[5];
    int indexLibro,indexSocio,codigoSocio;
    int contadorSocio = 0;

    system("cls");
    printf("Seleccione el libro a buscar:\n");
    showLibros(list,lenLibro,listAu,lenAut);
    while(!function_getStringNumeros("Ingrese el codigo del libro: ",auxCodigoLibro))
    {
        printf("\n***ERROR*** Debe ingresar solo numeros\n\n");
    }

    indexLibro = findLibroById(list,lenLibro,atoi(auxCodigoLibro));
    printf("\n\nEl libro %s fue solicitado por: \n",list[indexLibro].titulo);

    //ahora que tenemos el index del libro, recorremos la lista de prestamos

    for(int i = 0; i < lenPrest; i++)
    {
        if(atoi(auxCodigoLibro) == listPrest[i].codigoLib.codigoDelLibro)
        {
            codigoSocio = listPrest[i].codigoSoc.codigoDeSocio; //copio el codigo del socio
            indexSocio = findSocioById(listSoc,lenSocios,codigoSocio); //busco la posicon en el array de socios
            printf("\n");
            showSocio(listSoc[indexSocio]); // muestro el socio
            printf("\n");
            contadorSocio++;
        }


    }

    if(contadorSocio == 0)
    {
        printf("Nadie");
    }

}

void listarLibrosDeSocio(eLibro list[],int lenLibro,eSocios listSoc[],int lenSocios,eAutores listAu[],int lenAut,ePrestamos listPrest[],int lenPrest)
{
    char auxCodigoSocio[5];
    int indexLibro,indexSocio,codigoLibro;
    int contadorSocio = 0;

    system("cls");
    printf("Seleccione el socio/a a buscar:\n");
    showSocios(listSoc,lenSocios);
    while(!function_getStringNumeros("Ingrese el codigo del socio/a: ",auxCodigoSocio))
    {
        printf("\n***ERROR*** Debe ingresar solo numeros\n\n");
    }

    indexSocio = findSocioById(listSoc,lenSocios,atoi(auxCodigoSocio));
    printf("\n\nEl socio %s %s solicito los libros: \n",listSoc[indexSocio].nombre,listSoc[indexSocio].apellido);

    //ahora que tenemos el index del socio, recorremos la lista de prestamos

    for(int i = 0; i < lenPrest; i++)
    {
        if(atoi(auxCodigoSocio) == listPrest[i].codigoSoc.codigoDeSocio)
        {
            codigoLibro = listPrest[i].codigoLib.codigoDelLibro;//copio el codigo del libro
            indexLibro = findLibroById(list,lenLibro,codigoLibro); //busco la posicon en el array de libros
            printf("\n");
            showLibro(list[indexLibro],listAu,lenAut); // muestro el libro
            printf("\n");
            contadorSocio++;
        }


    }

    if(contadorSocio == 0)
    {
        printf("\nNingun libro solicitado.\n");
        system("pause");
    }


}

int listarLibrosPorTituloBurbujeo(eLibro list[], int len)
{
    eLibro auxLibro;
    int ret;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len -1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[i].titulo,list[j].titulo) < 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    auxLibro   = list[i];
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


void listarSociosPorInsercion(eSocios list[], int size)
{

    int i, j;
    eSocios auxSocio;

    for (i = 1; i < size; i++)
    {
        auxSocio = list[i];
        j = i - 1;
        while (strcmp(auxSocio.apellido,list[j].apellido) < 0)
        {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = auxSocio;
    }
}

void libroEnFechaDeterminada(ePrestamos listPrest[],int lenPres,eLibro listLibro[],int lenLibro,eAutores listAu[],int lenAut)
{
    char auxDia[3];
    char auxMes[3];
    char auxAnio[5];
    int codigoLibro,indexLibro;
    int contadorPrestamo = 0;

    system("cls");
    printf("Fecha a buscar:\n");
    ingresarDia(auxDia);
    ingresarMes(auxMes);
    ingresarAnio(auxAnio);

    for(int i=0; i<lenPres; i++)
    {
        if(listPrest[i].isEmpty == 0)
        {
            if(atoi(auxDia)==listPrest[i].fechaDePrestamo.dia && atoi(auxMes)==listPrest[i].fechaDePrestamo.mes && atoi(auxAnio)==listPrest[i].fechaDePrestamo.anio)
            {
            codigoLibro = listPrest[i].codigoLib.codigoDelLibro;//copio el codigo del libro
            indexLibro = findLibroById(listLibro,lenLibro,codigoLibro); //busco la posicon en el array de libros
                printf("\n\nCODIGO\tTITULO          APELLIDO    NOMBRE\n");
            printf("      \t                DEL AUTOR   DEL AUTOR\n\n");
            showLibro(listLibro[indexLibro],listAu,lenAut); // muestro el libro
            printf("_______________________________________________\n");
            contadorPrestamo++;
            }


        }


    }



    if(contadorPrestamo == 0)
    {
        printf("\nNo se realizo ningun prestamo en ese dia.\n\n");
        system("pause");
    }
}

void socioEnFechaDeterminada(ePrestamos listPrest[],int lenPres,eSocios listSoc[],int lenSoc)
{
    char auxDia[3];
    char auxMes[3];
    char auxAnio[5];
    int codigoSocio,indexSocio;
    int contadorPrestamo = 0;

    system("cls");
    printf("Fecha a buscar:\n");
    ingresarDia(auxDia);
    ingresarMes(auxMes);
    ingresarAnio(auxAnio);

    for(int i=0; i<lenPres; i++)
    {
        if(listPrest[i].isEmpty == 0)
        {
            if(atoi(auxDia)==listPrest[i].fechaDePrestamo.dia && atoi(auxMes)==listPrest[i].fechaDePrestamo.mes && atoi(auxAnio)==listPrest[i].fechaDePrestamo.anio)
            {
            codigoSocio = listPrest[i].codigoSoc.codigoDeSocio;//copio el codigo del socio
            indexSocio = findSocioById(listSoc,lenSoc,codigoSocio); //busco la posicon en el array de socio
            printf("\n\nCODIGO\tAPELLIDO\tNOMBRE\tSEXO\t  TELEFONO\t\tEMAIL\t\t FECHA DE INGRESO\n");
            showSocio(listSoc[indexSocio]); // muestro el socio
            printf("_______________________________________________\n");
            contadorPrestamo++;
            }

        }




    }
    if(contadorPrestamo == 0)
    {
        printf("\nNo se realizo ningun prestamo en ese dia.\n\n");
        system("pause");
    }


}
