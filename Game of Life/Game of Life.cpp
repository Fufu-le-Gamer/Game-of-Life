// Game of Life.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <chrono>
#include <conio.h>


int main()
{
	int SizeX;
	int SizeY;
	int X;
	int Y;
	int index;
	int cellule_alive;
	int* grid = new int[SizeX * SizeY];

	std::cout << "Combien de cellules voulez vous en hauteur ?" << "\n";
	std::cin >> SizeX;
	std::cout << "Combien de cellules voulez vous en longueur ?" << "\n";
	std::cin >> SizeY;
	std::cout << "Combient de cellules vivantes voulez vous au départ ?" << "\n";
	std::cin >> cellule_alive;
	while (cellule_alive > 0) {
		cellule_alive--;
		if (cellule_alive > 1) {
			std::cout << "Quelles sont les coorrdonnees des cellulues vivantes ?" << "\n";
		}
		else {
			std::cout << "Quelles sont les coorrdonnees de la cellulue vivante ?" << "\n";
		}
		std::cout << "X: ";
		std::cin >> X;
		std::cout << "Y: ";
		std::cin >> Y;
	}
	
	
	int* grid = new int[SizeX * SizeY];
	

	for (int x = 0; x < SizeX; x++) {
		for (int y = 0; y < SizeY; y++) {
			grid[x * SizeY + y] = 0;
		}
	}
	index = X * SizeY + Y;
	grid[index] = 1;


	for (int x = 0; x < SizeX; x++) {
		for (int y = 0; y < SizeY; y++) {
			if (grid[x * SizeY + y] == 0) {
				std::cout << ". ";
			}
			else {
				std::cout << "[]";
			}
			
		}
		std::cout << "\n";
	}
	
	delete[] grid;
	grid = nullptr;


}


