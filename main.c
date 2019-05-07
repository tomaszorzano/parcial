#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
#include "fecha.h"
#include "autores.h"
#include "libros.h"
#include "socios.h"
#include "prestamos.h"

#define MAX 1001
#define MAXAUT 5
#define MAXLIB 5
#define MAXPRES 21
#define MAXF 1001
int funcion_opciones();

int main()
{
    eAutores autores[MAXAUT];
    eLibros libros[MAXLIB];
    ePrestamos prestamos[MAXPRES];

    harcodeoAutores(autores);
    harcodeoLibros(libros);


    {
        char seguir='s';
        eSocios socios[MAX];
        initSocios(socios,MAX);
        initPrestamos(prestamos,MAXPRES);
        int flagSinAlta=0;
        char auxLegajo[5];



        do
        {

            switch (funcion_opciones())
            {
            case 1:
                addSocio(socios, MAX);
                flagSinAlta++;
                break;
            case 2:
                if (flagSinAlta == 0)
                {
                    printf("\nNO EXISTEN SOCIOS EN EL SISTEMA\n\n");
                    break;
                }
                else
                {
                    modifySocio(socios, MAX);
                };
                break;
            case 3:
                if (flagSinAlta == 0)
                {
                    printf("\nNO EXISTEN SOCIOS EN EL SISTEMA\n\n");
                    break;
                }
                else
                {
                    removeSocio(socios, MAX);
                };
                break;
            case 4:
                if (flagSinAlta == 0)
                {
                    printf("\nNO EXISTEN SOCIOS EN EL SISTEMA\n\n");
                    break;
                }
                else
                {
                    sortSocios(socios,MAX);
                    viewSocios(socios, MAX);
                };

                break;
            case 5:
                if (flagSinAlta == 0)
                {
                    printf("\nNO EXISTEN EMPLEADOS EN EL SISTEMA\n\n");
                    break;
                }
                else
                {
                    viewlibros(libros,MAXLIB);

                };

                break;
            case 6:
                if (flagSinAlta == 0)
                {
                    printf("\nNO EXISTEN EMPLEADOS EN EL SISTEMA\n\n");
                    break;
                }
                else
                {
                    viewAutores(autores,MAXAUT);

                };
                break;
                case 7:
                if (flagSinAlta == 0)
                {
                    printf("\nNO EXISTEN EMPLEADOS EN EL SISTEMA\n\n");
                    break;
                }
                else
                {

                    addPrestamo(prestamos,MAXPRES,socios,MAX,libros,MAXLIB);
                    system("cls");
                    viewSocios(socios,MAX);
                    while(!funcion_getStringNumeros("Ingrese codigo del socio para ver sus prestamos: ",auxLegajo))
                    {
                        printf("ERROR- EL CODIGO TIENE QUE CONTENER SOLO NUMEROS\n\n ");
                        system("pause");
                        system("cls");
                      };

                   viewPrestamos(prestamos,MAXPRES,socios,atoi(auxLegajo));

                };
                break;
                case 8:
                printf("Saliendo...");
                exit(-1);
                break;
            default:
                printf("\n\nOpcion ingresada incorrecta, por favor ingrese una opcion del 1 al 5\n\n");
                system("pause");
                break;

            }
            printf("\n Desea continuar? si/no \n\n");
            scanf("%c",&seguir);

            fflush(stdin);
            system("cls");


        }
        while (seguir == 's' || seguir == 'S');

        printf("\n\n Saliendo...\n\n");

    }
    return 0;
}
