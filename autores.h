typedef struct
{
    int codigo;
    char nombre[51];
    char apellido[51];
    int isEmpty;
} eAutores;

void harcodeoAutores(eAutores* list);
void viewAutor(eAutores aAutores);
void viewAutores(eAutores list[], int len);

