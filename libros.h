typedef struct
{
    int codigoDelLibro;
    char titulo[51];
    eAutores codigoDeAutor;
    int isEmpty;
}eLibro;




void showLibro(eLibro list,eAutores listAutor[],int lenAutor);

void showLibros(eLibro list[],int len,eAutores listAutor[],int lenAutor);

void hardcodeoLibros(eLibro* list);

int findLibroById(eLibro list[], int len, int id);

int sortLibros(eLibro list[], int len);
