typedef struct
{
    int codigoPrestamo;
    eLibros libroPre;
    eSocios socioPre;
    eFecha fechaPre;
    int isEmpty;

} ePrestamos;


int initPrestamos(ePrestamos list[], int len);
void viewPrestamoADD(ePrestamos aPrestamos, eSocios listSoc[],int indexS,eLibros listLib[],int indexl);
void viewPrestamoID(ePrestamos aPrestamos, eSocios listSoc[],int indexS, eLibros listLib[]);
//void viewPrestamos(ePrestamos list[], int len, eSocios listSoc[],int index,eLibros listLib[],int indexL);
int findEmptyPrestamos(ePrestamos list[],int len);
int findPrestamos(ePrestamos list[],int len, int file);
int addPrestamo(ePrestamos list[],int len,eSocios listSoc[],int lenSoc,eLibros listLibros[],int lenLib);
int funcion_opcionesPrestamos();
void mostrarlibrosdesocios(eLibros list[],int lenL,eSocios listSoc[],int lenSoc,ePrestamos listPres[],int lenPres);

