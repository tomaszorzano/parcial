#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "fecha.h"
#include "autores.h"
#include "libros.h"
#include "socios.h"
#include "prestamos.h"
#include "informes.h"
#define tamSocios 100
#define tamAutores 5
#define tamLibros 5
#define tamPrestamos 20

int main()
{
    //declaro variables
    char salir = 'n';
    char salirPrestamo = 'n';
    char salirInformes = 'n';
    eSocios sociosBiblioteca[tamSocios]; // se define al tipo eSocios el tamanio con el tamSocios
    eAutores escritores[tamAutores];
    eLibro exitos[tamLibros];
    ePrestamos prestamos[tamPrestamos];


    initSocios(sociosBiblioteca,tamSocios); //se inicializa todos los isEmpty en 1 indicando que estan vacios
    iniciarPrestamo(prestamos,tamPrestamos);
    hardcodeoSocios(sociosBiblioteca);
    hardcodeoAutores(escritores);
    hardcodeoLibros(exitos);
    hardcodeoPrestamos(prestamos);

    do
    {
        switch(menuSocios())
        {
        case 1: //ALTA SOCIO
            addSocio(sociosBiblioteca,tamSocios);
            break;
        case 2: //MODIFICAR SOCIO
            if(haySocioCargado(sociosBiblioteca,tamSocios)) //SE UTILIZA ESTA FUNCION PARA CHEQUEAR QUE SE HAYA CARGADO UN SOCIO
            {
                modifySocio(sociosBiblioteca,tamSocios);
                break;
            }
            else//SI NO HAY NINGUN SOCIO SE INFORMA
            {
                printf("***Error*** No hay ningun socio cargado.\n");
                system("pause");
                system("cls");
            }
            break;
        case 3://BAJA SOCIO
            if(haySocioCargado(sociosBiblioteca,tamSocios))
            {

                removeSocio(sociosBiblioteca,tamSocios,0);
                break;
            }
            else
            {
                printf("***Error*** No hay ningun socio cargado.\n");
                system("pause");
                system("cls");
            }
            break;
        case 4: //listar socios
            if(haySocioCargado(sociosBiblioteca,tamSocios))
            {
                system("cls");
                sortSocios(sociosBiblioteca,tamSocios); //se ordena los socios
                showSocios(sociosBiblioteca,tamSocios); // se muestra los socios
                system("pause");
            }
            else
            {
                printf("***Error*** No hay ningun socio cargado.\n");
                system("pause");
                system("cls");
            }
            break;
        case 5: //LISTAR LIBROS
            sortLibros(exitos,tamLibros);
            showLibros(exitos,tamLibros,escritores,tamAutores);
            printf("\n\n");
            system("pause");
            break;

        case 6: //LISTAR AUTORES
            sortAutores(escritores,tamAutores);
            showAutores(escritores,tamAutores);
            printf("\n\n");
            system("pause");
            break;
        case 7: // PRESTAMOS
            do
            {
                switch(menuPrestamos())
                {
                case 1:
                    addPrestamo(sociosBiblioteca,tamSocios,exitos,tamLibros,prestamos,tamPrestamos,escritores,tamAutores);
                    printf("\n\n");
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    mostrarPrestamos(prestamos,tamPrestamos,exitos,tamLibros,sociosBiblioteca,tamSocios);
                    printf("\n\n");
                    system("pause");
                    break;
                case 3:
                    salirPrestamo = 's';
                    printf("\n\nVolviendo al menu principal...\n\n");
                    system("pause");
                    break;
                }
            }
            while(salirPrestamo == 'n');
            break;
        case 8: // INFORMES
            do
            {
                switch(menuInformes())
                {
                case 3:
                    listarSociosDeLibro(exitos,tamLibros,sociosBiblioteca,tamSocios,escritores,tamAutores,prestamos,tamPrestamos);
                    printf("\n");
                    system("pause");
                    break;
                case 4:
                    listarLibrosDeSocio(exitos,tamLibros,sociosBiblioteca,tamSocios,escritores,tamAutores,prestamos,tamPrestamos);
                    printf("\n");
                    system("pause");
                    break;
                case 7:
                    libroEnFechaDeterminada(prestamos,tamPrestamos,exitos,tamLibros,escritores,tamAutores);
                    printf("\n");
                    system("pause");
                    break;
                case 8:
                    socioEnFechaDeterminada(prestamos,tamPrestamos,sociosBiblioteca,tamSocios);
                    printf("\n");
                    system("pause");
                    break;
                case 9:
                    listarLibrosPorTituloBurbujeo(exitos,tamLibros);
                    showLibros(exitos,tamLibros,escritores,tamAutores);
                    printf("\n");
                    system("pause");
                    break;
                case 10:
                    listarSociosPorInsercion(sociosBiblioteca,tamSocios);
                    showSocios(sociosBiblioteca,tamSocios);
                    printf("\n");
                    system("pause");
                    break;
                case 11:
                    printf("\n\nVolviendo...\n");
                    system("pause");
                    salirInformes = 's';
                    break;
                default:
                    printf("*** ERROR ***\n\n") ; // el default se utiliza por si se ingresa un numero que no sea del 1 al 8
                    system("pause");
                    system("cls");
                    break;
                }
            }
            while(salirInformes == 'n');
            break;
        case 9:
            printf("\n\nSaliendo...\n");
            system("pause");
            salir = 's';
            break;
        default:
            printf("*** ERROR *** Debe ingresar un numero del 1 al 9\n\n") ; // el default se utiliza por si se ingresa un numero que no sea del 1 al 8
            system("pause");
            system("cls");
            break;

        }



    }
    while(salir == 'n');

    return 0;
}
