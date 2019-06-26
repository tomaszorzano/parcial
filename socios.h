typedef struct
{
    int codigoDeSocio;
    char apellido[31];
    char nombre[31];
    char sexo[10];
    long int telefono;
    char email[31];
    eFecha fechaDeInscipcion;
    int isEmpty;
} eSocios;

//Funciones de empleados

int initSocios(eSocios list[], int len) ;
/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */


int searchEmpty(eSocios list[],int len);
/** \brief Busca un indice libre
 *
 * \param Array a buscar.
 * \param Tamaño del array
 * \return Devuelve el indice dond eesta vacio, y si no lo esta devuelve -1.
 *
 */


int findSocioById(eSocios list[], int len, int id) ;
/** \brief  find an socio by Id en returns the index position in array.
 *
 * \param list socio
 * \param len int
 * \param id int
 * \return  Return socio index position or (-1) if the socio not found.
 *
 */

void showSocio(eSocios list);
/** \brief show socio of a list
 *
 * \param array
 *
 */

void showSocios(eSocios list[],int len);
/** \brief show all socios of a list
 *
 * \param socios list int
 * \param lenght socios int
 *
 */

int addSocio(eSocios list[], int len) ;
/** \brief add in a existing list of socios the values received as parameters
 * in the first empty position
 * \param list socio*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */



void modifySocio(eSocios list[], int len);


void hardcodeoSocios(eSocios* list);
/** \brief carga una lista de socios
 *
 * \param array socio
 *
 */

int removeSocio(eSocios list[], int len,int id);
/** \brief Remove a socio by Id (put isEmpty Flag in 1)
 *
 * \param list socio*
 * \param lenght int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a socio] - (0) if Ok
 *
 */


int sortSocios(eSocios list[], int len) ;
/** \brief Sort the elements in the array of employees,
 *
 * \param list socio*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */


int haySocioCargado (eSocios list[],int len);
/** \brief Informa si hay algun socio cargado en el array
 *
 * \param list socio
 * \param lenght int
 * \return devuelve 1 si esta cargado o -1 si no hay ningun socio
 *
 */


int menuSocios ( );
/** \brief Menu de opciones de los socios
 *
 * \return Opcion ingresada
 *
 */

int menuModificarSocios ();
/** \brief Menu de opciones para modificar el socio
*
* \return Opcion ingresada
*
*/


