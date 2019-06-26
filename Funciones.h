/** \brief Suma dos variables.
 *
 * \param Valor asignado a la variable 1.
 * \param Valor asignado a la variable 2.
 * \return Devuelve la suma de las dos variables.
 *
 */
float funcion_suma (float opc1,float opc2) ;

/** \brief Resta dos variables.
 *
 * \param Valor asignado a la variable 1.
 * \param Valor asignado a la variable 2.
 * \return Devuelve la resta de las dos variables.
 *
 */
float funcion_resta (float opc1,float opc2);

/** \brief Multiplica dos variables.
 *
 * \param Valor asignado a la variable 1.
 * \param Valor asignado a la variable 2.
 * \return Devuelve la multiplicacion de las dos variables.
 *
 */
float funcion_multiplicar (float opc1,float opc2) ;

/** \brief Divide dos variables.
 *
 * \param Valor asignado a la variable 1.
 * \param Valor asignado a la variable 2.
 * \return Devuelve el resultado de las dos variables o un error si el divisor es 0.
 *
 */
float funcion_dividir (float opc1,float opc2) ;

/** \brief Calcula el factorial de una variable
 *
 * \param Variable utilizada.
 * \return Factorial de la variable.
 *
 */
int funcion_factorial(int opc1) ;

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */

 //funciones get.
/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float function_getFloat(char msj[]) ;

 /**
 * \brief Solicita un numero entero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El numero entero ingresado por el usuario
 *
 */
int function_getInt(char msj[] );

 /**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El numero entero ingresado por el usuario
 *
 */
char function_getChar(char msj[]) ;

/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumericoFlotante(char str[]);

 /**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int function_esNum(char str[]) ;

 /**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int function_esSoloLetras(char str[]) ;

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int function_esAlfaNumerico(char str[]) ;

/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int function_esTelefono(char str[]) ;

/** \brief Solicita un texto
 *
 * \param char array mensaje a mostrar.
 * \param  char array donde se guardara el mensaje ingresado.
 *
 */
void function_getString (char msj[],char input[]) ;

 /**
 * \brief Solicita un texto al usuario y lo devuelve validado.
 * \param char array mensaje a ser mostrado
 * \param char array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int function_getStringLetras(char msj[],char input[]) ;

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[]) ;

 /**
 * \brief Solicita un texto numérico al usuario y lo devuelve valido si es solo numeros.
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int function_getStringNumeros(char msj[],char input[]) ;

/** \brief Menu de opciones
 *
 * \return Opcion ingresada
 *
 */
int menu ( ) ;

/** \brief Menu de opciones para modificar el sempleado
 *
 * \return Opcion ingresada
 *
 */
int menuModificar ();

/** \brief Menu de opciones de los empleados
 *
 * \return Opcion ingresada
 *
 */
int menuEmpleados ( );

int menuDeLosMenues ( );

void function_validName(char text[]);


/** \brief Permite al usuario ingresar un texto y lo devuelve en un nuevo espacio de memoria.
 * \param char* msg. Mensaje a ser impreso
 * \return Puntero a cadena de caracteres con texto ingresado. Se debe liberar con free().
 */
char* getDynamicString(char* msg) ;
