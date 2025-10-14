// Game of Life.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
void afficher_cellule_dead(int SizeX, int SizeY) {
	
	int* grid = new int[SizeX * SizeY];

	for (int X = 0; X < SizeX; X++) {

		for (int Y = 0; Y < SizeY; Y++) {
			std::cout << ". ";
		}
		std::cout << "\n";
	}
	delete[] grid;
	grid = nullptr;
}
void afficher_cellule_alive(int SizeX, int SizeY) {

}

int main()
{
	int SizeX;
	int SizeY;
	int X;
	int Y;
	int index;
	index = X * SizeY + Y;

	std::cout << "Combien de cellules voulez vous en hauteur ?" << "\n";
	std::cin >> SizeX;
	std::cout << "Combien de cellules voulez vous en longueur ?" << "\n";
	std::cin >> SizeY;
	std::cout << "Quelles sont les coorrdonnées de la cellulue vivante ?" << "\n";
	
	int* grid = new int[SizeX * SizeY];

	for (int X = 0; X < SizeX; X++) {

		for (int Y = 0; Y < SizeY; Y++) {
			std::cout << ". ";
		}
		std::cout << "\n";
	}
	delete[] grid;
	grid = nullptr;


}


