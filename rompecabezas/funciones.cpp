#include<time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iostream>

using namespace std;

// 1. Función para inicializar la matriz
int** inicializar()
{
    int** matriz = 0;
    matriz = new int*[3];
    int contador = 1;

    for (int i = 0; i < 3; i++)
    {
        matriz[i] = new int[3];

        for (int j = 0; j < 3; j++)
        {
            matriz[i][j] = contador;
            contador++;
        }
    }
      
    matriz[2][2] = 0;

    return matriz;
}

// 2. Función de impresión en pantalla de la posición actual
void posicionact(int** matriz, int puntaje, int no)
{	
	
	
	if (no == 0) {
		ofstream archivo("resultado.txt");
		archivo << "Inicio" << endl << endl;
		
		for (int i=0; i<3;i++) 
		{
			for (int j=0;j<3;j++) {
				cout<<matriz[i][j]<<" ";
				archivo<<matriz[i][j]<<" ";
			}
			cout << endl;
			archivo<<endl;
		}
		cout << endl;
		archivo << endl;
		archivo.close();
		return;
	}
	
	ofstream archivo("resultado.txt", fstream::app);
	
	cout << "Movimiento: ";
	archivo << "Movimiento: ";
	
	for (int i=0; i<3;i++) 
	{
		for (int j=0;j<3;j++) {
			if (matriz[i][j] == 0) {
				cout << i << "," << j << " ";
				archivo << i << "," << j << " ";
			}
		} 
	}

	cout << "No. " << no << endl << "Puntaje: " << puntaje << endl;
	archivo << "No. " << no << endl << "Puntaje: " << puntaje << endl;

	for (int i=0; i<3;i++) 
	{
		for (int j=0;j<3;j++) {
			cout<<matriz[i][j]<<" ";
			archivo<<matriz[i][j]<<" ";
		}
		cout << endl;
		archivo<<endl;
	}
	cout << endl;
	archivo << endl;
	
	archivo.close();
}

// 3. Función de generación de movimientos

int** mover(int** matriz)
{	
	int ok = false;
	
	while(!ok) {
		//Escoger una pieza aleatoriamente
		int x = rand() % 3;
		int y = rand() % 3;
		
		
		
		//verificar validez e intercambiar 
		if (matriz[x][y] == 0) continue;
		
		if (x + 1 < 3) {
			if (matriz[x + 1][y] == 0) {
				matriz[x + 1][y] = matriz[x][y];
				matriz[x][y] = 0;
				ok = true;
			} 
		}  
		
		if (x - 1 >= 0) {
			if (matriz[x - 1][y] == 0) {
				matriz[x - 1][y] = matriz[x][y];
				matriz[x][y] = 0;
				ok = true;
			} 
		}
		
		if (y + 1 < 3) {
			if (matriz[x][y + 1] == 0) {
				matriz[x][y + 1] = matriz[x][y];
				matriz[x][y] = 0;
				ok = true;
			} 
		}
		
		if (y - 1 >= 0) {
			if (matriz[x][y - 1] == 0) {
				matriz[x][y - 1] = matriz[x][y];
				matriz[x][y] = 0;
				ok = true;
			} 
		} 
	}
	
	return matriz;
} 

// 4. Función que retorna el puntaje de la posición actual
int obtenerPuntaje(int** matriz)
{
	int puntaje = 0;
	int contador = 1;
	
    
	for(int i = 0; i < 3; i++)
	 {
		for(int j = 0; j < 3; j++) 
		{
			if (i == 2 && j == 2) 
			{
				if (matriz[2][2] != 0)
				{
					puntaje++;
				}
			} 
				else if (matriz[i][j] != contador ) 
				{
					puntaje++;
				} 
				
			contador++;
		}
	}
	
	return puntaje;
}

// 5. Función que verifica si el tablero está desordenado 

bool estaDesordenado(int puntaje)
{
    return puntaje >= 8;
}
