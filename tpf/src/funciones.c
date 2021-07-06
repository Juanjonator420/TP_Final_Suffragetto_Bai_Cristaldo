#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include"declaraciones.h"
#include"declaracionesgtk.h"

#include<gtk/gtk.h>

//funcion para verificacion del user input
int input_verificacion(char t[TAM_TABLERO][TAM_TABLERO], int *x, int *y, int faccion){

	int i, j;
	i = *x;
	j = *y;

	if (t[i][j]=='*'||t[i][j]=='-'|| t[i][j]=='H'|| t[i][j]=='M'||t[i][j]=='C'||t[i][j]=='L'){ // en caso de que se ingrese las coordenadas de una casilla vacia
		return 0;
	}
	if(faccion==1){ //limitacion a piezas suffragetto
		if(t[i][j]=='p' || t[i][j]=='P'){
			return 0;
		}
	}
	if(faccion==2){ //limitacion a piezas policia
		if(t[i][j]=='s' || t[i][j]=='S'){
			return 0;
		}
	}
	return 1;
}

int input_verificacion_pc(char t[TAM_TABLERO][TAM_TABLERO], int *x, int *y, int faccion){

	int i, j;
	i = *x;
	j = *y;

	if (t[i][j]=='*'||t[i][j]=='-'|| t[i][j]=='H'|| t[i][j]=='M'||t[i][j]=='C'||t[i][j]=='L'){ // en caso de que se ingrese las coordenadas de una casilla vacia
		return 0;
	}
	if(faccion==1){ //limitacion a piezas suffragetto
		if(t[i][j]=='s' || t[i][j]=='S'){
			return 0;
		}
	}
	if(faccion==2){ //limitacion a piezas policia
		if(t[i][j]=='p' || t[i][j]=='P'){
			return 0;
		}
	}
	return 1;
}
