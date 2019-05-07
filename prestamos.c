#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
#include "autores.h"
#include "fecha.h"
#include "libros.h"
#include "socios.h"
#include "prestamos.h"

#define MAXPREST 21
#define MAXLIB 5
#define MAXSOC 101

int initPrestamos(ePrestamos list[], int len)
{
    int ret = 0;

    if(list != NULL && len > 0)
    {

        for(int i=1; i < len; i++)
        {

            list[i].isEmpty = 1;
        };
    }
    else
    {
        ret = -1;
    };

    return ret;
};

int findEmptyPrestamos(ePrestamos list[],int len)
{
    int index = -1;
    for(int i=0; i< len ; i++)
    {
        if( list[i].isEmpty == 1)
        {
            index = i ;
            break;
        };
    };
    return index ;
};
int findPrestamos(ePrestamos list[],int len, int file)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {

        if( list[i].codigoPrestamo == file && list[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;

};

void viewPrestamo(ePrestamos aPrestamos, eSocios listSoc[],int index, eLibros listLib[],int indexL)
{


    viewSocio(listSoc[index]);
    viewLibro(listLib[indexL]);
    printf(" \nCodigo Libro:%d - Legajo Socio:%d-\n\nFecha de Prestamo\n\n Dia:%d- Mes:%d- Anio:%d \n---------------------------\n ", aPrestamos.codigoPrestamo, aPrestamos.socioPre.file,aPrestamos.fechaPre.dia,aPrestamos.fechaPre.mes,aPrestamos.fechaPre.anio);
};

void viewPrestamos(ePrestamos list[], int len, eSocios listSoc[],int index,eLibros listLib[],int indexL)
{

    system("cls");


    for(int i=0; i < len; i++)
    {

        if( list[i].isEmpty == 0)
        {
            viewPrestamo(list[i],listSoc,index,listLib,indexL);
        }
    }

};
int addPrestamo(ePrestamos list[],int len,eSocios listSoc[],int lenSoc,eLibros listLib[],int lenLib)
{


    ePrestamos newPrestamo;



    harcodeoLibros(listLib);

    int index;
    int indexE;
    char auxLibro[51];
    char auxLegajo[51];
    char auxDia[11];
    char auxMes[11];
    char auxAnio[11];
    char auxName[51];
    char codigoLibro[5];
    int indexLibro=0;


    //Contadores
    int contLibro1=0;
    int contLibro2=0;
    int contLibro3=0;
    int contLibro4=0;
    int contLibro5=0;

    char auxLastName[51];
    float ret;
    int fechaCorrecta=-1;
    int libro=0,legajo=0,fecha=0;


    if(list != NULL && MAXPREST > 0 )
    {
        system("cls");
        fflush(stdin);
        index = findEmptyPrestamos(list,len);
        printf("*** ALTA PRESTAMO ***\n\n");
        if( index == -1)
        {

            printf("NO HAY ESPACIO EN EL SISTEMA\n\n");
            ret = -1;
            system("pause");
        }
        else
        {


            printf("Nuevo Prestamo, su codigo es : %d \n",index);
            newPrestamo.codigoPrestamo = index ;




            if(libro == 0 )
            {

                viewlibros(listLib,MAXLIB);
                int existeLibro=0;


                do
                {

                    existeLibro=0;
                    while(!funcion_getStringNumeros("Ingrese codigo del libro: ",codigoLibro))
                    {
                        printf("ERROR- EL CODIGO TIENE QUE CONTENER SOLO NUMEROS\n\n ");
                        system("pause");
                        system("cls");
                        existeLibro=0;
                        libro=1;
                    }
                    indexLibro=findLibro(listLib,MAXLIB,atoi(codigoLibro));
                    if(indexLibro == -1)
                    {
                        printf("No existe libro\n\n");
                        system("pause");
                        system("cls");
                        existeLibro=1;

                    }
                }while (existeLibro == 1 );

                libro=1;
            }
            printf("\nLibro: %s \n",auxLibro);

            if(legajo==0)
            {
                viewSocios(listSoc,lenSoc);
                int existeSocio=0;


                do
                {

                    existeSocio=0;
                     while(!funcion_getStringNumeros("Ingrese codigo del socio: ",auxLegajo))
                {
                    printf("ERROR- EL CODIGO TIENE QUE CONTENER SOLO NUMEROS\n\n ");
                    system("pause");
                    system("cls");
                    existeSocio=0;
                    legajo=1;

                }
                    indexE=findSocio(listSoc,MAXSOC,atoi(auxLegajo));
                    if(indexE == -1)
                    {
                        printf("No existe socio\n\n");
                        system("pause");
                        system("cls");
                        existeSocio=1;

                    }
                }while (existeSocio == 1 );
                legajo=1;

            }
            printf("\nLibro: %s - Codigo: %s \n",auxLibro,auxLegajo);
            if(fecha == 0)
            {
                do
                {
                       system("cls");
                       printf("****** Fecha de Prestamo ******\n\n");
                       while(!funcion_getStringNumeros("Ingrese dia: ", auxDia))
                        {
                            printf("ERROR- EL DIA TIENE QUE CONTENER SOLO NUMEROS \n\n");
                            system("pause");
                            system("cls");

                        };
                        while(!funcion_getStringNumeros("Ingrese mes: ", auxMes))
                        {
                            printf("ERROR- EL MES TIENE QUE CONTENER SOLO NUMEROS \n\n");
                            system("pause");
                            system("cls");

                        };
                        while(!funcion_getStringNumeros("Ingrese anio: ", auxAnio))
                        {
                            printf("ERROR- EL ANIO TIENE QUE CONTENER SOLO NUMEROS \n\n");
                            system("pause");
                            system("cls");
                        };

                        fechaCorrecta = funcion_ValidarFecha(auxDia,auxMes,auxAnio);

                    }
                    while(fechaCorrecta == 0);

                fecha=1;


            }
                indexE=findSocio(listSoc,MAXSOC,atoi(auxLegajo));
                strcpy(auxName,newPrestamo.socioPre.name);
                strcpy(auxLastName,newPrestamo.socioPre.lastName);

                printf("\nLegajo: %s\n\nFecha de Prestamo\n\nDia %s - Mes %s - Anio %s \n\n",auxLegajo,auxDia,auxMes,auxAnio);
                viewLibro(listLib[indexLibro]);
                viewSocio(listSoc[indexE]);

                system("pause");

            while((libro == 1) && (legajo == 1) &&(fecha == 1))
            {

                strcpy(newPrestamo.libroPre.titulo,auxLibro);
                newPrestamo.socioPre.file = atoi(auxLegajo);
                newPrestamo.fechaPre.dia = atoi(auxDia);
                newPrestamo.fechaPre.mes= atoi(auxMes);
                newPrestamo.fechaPre.anio = atoi(auxAnio);


                newPrestamo.isEmpty = 0;
                list[index] = newPrestamo ;
                system("cls");
                printf("\n\n********PRESTAMO CARGADO CORRECTAMENTE*********\n\n");

                viewPrestamo(list[index],listSoc,indexE,listLib,indexLibro);
                printf("\n\n\n");
                ret=0;
                break;

            }
        }
    }
    else
    {
        ret =-1;
    }
    return ret;

};

int funcion_opcionesPrestamos()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES ******* \n\n");
    printf(" 1- ALTA PRESTAMO \n");
    printf(" 2- LISTAR PRESTAMO POR LEGAJO\n");
    printf(" 3- SALIR \n");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-3 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 3\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
};
