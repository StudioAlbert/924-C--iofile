// 924-iofile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <string>

enum class data_order
{
	idx_x = 1,
	idx_y = 2,
	idx_type = 0
};

int main()
{
	int output_x = 50;
	int output_y = 123;
	std::string output_type = "house";

	std::string file_name = "city.map";

	// ---------------------------------------------------------------------------
	std::ofstream out_file;

	out_file.open(file_name);

	out_file << output_type << '\n';
	out_file << output_x << '\n';
	out_file << output_y << '\n';
	out_file << 'new_building' << '\n';

	out_file.close();


	// ---------------------------------------------------------------------------
	std::ifstream in_file;
	std::string line;
	in_file.open(file_name);

	int input_x, input_y;
	std::string input_type;

	// ouverture fichier
	std::cout << "Lecture des données" << '\n';
	int idx = 0;
	while (in_file >> line)
	{
		switch (idx)
		{
		case data_order::idx_type:
			input_type = line;
			break;
		case data_order::idx_x:
			input_x = std::stoi(line);
			break;
		case data_order::idx_y:
			input_y = std::stoi(line);
			break;
		default:
			std::cout << "too much datas" << std::endl;
			break;
		}
		idx++;
		std::cout << line;
	}

	in_file.close();

	return EXIT_SUCCESS;

}

