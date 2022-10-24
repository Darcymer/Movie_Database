#pragma once

//elements used for this file
#include <string>
#include <iostream>

//dictonaries used
using std::string;


//The puropse for this class is to build information that will be given to a movie id
class mInfo
{
private:

	string Director;
	string Release_date;
	string Synopsis;
	string Actors;
	string Studio;

public:
	mInfo() : Director(""), Release_date(""), Synopsis(""), Actors(""), Studio("") {};
	void initialize();
	void display() const;
};

