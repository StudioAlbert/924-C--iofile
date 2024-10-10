// 924-iofile-Exercice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <string>

void LoadScore(const std::string& file_name, int& score)
{
	// TODO : Lire le score dans le fichier
	std::ifstream file(file_name);			
	
	if (file.is_open()) {					// Si le fichier est ouvert
		std::string score_string;

		file >> score_string;				// Recuperation en string
		score = std::stoi(score_string);	// Passage en entier
		file.close();						// Fermeture du fichier
	}
}

void SaveScore(const std::string& file_name, int score)
{
	// TODO : Ecrire le score dans le fichier
	std::ofstream file(file_name);

	if(file.is_open())	// Si le fichier est ouvert
	{
		file << score;	// Ecriture du score
		file.close();	// Fermeture du fichier
	}
}

int main()
{

	const std::string file_name = ".scores";

	srand(time(NULL));

	int score_main = 0;
	bool exit = true;

	LoadScore(file_name, score_main);

	do {

		// On attend une touche
		system("pause");

		// On compte et on affiche
		score_main++;
		std::cout << score_main << '\n';

		// 1 chance sur 10 de quitter
		exit = (rand() % 10 == 0 ? false : true);

	} while (exit);

	std::cout << "EXIT the clicker" << '\n';

	SaveScore(file_name, score_main);

}


