// 924-iofile-Exercice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{

	srand(time(NULL));

	int score = 0;
	bool exit = true;

	// TODO : Lire le score dans le fichier

	do {
		// On attend une touche
		system("pause");

		// On compte et on affiche
		score++;
		std::cout << score << '\n';

		// 1 chance sur 10 de quitter
		exit = (rand() % 10 == 0 ? false : true);

	} while (exit);

	std::cout << "EXIT the clicker" << '\n';

	// TODO : Ecrire le score dans le fichier

}


