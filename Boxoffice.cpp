#include "Boxoffice.h"
#include <iostream>

Boxoffice::Boxoffice() : BOearnings(0){}

void Boxoffice::initialize()
{
	std::string input;
	std::cout << "What is your balance?  ";
	std::getline(std::cin, input);
	BOearnings = std::stof(input);
}
void Boxoffice::display() const
{
	std::cout 
		<< " Box Office Earnings: $" << std::fixed << BOearnings
		<< std::endl;
}

float Boxoffice::get_BOearnings() const
{
	return BOearnings;
}

