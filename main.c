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
    eSocios socios[MAX];

    initSocios(socios,MAX);

    harcodeoAutores(autores);
    harcodeoLibros(libros);
    harcodeoSocios(socios);



    {
        char seguir='s';
        char seguirS='s';
        char seguirL='s';
        char seguirA='s';
        char seguirP='s';
        int exitP=1;
        int exitA=1;
        int exitS=1;
        int exitL=1;
        int cantPres=0;
        int acumPres=0;
        int totalPres;


        initPrestamos(prestamos,MAXPRES);
        int flagSinAlta=0;
        char auxLegajo[5];



        do
        {

            switch (funcion_opciones())
            {
            case 1://MENU SOCIOS

                do
                {
                    switch(funcion_opcionesSocios())
                    {
                    case 1 :
                        addSocio(socios, MAX);
                        flagSinAlta++;
                        exitS =0;
                        break;
                    case 2 :
                        if (flagSinAlta == 0)
                        {
                            printf("\nNO EXISTEN SOCIOS EN EL SISTEMA\n\n");
                            break;
                        }
                        else
                        {
                            modifySocio(socios, MAX);
                            exitS =0;

                        };
                        break;
                    case 3 :
                        if (flagSinAlta == 0)
                        {
                            printf("\nNO EXISTEN SOCIOS EN EL SISTEMA\n\n");
                            break;
                        }
                        else
                        {
                            removeSocio(socios, MAX);
                            exitS =0;

                        };
                        break;
                    case 4 :
                        if (flagSinAlta == 0)
                        {
                            printf("\nNO EXISTEN SOCIOS EN EL SISTEMA\n\n");
                            break;
                        }
                        else
                        {
                            sortSocios(socios,MAX);
                            viewSocios(socios, MAX);
                            exitS =0;

                        };
                        break;
                        case 5 :
                        if (flagSinAlta == 0)
                        {
                            printf("\nNO EXISTEN SOCIOS EN EL SISTEMA\n\n");
                            break;
                        }
                        else
                        {
                            ordenacion_insercion(socios,MAX);
                            viewSocios(socios, MAX);
                            exitS =0;

                        };
                        break;
                    case 6 :
                        printf("Volviendo a menu principal");
                        exitS=1;
                        break;
                    default:
                        printf("\n\nOpcion ingresada incorrecta, por favor ingrese una opcion del 1 al 5\n\n");
                        system("pause");
                        break;
                    }
                    if(exitS==0)

                    {
                        printf("\n *** Socios ***");
                        printf("\nDesea continuar en menu socios? \n\n");

                        scanf("%c",&seguirS);


                        fflush(stdin);
                        system("cls");

                    }

                    else
                    {
                        printf("\n\nEsta por salir del menu socios esta seguro? s/n \n\n");
                        scanf("%c",&seguirS);
                        if(seguirS == 's' || seguirS == 'S')
                        {
                            seguirS='n';
                        }
                        fflush(stdin);
                        system("cls");

                    }

                }
                while (seguirS == 's' || seguirS == 'S');


                break;
            case 2: //MENU LIBROS

                do
                {
                    switch(funcion_opcionesLibros())
                    {
                    case 1 :
                        viewlibros(libros,MAXLIB);
                        exitL =0;
                        break;
                    case 2 :
                        sortLibros(libros,MAXLIB);
                        printf("\n\nLIBROS ORDENADOS POR TITULO DE FORMA DESCENDETE\n\n");
                        system("pause");
                        break;
                    case 3 :
                        printf("Volviendo a menu principal");
                        exitL=1;
                        break;
                    default:
                        printf("\n\nOpcion ingresada incorrecta, por favor ingrese una opcion del 1 al 2\n\n");
                        system("pause");
                        break;
                    }
                    if(exitL==0)

                    {
                        printf("\n *** Libros ***");
                        printf("\nDesea continuar en menu libros? \n\n");

                        scanf("%c",&seguirL);
                        if(seguirL == 's' || seguirL == 'S')
                        {
                            seguirL='s';
                        }

                        fflush(stdin);
                        system("cls");

                    }

                    else
                    {
                        printf("\n\nEsta por salir del menu libros esta seguro? s/n \n\n");
                        scanf("%c",&seguirL);
                        if(seguirL == 's' || seguirL == 'S')
                        {
                            seguirL='n';
                        }
                        fflush(stdin);
                        system("cls");

                    }

                }
                while (seguirL == 's' || seguirL == 'S');
                break;

            case 3: //MENU AUTORES
                do
                {
                    switch(funcion_opcionesAutores())
                    {
                    case 1 :
                        viewAutores(autores,MAXAUT);
                        exitA =0;
                        break;
                    case 2 :
                        printf("Volviendo a menu principal");
                        exitA=1;
                        break;
                    default:
                        printf("\n\nOpcion ingresada incorrecta, por favor ingrese una opcion del 1 al 2\n\n");
                        system("pause");
                        break;
                    }
                    if(exitA==0)

                    {
                        printf("\n *** AUTORES ***");
                        printf("\nDesea continuar en menu autores? \n\n");

                        scanf("%c",&seguirA);
                        if(seguirA == 's' || seguirA == 'S')
                        {
                            seguirA='s';
                        }

                        fflush(stdin);
                        system("cls");

                    }

                    else
                    {
                        printf("\n\nEsta por salir del menu autores esta seguro? s/n \n\n");
                        scanf("%c",&seguirA);
                        if(seguirA == 's' || seguirA == 'S')
                        {
                            seguirA='n';
                        }
                        fflush(stdin);
                        system("cls");

                    }

                }
                while (seguirA == 's' || seguirA == 'S');
                break;
            case 4://MENU PRESTAMOS
                if (flagSinAlta == 0)
                {
                    printf("\nNO EXISTEN SOCIOS EN EL SISTEMA\n\n");
                    break;
                }
                else
                {
                    do
                    {
                        switch(funcion_opcionesPrestamos())
                        {
                        case 1 :


                            addPrestamo(prestamos,MAXPRES,socios,MAX,libros,MAXLIB);
                            cantPres++;
                            totalPres = (acumPres + cantPres);

                            system("pause");
                            exitP =0;



                            break;
                        case 2 :
                            while(!funcion_getStringNumeros("Ingrese codigo del socio para ver sus prestamos: ",auxLegajo))
                            {
                                printf("ERROR- EL CODIGO TIENE QUE CONTENER SOLO NUMEROS\n\n ");
                                system("pause");
                                system("cls");
                            };
                           // viewPrestamoID(prestamos,socios,auxLegajo,libros);


                            exitP=0;
                            break;
                        case 3 :
                            printf("Volviendo a menu principal");
                            exitP=1;
                            break;
                        default:
                            printf("\n\nOpcion ingresada incorrecta, por favor ingrese una opcion del 1 al 3\n\n");
                            system("pause");
                            break;
                        }
                        if(exitP==0)

                        {
                            printf("\n *** PRESTAMOS ***");
                            printf("\nDesea continuar en menu prestamos? \n\n");

                            scanf("%c",&seguirP);
                            if(seguirP == 's' || seguirP == 'S')
                            {
                                seguirP='s';
                            }

                            fflush(stdin);
                            system("cls");

                        }

                        else
                        {
                            printf("\n\nEsta por salir del menu prestamos esta seguro? s/n \n\n");
                            scanf("%c",&seguirP);
                            if(seguirP == 's' || seguirP == 'S')
                            {
                                seguirP='n';
                            }
                            fflush(stdin);
                            system("cls");

                        }

                    }
                    while (seguirP == 's' || seguirP == 'S');
                    break;


                };

                break;
                case 5://informes
                printf("\n\nTotal general de prestamos: %d\n\n",totalPres);
                mostrarlibrosdesocios(libros,MAXLIB,socios,MAX,prestamos,MAXPRES);
                system("pause");

                break;
                 case 6://SALIR
                printf("Saliendo...");
                exit(-1);
                break;



            default:
                printf("\n\nOpcion ingresada incorrecta, por favor ingrese una opcion del 1 al 5\n\n");
                system("pause");
                break;

            }
            printf("\n Desea continuar en el ABM? si/no \n\n");
            scanf("%c",&seguir);

            fflush(stdin);
            system("cls");


        }
        while (seguir == 's' || seguir == 'S');

        printf("\n\n Saliendo...\n\n");

    }
    return 0;
}

int funcion_opciones()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES ******* \n\n");
    printf(" 1- SOCIOS \n");
    printf(" 2- LIBROS \n");
    printf(" 3- AUTORES \n");
    printf(" 4- PRESTAMOS \n");
    printf(" 5- INFORMES \n");
    printf(" 6- SALIR \n");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-6 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 6\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
};
