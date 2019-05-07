#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
#include "fecha.h"

int funcion_ValidarFecha(char dia[11],char mes[11],char anio[11])
{
    int auxDia,auxMes,auxAnio,ret=0;

    auxDia=atoi(dia);
    auxMes=atoi(mes);
    auxAnio=atoi(anio);

    if ( ((auxMes >= 1) && (auxMes <= 12)) )
    {
        switch ( auxMes )
        {
        case  1 :
        case  3 :
        case  5 :
        case  7 :
        case  8 :
        case 10 :
        case 12 :
            if ( auxDia >= 1 && auxDia <= 31 )
            {
                ret=1;
            }
            else
            {
                printf("Dia incorrecto\n\n");
                system("pause");
                ret=0;

            }
            break;

        case  4 :
        case  6 :
        case  9 :
        case 11 :
            if ( auxDia >= 1 && auxDia<= 30 )
            {
                ret=1;
            }
            else
            {
                printf("Dia incorrecto\n\n");
                system("pause");
                ret=0;
            }

            break;

        case  2 :
            if ( ((auxAnio % 4 == 0) && (auxAnio % 100 != 0)) || (auxAnio % 400 == 0 ))
            {
                if ( auxDia >= 1 && auxDia <= 29 )
                {
                    ret=1;
                }
                else
                {
                    printf("Dia incorrecto\n\n");
                    system("pause");
                    ret=0;
                }

            }
            else if ( auxDia >= 1 && auxDia <= 28 )
            {
                ret=1;
            }
            else
            {
                printf("Dia incorrecto\n\n");
                system("pause");
                ret=0;
            }

            break;



        }

    }
    else
    {
        printf("Mes Ingresado es incorrecto\n\n");
        system("pause");
    }

    return ret;
}
