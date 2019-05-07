#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/** \brief Suma de dos numeros flotantes.
    \param Valor asignado a variable "a".
    \param valor asignado a variable "b".
    \return Devuelve el resultado de la suma de las dos variables.
*/


float funcion_Suma(float a , float b)

{
    float resSuma;
    resSuma = a + b;
    return resSuma;
};

/** \brief Resta de dos numeros flotant
    \param Valor asignado a variable "a".
    \param Valor asignado a variable "b".
    \return Devuelve el resultado de la resta de las dos variables.
*/


float funcion_Resta(float a,float b)
{
    float resResta;
    resResta= a - b;
    return resResta;

};


/** \brief Multiplicacion de dos numeros flotantes.
    \param Valor asignado a variable "a".
    \param Valor asignado a variable "b".
    \return Devuelve el resultado de la multiplicacion de las dos variables.
*/



float funcion_Multiplicacion(float a,float b)
{
    float resMultiplicacion;
    resMultiplicacion= a * b;
    return resMultiplicacion;

};


/** \brief Division de dos numeros flotantes
    \param Valor asignado a variable "a".
    \param Valor asignado a variable "b".
    \return Devuelve el resultado de la division de las dos variables.
*/


float funcion_Division(float a,float b)
{
    float resDivision;

    if(b ==0)
    {

        return -1;

    }
    else
    {
        resDivision=a/b;
        return resDivision;
    }


};


/** \brief Factoriza un numero entero
    \param Valor asignado a variable "a".
    \return Devuelve el resultado de la factorial de la variable.
*/



int funcion_Factorial(int a)
{
    int valor;
    if(a==0)
    {
        return 1;
    }
    valor=a*funcion_Factorial(a-1);
    return valor;
};

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float funcion_getFloat(char* mensaje)
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int funcion_getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char funcion_getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}


/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int funcion_validarNumeroFlotante(char str[])
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

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int funcion_ValidarNumero(char str[])
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

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int funcion_validarSoloLetras(char str[])
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


/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int funcion_validarAlfaNumerico(char str[])
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


/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int funcion_ValidarTelefono(char str[])
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
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void funcion_getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    gets(input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int funcion_getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    funcion_getString(mensaje,aux);
    if(funcion_validarSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int funcion_getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    funcion_getString(mensaje,aux);
    if(funcion_ValidarNumero(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int funcion_getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    funcion_getString(mensaje,aux);
    if(funcion_validarNumeroFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int funcion_getStringTelefono(char mensaje[],char input[])
{
    char aux[256];
    funcion_getString(mensaje,aux);
    if(funcion_ValidarTelefono(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int funcion_validarEmail(char str[])
{
   int i=0;
   int contadorArroba=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9') && (str[i] != '@') && (str[i] != '.')&& (str[i] != '_')&& (str[i] != '-')&& (str[i] != '/'))
           return 0;
           if(str[i] == '@')
            contadorArroba++;

       i++;
   }
   if(contadorArroba==1) // debe tener un guion
        return 1;
   return 0;
}

int funcion_getStringEmail(char mensaje[],char input[])
{
    char aux[256];
    funcion_getString(mensaje,aux);
    if(funcion_validarEmail(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int funcion_getStringAlfaNumerico(char mensaje[],char input[])
{
    char aux[256];
    funcion_getString(mensaje,aux);
    if(funcion_validarAlfaNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
