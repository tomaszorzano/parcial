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
