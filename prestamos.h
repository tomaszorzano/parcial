typedef struct
{
    int codigoPrestamo;
    eLibros libroPre;
    eSocios socioPre;
    eFecha fechaPre;
    int isEmpty;

} ePrestamos;


int initPrestamos(ePrestamos list[], int len);
void viewPrestamo(ePrestamos aPrestamos, eSocios listSoc[],int index);
void viewPrestamos(ePrestamos list[], int len, eSocios listSoc[],int index);
int findEmptyPrestamos(ePrestamos list[],int len);
int findPrestamos(ePrestamos list[],int len, int file);
int addPrestamo(ePrestamos list[],int len,eSocios listSoc[],int lenSoc,eLibros listLibros[],int lenLib);
int funcion_opcionesPrestamos();

