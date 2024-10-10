#ifndef DATAS_H
#define DATAS_H

#include <fstream>
#include <string>
#include <vector>

struct Player
{
	std::string name;
	int score;
};

static std::vector<Player> players;


//#define kDelimiter ':'
//const char kDelimiter = ':';
constexpr char kDelimiter = ':';


inline bool HasPlayer(const std::string& player_name, int& idx_player_found)
{

	for(int i = 0; i < players.size(); i++)
	{
		if (players[i].name == player_name)
		{
			// Player found !!!!!!!!!!!!!!!!!!!
			idx_player_found = i;
			// say yes
			return true;
		}

	}

	// Player not found
	players.push_back({ player_name, 0 });
	idx_player_found = players.size() - 1;

	return false;

}

inline void LoadScores(const std::string& file_name)
{
	// TODO : Lire le score dans le fichier
	std::ifstream file(file_name);

	if (file.is_open()) {					// Si le fichier est ouvert

		std::string score_string;

		while (getline(file, score_string))
		{
			int pos = score_string.find(kDelimiter);

			std::string name = score_string.substr(0, pos);
			int score = std::stoi(score_string.substr(
				pos + 1, 
				score_string.size() - pos - 1)
			);

			players.push_back({ name, score });

		}

		file.close();						// Fermeture du fichier

	}
}

inline void SaveScores(const std::string& file_name)
{
	// TODO : Ecrire le score dans le fichier
	std::ofstream file(file_name);

	if (file.is_open())	// Si le fichier est ouvert
	{
		for(Player& p : players)
		{
			file << p.name << kDelimiter << p.score << '\n';
		}

		file.close();	// Fermeture du fichier
	}
}


#endif // DATAS_H
