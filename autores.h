typedef struct
{
    int codigoDeAutor;
    char apellido[31];
    char nombre[31];
    int isEmpty;

}eAutores;

void hardcodeoAutores(eAutores* list);

void showAutor(eAutores list);

void showAutores(eAutores list[],int len);

int obtenerAutor(eAutores list[], int len, int idAutor, char apellido[],char nombre[]);

int sortAutores(eAutores list[], int len);
