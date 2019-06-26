typedef struct
{
    int codigoDePrestamo;
    eLibro codigoLib;
    eSocios codigoSoc;
    eFecha fechaDePrestamo;
    int isEmpty;

}ePrestamos;

int iniciarPrestamo(ePrestamos list[], int len);
/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */


int searchEmptyPrestamo(ePrestamos list[],int len);
/** \brief Busca un indice libre
 *
 * \param Array a buscar.
 * \param Tamaño del array
 * \return Devuelve el indice dond eesta vacio, y si no lo esta devuelve -1.
 *
 */


void mostrarPrestamo(ePrestamos listPrest,int lenPrest,eLibro listLibros[],int lenLibros,eSocios listSocios[],int lenSocios) ;
/** \brief show prestamo of a list
 *
 * \param array
 *
 */


void mostrarPrestamos(ePrestamos listPrest[],int lenPrest,eLibro listLibros[],int lenLibros,eSocios listSocios[],int lenSocios);
/** \brief show all prestamos of a list
 *
 * \param prestamos list int
 * \param lenght prestamos int
 *
 */


int addPrestamo(eSocios listSocios[],int tamSoc,eLibro listLibros[],int tamLibro,ePrestamos listPrest[],int tamPrest,eAutores listAut[],int tamAuto);
/** \brief add in a existing list of prestamos the values received as parameters
 * in the first empty position
 * \param list prestamo*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */

int menuPrestamos();
/** \brief Menu de opciones de los prestamos
 *
 * \return Opcion ingresada
 *
 */

void hardcodeoPrestamos(ePrestamos* list);
/** \brief carga una lista de prestamos
 *
 * \param lista prestamos
 *
 */
