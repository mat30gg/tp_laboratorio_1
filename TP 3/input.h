/*
 * input.h
 *
 *  Created on: 15 jun. 2021
 *      Author: mateo
 */

#ifndef INPUT_H_
#define INPUT_H_

int getInt(char* msg);
float getFloat(char* msg);
char getChar(char* msg);
int getSON(char* msg);
int getString(char* msg, char* destino);
int getStringSize(char* cadena);
int getStringAll(char* msg, char* destino);
int getStringNum(char* msg, char* destino);
int esNumerica(char* cadena);
int esFlotante(char* cadena);
int esAlfanumerica(char* cadena);
int esEspaciado(char* cadena);

#endif /* INPUT_H_ */
