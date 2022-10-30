
#ifndef VALIDACIONESTP2_H_
#define VALIDACIONESTP2_H_



#endif /* VALIDACIONESTP2_H_ */

int esNumerica(char* cadena);
int getInt(int* pResultado);
int myGets(char* cadena, int longitud);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNombre(  char *pNombre, int limite, char *mensaje, char *mensajeError, int reintentos);
int isValidNombre(char *pBuffer, int limite);
int getString(char *pBuffer, int limite);
int esFlotante(char *str);
int getFloat(float* pResult);
int input_GetFloat(float* pResult, char* message, char* errorMessage, float min, float max, int retries);
int confirmarSalida(char* pSalida);

