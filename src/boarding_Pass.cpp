#include "../include/boarding_Pass.h"
#include <iostream>

std::vector<std::string> decodeInput(std::fstream &file)
{
	std::string line;
	std::vector<std::string> pass_data;
	while (getline(file, line))
	{
		if (!line.empty())
		{
			pass_data.push_back(line);
		}
		else
		{
			break;
		}
	}
	return pass_data;
}

uint32_t BoardingPass::changeUpper(){
	return  lower + (upper - 1 - lower) / 2;
}

uint32_t BoardingPass::changeLower(){
	 return lower + (upper - 1 - lower) / 2 + 1;
}

uint32_t BoardingPass::changeR(){
	return l + (r - 1 - l) / 2;
}

uint32_t BoardingPass::changeL(){
	 return l + (r + 1 - l) / 2;
}

void BoardingPass::rowReveal(std::string first)
{
	for (int i = 0; i < int(first.size()); i++)
	{
		if (first.at(i) == 'F')
			upper = changeUpper();
		else 
			lower = changeLower();

		row = (lower == upper) ? upper : row;
	}
}

void BoardingPass::columnReveal(std::string first)
{
	for (int i = 0; i < int(first.size()); i++)
	{
		if (first.at(i) == 'R')
			l = changeL();
		else
			r = changeR();
		column = (l == r) ? r : column;
	}
}
int decodeSeat(std::string i)
{
	std::string first, second;
	BoardingPass object;

	first = i.substr(0, i.size() - 3);
	second = i.substr(i.size() - 3, i.size());
	object.rowReveal(first);
	object.columnReveal(second);
	
	int seat = 8 * object.row + object.column;
	return seat;
}