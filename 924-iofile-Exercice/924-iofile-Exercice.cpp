// 924-iofile-Exercice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <string>

void LoadScore(const std::string file_name, int& score)
{
	// TODO : Lire le score dans le fichier
	std::ifstream file(file_name);			
	
	if (file.is_open()) {
		std::string score_string;

		file >> score_string;				// récupération en string
		score = std::stoi(score_string);	// Passage en entier
		file.close();						// Fermeture du fichier}
	}
}

void SaveScore(const std::string file_name, int score)
{
	// TODO : Ecrire le score dans le fichier
	std::ofstream file(file_name);

	if(file.is_open())
	{
		file << score;
		file.close();
	}
}

int main()
{

	const std::string file_name = ".score";

	srand(time(NULL));

	int score = 0;
	bool exit = true;

	LoadScore(file_name, score);

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

	SaveScore(file_name, score);

}


