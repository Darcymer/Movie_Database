#pragma once

//elements used for this file
#include <string>
#include <iostream>
#include <memory>


//The purpose of this class is to add in a boxoffice float account to the movie id when called.
class Boxoffice
{
private:
	float BOearnings;

public:
	Boxoffice();
	void initialize();
	void display() const; 
	float get_BOearnings() const;
};

