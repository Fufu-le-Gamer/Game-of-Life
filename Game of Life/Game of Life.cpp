// Game of Life.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <chrono>
#include <conio.h>

int countNeighbors(int* grid, int x, int y, int SizeX, int SizeY) {
    int count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < SizeX && ny >= 0 && ny < SizeY) {
                if (grid[nx * SizeY + ny] == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

void displayGrid(int* grid, int SizeX, int SizeY) {
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
    std::cout << "\n";
}

int main() {
    int SizeX;
    int SizeY;
    int X;
    int Y;
    int cellule_alive;
    int generations;
    int temps = 0;

    std::cout << "Combien de cellules voulez-vous en hauteur ?" << "\n";
    std::cin >> SizeX;
    std::cout << "Combien de cellules voulez-vous en longueur ?" << "\n";
    std::cin >> SizeY;

    int* grid = new int[SizeX * SizeY];
    int* nextGrid = new int[SizeX * SizeY];

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
        std::cout << "X (0 a " << SizeX - 1 << ") : ";
        std::cin >> X;
        std::cout << "Y (0 a " << SizeY - 1 << ") : ";
        std::cin >> Y;

        if (X >= 0 && X < SizeX && Y >= 0 && Y < SizeY) {
            grid[X * SizeY + Y] = 1;
        }
        else {
            std::cout << "Coordonnees invalides, cellule ignoree." << "\n";
        }
    }

    std::cout << "Combien de generations voulez-vous faire ?" << "\n";
    std::cin >> generations;


    auto TimePoint = std::chrono::steady_clock::now(); //0
    while (temps < generations)
    {
        auto TimePoint2 = std::chrono::steady_clock::now();//2.0
        std::chrono::duration<float> Duration = TimePoint2 - TimePoint; //2.0
        if (Duration.count() >= 1.0f) { //Toute les 2secs
            TimePoint = std::chrono::steady_clock::now();//2.0
        

            std::cout << "\nGeneration " << temps + 1 << ":\n";
            displayGrid(grid, SizeX, SizeY);

            for (int x = 0; x < SizeX; x++) {
                for (int y = 0; y < SizeY; y++) {
                    int neighbors = countNeighbors(grid, x, y, SizeX, SizeY);
                    int index = x * SizeY + y;

                    if (grid[index] == 1) {
                        if (neighbors < 2 || neighbors > 3)
                            nextGrid[index] = 0;
                        else
                            nextGrid[index] = 1;
                    }
                    else {
                        if (neighbors == 3)
                            nextGrid[index] = 1;
                        else
                            nextGrid[index] = 0;
                    }
                }
            }

            std::swap(grid, nextGrid);
            temps++ ;

        }
    }
        
    

    delete[] grid;
    delete[] nextGrid;

    grid = nullptr;
    nextGrid = nullptr;
}

