/*
 * input.h
 *
 *  Created on: 25 jun. 2021
 *      Author: mateo
 */

#ifndef INPUT_H_
#define INPUT_H_

int getInt(char* msg);
float getFloat(char* msg);
char getChar(char* msg);
int getSON(char* msg);
int getString(char* msg, char* destino);
int esNumerica(char* cadena);
int esAlfanumerica(char* cadena);
int esEspaciado(char* cadena);

#endif /* INPUT_H_ */
