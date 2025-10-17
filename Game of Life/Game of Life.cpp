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
	int cellule_alive;

	std::cout << "Combien de cellules voulez-vous en hauteur ?" << "\n";
    std::cin >> SizeX;
	std::cout << "Combien de cellules voulez-vous en longueur ?" << "\n";
    std::cin >> SizeY;

    int* grid = new int[SizeX * SizeY];

    for (int i = 0; i < SizeX * SizeY; i++) {
        grid[i] = 0;
    }

    std::cout << "Combien de cellules vivantes voulez-vous au depart ?" << "\n";
    std::cin >> cellule_alive;

    for (int i = 0; i < cellule_alive; i++) {
        if (cellule_alive > 1) {
            std::cout << "Coordonnees des cellules vivantes " << i + 1 << " :\n";
        }
        else {
            std::cout << "Coordonnees de la cellule vivante " << i + 1 << " :\n";
        }
        std::cout << "X (0 a " << SizeX - 1 << "): ";
        std::cin >> X;
        std::cout << "Y (0 a " << SizeY - 1 << "): ";
        std::cin >> Y;

        if (X >= 0 && X < SizeX && Y >= 0 && Y < SizeY) {
            grid[X * SizeY + Y] = 1;
        }
        else {
            std::cout << "Coordonnees invalides, cellule ignoree.\n";
        }
    }
    for (int x = 0; x < SizeX; x++) {
        for (int y = 0; y < SizeY; y++) {
            if (grid[x * SizeY + y] == 1)
                std::cout << "[]";
            else
                std::cout << ". ";
        }
        std::cout << "\n";
    }
    for (int y = 0; y < SizeY; y++) {
        std::cout << "--";
    }
    delete[] grid;
    grid = nullptr;
}

