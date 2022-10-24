#pragma once

#include "mInfo.h"
#include "Boxoffice.h"
#include <string>
#include <iostream>
#include <memory>

using std::string;

class Movie
{
	
private:
	int movienum;
	string movietitle;
	static int new_movienum; 

	//adds in a movie 
	std::shared_ptr<mInfo> movie_info;
	std::shared_ptr<Boxoffice> earnings;
	
public:
	Movie();

	void initialize();
	void display() const;
	int get_movie_number() const;
	void add_Info();
	void add_balancer();
};

