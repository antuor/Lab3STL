#pragma once
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
//Проверка кодировки
#define Strings std::vector <std::string>

void CompareOfString()
{
	Strings String; 
	std::map<char, Strings> Text;
	try 
	{
		std::ifstream fin("input.txt"); 
		if (!fin.is_open()) 
			std::cout << "Error while opening the file\n"; 
		else
		{
			std::string symb;
			while (std::getline(fin, symb))
			{
				Text[tolower(symb[0])].insert(Text[tolower(symb[0])].end(), symb);
			}
			symb.clear();
			fin.close();
			std::ofstream fout("output.txt");
			for (auto it = Text.begin(); it != Text.end(); it++)
			{
				std::sort((*it).second.begin(), (*it).second.end());
				for (int i = 0; i < (*it).second.size(); i++) 
				{
					fout << (*it).second[i] << std::endl;
				}
			}
			fout.close();
		}
	}

	catch (std::bad_alloc) {
		std::cout << "Could not allocate memory";
	}
}