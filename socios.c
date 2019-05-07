#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
#include "fecha.h"
#include "libros.h"
#include "socios.h"


#define MAX 1001
#define MAXF 1001
#define MAXL 5

int initSocios(eSocios list[], int len)
{
    int ret = 0;

    if(list != NULL && len > 0)
    {

        for(int i=0; i < len; i++)
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
int findEmpty(eSocios list[],int len)
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
int findSocio(eSocios list[],int len, int file)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {

        if( list[i].file == file && list[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;

};

void viewSocio(eSocios aSocios)
{

    printf(" \nCodigo de Socio:%d - Nombre:%s -  Apellido:%s- Genero:%s\n\nTelefono:%s  Email:%s\n\nFecha de Asociado\n\nDia:%d-  Mes:%d-  Anio:%d \n\n-----------------------------------------\n\n ", aSocios.file, aSocios.name, aSocios.lastName, aSocios.gender, aSocios.telefono,aSocios.email,aSocios.fechaSocios.dia,aSocios.fechaSocios.mes,aSocios.fechaSocios.anio);
};

void viewSocios(eSocios list[], int len)
{

    system("cls");


    for(int i=0; i < len; i++)
    {

        if( list[i].isEmpty == 0)
        {
            viewSocio(list[i]);
        }
    }

};
int addSocio(eSocios list[], int len)
{
    eSocios newSocio;

    int index;
    char auxName[51];
    char auxLastName[51];
    char auxTelefono[11];
    char auxGender[51];
    char auxEmail[51];
    char auxDia[11];
    char auxMes[11];
    char auxAnio[11];
    float ret;
    int fechaCorrecta=-1;
    int nombre=0,apellido=0,telefono=0,genero=0,fecha=0;
    int email=0;

    if(list != NULL && MAX > 0 )
    {
        system("cls");
        fflush(stdin);
        index = findEmpty (list, len);
        printf("*** SOCIO NUEVO ***\n\n");
        if( index == -1)
        {

            printf("NO HAY ESPACIO EN EL SISTEMA\n\n");
            ret = -1;
            system("pause");
        }
        else
        {


            printf("Socio Nuevo, su codigo es : %d \n",index);
            newSocio.file = index ;




            if(nombre == 0 )
            {
                while(!funcion_getStringLetras("Ingrese Nombre: ",auxName))
                {
                    printf("ERROR- EL NOMBRE TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                    nombre=1;


                };
                 nombre=1;

            }


            printf("\nNombre: %s \n",auxName);

            if(apellido==0)
            {
                while(!funcion_getStringLetras("Ingrese Apellido: ",auxLastName))
                {
                    printf("ERROR- EL APELLIDO TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s \n",auxName);
                    apellido=1;

                };
                apellido=1;

            }
            printf("\nNombre: %s - Apellido: %s \n",auxName,auxLastName);
            if(telefono == 0)
            {
                while(!funcion_getStringTelefono("Ingrese Telefono: ",auxTelefono))
                {
                    printf("ERROR- EL TELEFONO TIENE QUE CONTENER EL SIGUIENTE FORMATO (xxxx-xxxx) \n\n");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s - Apellido: %s \n",auxName,auxLastName);
                    telefono=1;
                };
                telefono=1;

            }
            printf("\nNombre: %s - Apellido: %s - Telefono: %s \n",auxName,auxLastName,auxTelefono);

            if(genero == 0)
            {


                    while(!funcion_getStringLetras("Ingrese Genero: ",auxGender))
                    {
                        printf("ERROR- EL GENERO TIENE QUE CONTENER SOLO NUMEROS ENTEROS \n\n");
                        system("pause");
                        system("cls");
                        printf("\nNombre: %s - Apellido: %s - Salario: %s \n\n",auxName,auxLastName,auxTelefono);

                    };


                            genero=1;

                    }


                while ( genero == 0);

            }
            printf("\nNombre: %s - Apellido: %s - Salario: %s - Genero %s \n",auxName,auxLastName,auxTelefono,auxGender);

            if(email == 0)
            {
                while(!funcion_getStringEmail("Ingrese Email: ",auxEmail))
                {
                    printf("ERROR- EL EMAIL TIENE QUE CONTENER EL SIGUIENTE FORMATO (XXX@XXX.XX) \n\n");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s - Apellido: %s - Salario: %s- Genero: %s \n",auxName,auxLastName,auxTelefono,auxGender);
                    email=1;
                 };
                email=1;

            }
           printf("\nNombre: %s - Apellido: %s - Salario: %s - Genero %s - Email: %s \n",auxName,auxLastName,auxTelefono,auxGender,auxEmail);

            if(fecha == 0)
            {
                do
                {
                       system("cls");
                       printf("****** Fecha de Ingreso ******\n\n");
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

                printf("\nNombre: %s - Apellido: %s - Telefono: %s - Genero %s- Email: %s\n\nFecha de Ingreso\n\nDia %s - Mes %s - Anio %s \n\n",auxName,auxLastName,auxTelefono,auxGender,auxEmail,auxDia,auxMes,auxAnio);
                system("pause");

            while((nombre == 1) && (apellido == 1) && (telefono == 1) && (genero == 1) && (fecha == 1) && (email == 1))
            {
                strcpy(newSocio.name,auxName);
                strcpy(newSocio.lastName,auxLastName);
                strcpy(newSocio.gender,auxGender);
                strcpy(newSocio.telefono,auxTelefono);
                strcpy(newSocio.email,auxEmail);
                newSocio.fechaSocios.dia = atoi(auxDia);
                newSocio.fechaSocios.mes = atoi(auxMes);
                newSocio.fechaSocios.anio = atoi(auxAnio);


                newSocio.isEmpty = 0;
                list[index] = newSocio ;
                system("cls");
                printf("\n\n********SOCIO NUEVO, BIENVENIDO*********\n\n");
                viewSocio(list[index]);
                printf("\n\n\n");
                ret=0;
                break;


        }
    }
    else
    {
        ret =-1;
    }
    return ret;

};
int funcion_opciones()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES ******* \n\n");
    printf(" 1- ALTA \n");
    printf(" 2- MODIFICAR \n");
    printf(" 3- BAJA \n");
    printf(" 4- LISTAR SOCIOS \n");
    printf(" 5- LISTAR LIBROS \n");
    printf(" 6- LISTAR AUTORES \n");
    printf(" 7- PRESTAMOS \n");
    printf(" 8- SALIR \n");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-8 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 8\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
};

int funcion_opcionesModificacion()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES *******");
    printf("\n Que desea modificar?\n");
    printf(" 1- NOMBRE \n");
    printf(" 2- APELLIDO \n");
    printf(" 3- TELEFONO \n");
    printf(" 4- EMAIL \n");
    printf(" 5- GENERO \n");
    printf(" 6- NO MODIFICAR NADA \n ");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-6 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 6\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
};
int removeSocio(eSocios* list, int len)
{

    int index;
    char next[3];
    int id;
    char auxId[4];



    system("cls");
    printf("  *** BAJA SOCIO ***\n\n");

    while(!funcion_getStringNumeros("Ingrese Codigo de Socio: ", auxId))
    {
        printf("ERROR- EL CODIGO TIENE QUE TENER SOLO NUMEROS \n\n");
        system("pause");
        system("cls");
    };

    id=atoi(auxId);

    index = findSocio(list, len, id);

    while (index == 0)
    {
        printf("NO HAY NINGUN SOCIO CON ESE CODIGO %d\n\n", id);
        while(!funcion_getStringNumeros("Ingrese un codigo existente: ", auxId))
        {
            printf("ERROR- EL CODIGO TIENE QUE TENER SOLO NUMEROS \n\n");
            system("pause");
            system("cls");
        };
        id=atoi(auxId);
        index = findSocio(list, len, id);

    }



    while (index == 1)
    {
        viewSocio(list[index]);

        while(!funcion_getStringLetras("\nQUIERE BORRAR SOCIO DEL SISTEMA? si/no: ",next))
        {
            printf("\n ERROR DEBE CONTENER SOLO LETRAS");
        }

        fflush(stdin);



        if(strcmp(next,"si") && strcmp(next,"SI"))
        {
            printf("NO SE REALIZO LA BAJA\n\n");
            break;


        }
        else if(strcmp(next,"no")&& strcmp(next,"NO"))
        {

            list[index].isEmpty = 1;
            printf("SE HIZO LA BAJA DEL SOCIO CORRECTAMENTE\n\n");
            break;


        }

    }
    return -1;
}
void modifySocio(eSocios list[], int len)
{
    int id;
    char auxId[5];
    int index;
    char newTelefono[21];
    char newEmail[51];
    char newName[51];
    char newLastName[51];
    char newGender[31];
    char seguir='s';
    int exit = 1;

    system("cls");
    printf("  *** Modificar  Socio ***\n\n");

    while(!funcion_getStringNumeros("Ingrese Codigo: ", auxId))
    {
        printf("ERROR- EL CODIGO TIENE QUE TENER SOLO NUMEROS \n\n");
        system("pause");
        system("cls");
    };

    id=atoi(auxId);

    index = findSocio(list, len, id);

    while (index == -1)
    {
        printf("NO HAY NINGUN EMPLEADO CON ESE CODIGO %d\n\n", id);
        while(!funcion_getStringNumeros("Ingrese un codigo existente: ", auxId))
        {
            printf("ERROR- EL CODIGO TIENE QUE TENER SOLO NUMEROS \n\n");
            system("pause");
            system("cls");
        };
        id=atoi(auxId);
        index = findSocio(list, len, id);

    }


    while ((index >= 0) && (index <=1000))
    {
        viewSocio(list[index]);

        do
        {
            switch (funcion_opcionesModificacion())
            {
            case 1:
                fflush(stdin);
                viewSocio(list[index]);

                while(!funcion_getStringLetras("Ingrese nombre nuevo: ", newName))
                {
                    printf("ERROR- EL NOMBRE TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                };
                strcpy(list[index].name,newName);
                exit = 0;
                break;
            case 2:
                fflush(stdin);
                viewSocio(list[index]);
                while(!funcion_getStringLetras("Ingrese apellido nuevo: ",newLastName))
                {
                    printf("ERROR- EL APELLIDO TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                };
                strcpy(list[index].lastName,newLastName);
                exit = 0;

                break;
            case 3:
                fflush(stdin);
                viewSocio(list[index]);

                while(!funcion_getStringTelefono("Ingrese Telefono: ", newTelefono))
                {
                    printf("ERROR- EL TELEFONO TIENE QUE CONTENER SOLO NUMEROS \n\n");
                    system("pause");
                    system("cls");

                };

                strcpy(list[index].telefono,newTelefono);
                exit = 0;
                break;
            case 4:
                fflush(stdin);
                viewSocio(list[index]);


                while(!funcion_getStringEmail("Ingrese email nuevo: ", newEmail))
                {
                    printf("ERROR- EL EMAIL TIENE QUE CONTENER SOLO LETRAS \n\n");
                    system("pause");
                    system("cls");
                };
                strcpy(list[index].email,newEmail);
                exit = 0;
                break;
                case 5:
                fflush(stdin);
                viewSocio(list[index]);
                while(!funcion_getStringLetras("Ingrese genero nuevo: ", newGender))
                {
                    printf("ERROR- EL SECTOR TIENE QUE CONTENER SOLO LETRAS \n\n");
                    system("pause");
                    system("cls");
                };
                 strcpy(list[index].gender,newGender);
                exit = 0;
                break;
            case 6:
                printf("Volviendo a menu principal");
                exit = 1;

                break;
            default:
                printf("\n\nOpcion ingresada incorrecta, por favor ingrese una opcion del 1 al 6\n\n");
                system("pause");
                break;


            }

            if(exit==0)

            {
                printf("\n     *** MODIFICACCION EXITOSA ***");
                printf("\nDesea continuar modificando? \n\n");
                scanf("%c",&seguir);

                fflush(stdin);
                system("cls");
                break;
            }

            else
            {
                printf("\n\nEsta por salir de modificacion esta seguro? s/n \n\n");
                scanf("%c",&seguir);

                fflush(stdin);
                system("cls");

            }
            return;
        }
        while (seguir == 's' || seguir == 'S');


    }
    };

int sortSocios(eSocios list[], int len)
{
    eSocios auxSocio;

    int ret;


    if(list != NULL && len > 0)
    {

        for(int i = 0; i < len-1; i++)
        {
            for(int j = i+1; j < len; j++)
            {
               if(strcmp(list[j].lastName, list[i].lastName) > 0 && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                {
                    auxSocio = list[i];
                    list[i] = list[j];
                    list[j] = auxSocio;
                }
                else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].name < list[i].name  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                {
                    auxSocio = list[i];
                    list[i] = list[j];
                    list[j] = auxSocio;
                }
            }
        }
    }


    else
    {
        ret = -1;
    }


    return ret;

};
