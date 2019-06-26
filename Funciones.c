#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


float funcion_suma(float opc1,float opc2)
{

    float resp ;
    resp = opc1 + opc2 ;
    return resp ;
}

float funcion_resta(float opc1,float opc2)
{

    float resp;
    resp=opc1-opc2 ;
    return resp ;
}

float funcion_multiplicar(float opc1,float opc2)
{

    float resp ;
    resp=opc1*opc2 ;
    return resp ;
}

float funcion_dividir(float opc1,float opc2)
{

    float resp ;
    if(opc2 == 0)
    {

        return -1 ;
    }
    else
    {
        resp=opc1/opc2 ;
        return resp ;
    }
}

int funcion_factorial(int opc1)
{
    int resp;
    if(opc1==0)
    {
        return 1;
    }

    resp=opc1*funcion_factorial(opc1-1) ;
    return resp ;
}
// funciones get
float function_getFloat(char msj[])
{
    float aux;
    printf("%s",msj);
    scanf("%f",&aux);
    return aux;
}

int function_getInt(char msj[] )
{
    int resultado;
    printf("%s",msj);
    scanf("%d",&resultado);
    return resultado;
}

char function_getChar(char msj[])
{
    char aux;
    printf("%s",msj);
    fflush(stdin);
    scanf("%c",&aux);
    return aux;
}

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int function_esNum(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int function_esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int function_esAlfaNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

int function_esTelefono(char str[])
{
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

void function_getString (char msj[],char input[])
{
    printf("%s",msj);
    fflush(stdin) ;
    gets(input) ;
}

int function_getStringLetras(char msj[],char input[])
{
    char aux[256];
    function_getString(msj,aux);
    if(function_esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0 ;
}

int function_getStringNumeros(char msj[],char input[])
{
    char aux[256];
    function_getString(msj,aux);
    if(function_esNum(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    function_getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int menu ( )
{
    char auxOption[2];
    int option;
    system("cls") ;
    printf("\n\t\t*** MENU PRINCIPAL ***\n\n");
    printf("1-MENUES \n");
    printf("2-EMPLEADOS \n") ;
    printf("3-ALMUERZOS \n");
    printf("4-INFORMES \n");
    printf("5-SALIR\n\n") ;
    while(!function_getStringNumeros("Ingresar opcion: ",auxOption))
    {
        printf("\n*** ERROR *** Debe ingresar un numero del 1 al 5. \n") ;
        system("pause") ;

    }
    option = atoi(auxOption) ;
    return option;
}



void function_validName(char text[])
    {
        int dentro_de_palabra = 0; // Al principio está fuera
        for (int i = 0; text[i] != '\0'; i++)
        {
            if (text[i] == ' ')
            {
                dentro_de_palabra = 0; // Fuera de palabra
            }
            else
            {
                if (dentro_de_palabra)
                {
                    // Ya estábamos dentro de una palabra
                    text[i] = tolower(text[i]);
                }
                else
                {
                    // Acabamos de entrar en una nueva palabra
                    dentro_de_palabra = 1;
                    text[i] = toupper(text[i]);
                }
            }
        }
    }

char* getDynamicString(char* msg)
{
    printf(msg);

    char* pData = (char*)malloc(sizeof(char)*1024);

    scanf("%1023s",pData); // cantidad maxima 1023 (dejamos 1 byte para terminador)

    int len = strlen(pData);

    pData = (char*)realloc(pData,sizeof(char)*(len+1)); //realloc de len (cantidad de letras) + 1  byte por caracter terminador

    return pData;
}
