typedef struct
{
    int file;
    char name[51];
    char lastName[51];
    char gender[51];
    char telefono[21];
    eFecha fechaSocios;
    char email[51];

    int isEmpty;
} eSocios;



int initSocios(eSocios list[], int len);
int findEmpty(eSocios list[],int len);
int findSocio(eSocios list[],int len, int file);
void viewSocio(eSocios aSocios);
void viewSocios(eSocios list[], int len);
int addSocio(eSocios list[], int len);
int removeSocio(eSocios* list, int len);
void modifySocio(eSocios list[], int len);
int sortSocios(eSocios list[], int len);
int funcion_opcionesSocios();
void ordenacion_insercion (eSocios* A, int len);
void harcodeoSocios(eSocios* list);


