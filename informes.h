
int menuInformes();
/** \brief Menu de opciones de los informes
 *
 * \return Opcion ingresada
 *
 */

 void listarSociosDeLibro(eLibro list[],int lenLibro,eSocios listSoc[],int lenSocios,eAutores listAu[],int lenAut,ePrestamos listPrest[],int lenPrest);

  void listarLibrosDeSocio(eLibro list[],int lenLibro,eSocios listSoc[],int lenSocios,eAutores listAu[],int lenAut,ePrestamos listPrest[],int lenPrest);

int listarLibrosPorTituloBurbujeo(eLibro list[], int len);

 void listarSociosPorInsercion(eSocios list[], int size);

 void libroEnFechaDeterminada(ePrestamos listPrest[],int lenPres,eLibro listLibro[],int lenLibro,eAutores listAu[],int lenAut);

 void socioEnFechaDeterminada(ePrestamos listPrest[],int lenPres,eSocios listSoc[],int lenSoc);


