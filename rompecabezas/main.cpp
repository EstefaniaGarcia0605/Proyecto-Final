#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <C:\\rompecabezas\\funciones.h>

using namespace std;

int main() 
{	
	int semilla;
	cout << "Ingrese la semilla que desea para la ejecucion ";
	cin >> semilla;

	srand(semilla);
	int** matriz = inicializar();
	int puntaje = 0;
	int movimientos = 0;
	
	posicionact(matriz, 0, 0);
	
	do {
	    matriz = mover(matriz);
	    puntaje = obtenerPuntaje(matriz);
	    posicionact(matriz, puntaje, ++movimientos);
	} while (!estaDesordenado(puntaje));  
    
    return 0;
}
