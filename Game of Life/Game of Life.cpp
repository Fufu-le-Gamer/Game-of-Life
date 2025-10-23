

#include <iostream>
#include <chrono>
#include<thread>
#include <conio.h>

//Compte le tous les voisins des cellules vivantes
int countNeighbors(int* grid, int x, int y, int SizeX, int SizeY) {
    int count = 0;
    for (int vx = -1; vx <= 1; vx++) {
        for (int vy = -1; vy <= 1; vy++) {
            if (vx == 0 && vy == 0) continue;
            int nx = x + vx;
            int ny = y + vy;
            if (nx >= 0 && nx < SizeX && ny >= 0 && ny < SizeY) {
                if (grid[nx * SizeY + ny] == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}
//Créer et parcoure la grille pour détecter les cellules vivantes et mortes
void displayGrid(int* grid, int SizeX, int SizeY) {
    for (int x = 0; x < SizeX; x++) {
        for (int y = 0; y < SizeY; y++) {
            if (grid[x * SizeY + y] == 1)
                std::cout << "[]";//Cellules vivantes
            else
                std::cout << ". ";//Cellules mortes
        }
        std::cout << "\n";
    }
    for (int y = 0; y < SizeY; y++) {
        std::cout << "--";//Séparation entre les grilles
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
    bool pause = false;
    float vitesse = 2.0f;
    bool reponse = true;

    while (reponse) {
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
            //Si j'appui sur "p" le jeu ce met en pause
            if (_kbhit()) {
                char touche = _getch();

                if (touche == 'p' || touche == 'P') {
                    pause = !pause;
                    if (pause) {
                        std::cout << "Jeu en pause" << "\n";
                        std::cout << "Appuyez sur 'P' pour reprendre.\n";
                    }
                    else {
                        std::cout << "Jeu repris !\n";
                    }
                }
                //Si j'appuit sur "+" la vitesse de generation augmente, si j'appuit sur "-" elle diminue
                else if (touche == '+') {
                    if (vitesse > 0.1f) { // limite minimale
                        vitesse -= 0.1f;
                        std::cout << "Acceleration: " << vitesse << "s" << "\n";
                    }
                }
                else if (touche == '-') {
                    vitesse += 0.1f;
                    std::cout << "Ralentissement: " << vitesse << "s" << "\n";
                }
            }
            if (pause) {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                continue;
            }
            //Génere la grille suivante toute les 2 seconde par défaut
            auto TimePoint2 = std::chrono::steady_clock::now();//2.0
            std::chrono::duration<float> Duration = TimePoint2 - TimePoint; //2.0
            if (Duration.count() >= vitesse) { //Toute les 2secs
                TimePoint = std::chrono::steady_clock::now();//2.0

                displayGrid(grid, SizeX, SizeY);
                //Génere une nouvelle grille avec les nouvelles cellules vivantes et mortes
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
                temps++;
            }
        }



        delete[] grid;
        delete[] nextGrid;

        grid = nullptr;
        nextGrid = nullptr;
        std::cout << "Voulez vous relancer une partie ?" << "\n";
        std::cout << "Appuyer sur 1 pour recommencer ou 0 pour arreter: ";
        std::cin >> reponse;
    }
}

