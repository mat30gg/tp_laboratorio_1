/** \brief Solicita el ingreso del valor A y lo retorna al valor x*/
int IngresoDeValorA();
/** \brief Solicita el ingreso del valor B y lo retorna al valor y*/
int IngresoDeValorB();
/** \brief Imprime los valores procesados por la funcion CalcularOperaciones
 *
 * \param int x
 * \param int y
 * \param int resultados[]
 * \param float resultadoDiv[]
 */
void InformarResultados(int, int, int[], float[]);
/** \brief Procesa los datos ingresados A y B utilizando las operaciones
 *
 * \param int x
 * \param int y
 * \param int resultados[] para guardar los resultados de las operaciones
 * \param float resultadoDiv[] para guardar un valor unico de tipo float
 */
void CalcularOperaciones(int, int, int[], float[]);
/** \brief recibe dos valores int y retorna su suma*/
int Suma(int, int);
/** \brief recibe dos valores int y retorna su resta*/
int Resta(int, int);
/** \brief recibe dos valores int y retorna la division de*/
float Division(int, int);
/** \brief recibe dos valores int y retorna su producto*/
int Producto(int, int);
/** \brief recibe un valor y retorna su factorial*/
int Factorial(int);
