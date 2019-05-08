typedef struct
{
    int id;
    char  titulo[51];
    int  codigoA;
    int isEmpty;


} eLibros;

void harcodeoLibros(eLibros* list);
void viewLibro(eLibros aLibros);
void viewlibros(eLibros list[], int len);
int funcion_opcionesLibros();
int findLibro(eLibros list[],int len, int file);
int findLibroXCodigo(eLibros list[],int len, int file);
int sortLibros(eLibros list[], int len);
