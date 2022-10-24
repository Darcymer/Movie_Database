#include "movie.h"

#include <iostream>


int Movie::new_movienum = 1; 

Movie::Movie() : movienum(0), movie_info(nullptr) {}


void Movie::initialize()
{
	movienum = new_movienum++;

	std::cout << "What is The Movie Title?  ";
	std::getline(std::cin, movietitle);
}


void Movie::display() const
{
	std::cout << "\nID: " << movienum
		<< " Movie: " << movietitle
		<< std::endl;


	//These if and else if stayements show what to do when one case dosent match with another, works as a sort of error handeling

	if (movie_info != nullptr && earnings != nullptr)
	{
		movie_info ->display();
		earnings->display();
	}
	else if(earnings != nullptr && movie_info == nullptr) {
		earnings->display();
	}
	else if (earnings == nullptr && movie_info != nullptr) {
		movie_info->display();
	}
}
int Movie::get_movie_number()const
{
	return movienum;
}


// These next 2 void methods bring in mInfo and Boxoffice into the main movie file
void Movie::add_Info()
{
	movie_info = std::make_shared<mInfo>();
	movie_info->initialize();
}
void Movie::add_balancer()
{
	earnings = std::make_shared<Boxoffice>();
	earnings->initialize();
}