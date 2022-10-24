#include "mInfo.h"

#include <iostream>


void mInfo::initialize()
{
    std::cout << "\nWho Directed the movie: ";
    std::getline(std::cin, Director);

    std::cout << "When was the Release Date (Month, Year): ";
    std::getline(std::cin, Release_date);

    std::cout << "What is the movie about? ";
    std::getline(std::cin, Synopsis);

    std::cout << "Who plays in the movie? ";
    std::getline(std::cin, Actors);

    std::cout << "What studio is responcible for the movie: ";
    std::getline(std::cin, Studio);
}

void mInfo::display() const
{
    std::cout << "\n Director: " << Director << "\n Release Date: " << Release_date
        << "\n Movie Synopsis: " << Synopsis << "\n Actors Listed: " << Actors
        << "\n Studio Responcible: " << Studio << std::endl;
}