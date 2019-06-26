#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "fecha.h"

void ingresarDia(char auxDia[])
{
    int dia;

    do //do while para validar
    {
        while(!function_getStringNumeros("Ingrese el dia(Del 1 al 31):",auxDia))
        {
            printf("**** Error ****Debe ingresar un numero del 1 al 31.\n\n");
            system("pause");
            system("cls");
        }
        dia = atoi(auxDia);
        if(dia < 0 || dia > 31)
        {
            printf("**** Error ****Debe ingresar un numero del 1 al 31.\n\n");

        }

    }
    while(dia < 0 || dia > 31);
}

void ingresarMes(char auxMes[])
{
    int mes;

    do //do while para validar el mes
    {
        while(!function_getStringNumeros("Ingrese el mes(Del 1 al 12):",auxMes))
        {
            printf("**** Error ****Debe ingresar un numero del 1 al 12.\n\n");
            system("pause");
            system("cls");
        }
        mes = atoi(auxMes);
        if(mes < 0 || mes > 12)
        {
            printf("***Error*** El mes debe ser del 1 al 12");
        }
    }
    while(mes < 0 || mes > 12);
}

void ingresarAnio(char auxAnio[])
{
while(!function_getStringNumeros("Ingrese el anio(4 digitos, EJ:1998):",auxAnio))
{
    printf("**** Error ****Debe ingresar numeros.\n\n");
    system("pause");
    system("cls");
}


}
