// 924-iofile-Exercice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>

#include "datas.h"


int main()
{

	const std::string file_name = ".scores";

	bool exit = true;
	std::string current_name;
	int idx_player;

	LoadScores(file_name);

	// Prompt 
	std::cout << "What's your name ?" << std::endl;
	std::cin >> current_name;

	if (HasPlayer(current_name, idx_player))
	{
		std::cout << "Welcome back , " << players[idx_player].name << '\n';
	}
	else
	{
		std::cout << "New challenger incoming, " << players[idx_player].name << '\n';
	}

	do {

		// On attend une touche
		system("pause");

		// On compte et on affiche
		players[idx_player].score++;
		std::cout << players[idx_player].score << '\n';

		// 1 chance sur 10 de quitter
		exit = (rand() % 10 == 0 ? false : true);

	} while (exit);

	std::cout << "EXIT the clicker" << '\n';

	SaveScores(file_name);

 }


