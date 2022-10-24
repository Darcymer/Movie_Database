// Movie_Database.cpp : This file contains the 'main' function. Program execution begins and ends there



// This is the movie database! This C++ program will utilize how to make and sort movies.


// Darcy Merilan
// Video demo: https://youtu.be/PrJzGVggX2E


// all systems that will be needed for the code
#include <iostream>
#include "movie.h"
#include <list> 
#include <string>
#include <algorithm> 
#include <numeric> 
// Allows for random systems to be used 
#include <random>


// all std dictionaries needed
using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::list;
using std::string;
using std::for_each;
using std::remove_if;
using std::accumulate;
using std::transform;
//allows for us to implement a random device based on certain criteria
using std::random_device;


//shows menu
void display_menu();

//creates a movie list that is using iterators to move and sort the list
list<Movie>::iterator find_by_movienum(list<Movie>& movie_list);

int main()
{
    //List that will store all the movies and any information we give them
    list<Movie> mymovies;

    // the choice is set to one so the movie list is 
    int inserter = 1;

    //while the insert is not 0, do this
    while (inserter)
    {
        display_menu();
        cin >> inserter;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //switch...case is used for fast results back from the menu.
        switch (inserter) {

        //Displays mymovies list from what was added so far
        case 1:
        {
            for_each(mymovies.begin(), mymovies.end(), 
                [](auto& mymovies) {
                    mymovies.display(); 
                });
            break;
        }

        //Adds a movie to the mymovies list
        case 2:
        {
            Movie moviename;
            moviename.initialize();
            mymovies.push_back(moviename);
            cout << "Movie Added\n";
            break;
        }

        // Locates a movie by its ID
        case 3:
        {
            list<Movie>::iterator it = find_by_movienum(mymovies);
            if (it != mymovies.end())
                it->display();
            else
            {
                cout << "We could not find your movie\n";
            }
            break;
        }

        // Deletes a movie from the list
        case 4:
        {
            string input;
            int id = 0;
            cout << "What Movie are you deleting? ";
            getline(cin, input);
            id = std::stof(input);
            auto dier = remove_if(mymovies.begin(), mymovies.end(), [id](auto& mymovies) {
                return id == mymovies.get_movie_number();
                });
            mymovies.erase(dier);
            break;
        }

        //adds movie info from mInfo into the movie id
        case 5:
        {
            list<Movie>::iterator it = find_by_movienum(mymovies);
            if (it != mymovies.end())
                it->add_Info();
            else
            {
                cout << "We could not find your movie, please add in the movie to be added to the list\n";
            }
            break;
        }

        //adds a Box office amount from Boxoffice to the movie id
        case 6:
        {
            list<Movie>::iterator it = find_by_movienum(mymovies);
            if (it != mymovies.end())
                it->add_balancer();
            else
            {
                cout << "We could not find your movie, please add in the movie to be added to the list\n";
            }
            break;
        }

        // this is something new that i have learned... the random functionality. We the user presses 7 the following code will be run...
        case 7:
        {
            list<Movie>::iterator it = find_by_movienum(mymovies);
            if (it != mymovies.end()) {
                // creates a random interger that will work as a score for the movie
                random_device review_score;

                // this dictionary will show a distribution between the numbers 1-10
                std::uniform_int_distribution<int> userat(0, 10);

                // We are seperating the score depending on the random number, so if it is equal or higher than 7, it produces a message, but if it is lower than 7, it produces another message
                cout << "One user reviewed this as ";
                if (userat(review_score) >= 7)
                {
                    // this code will use the uniform distributor as a random number thanks to the random device, and will allow for changes to the score
                    cout << userat(review_score) << "\n That's a Pretty Good Movie, would watch again\n";
                }
                else
                {
                    // this code will use the uniform distributor as a random number thanks to the random device, and will allow for changes to the score
                    cout << userat(review_score) << "\n That was certainly something but... i didnt like this movie \n";
                }
            }
            else
            {
                cout << "We could not find your movie, please add in the movie to be added to the list\n";
            }
            break;
        }

        //when we press 0 we break the loop and end the code
        case 0:
            break;

        //error handeling
        default:
            cout << "Whoops! That ain't right... try again!\n";
            continue;
        }
    }
}

// menu that will be shown to user
void display_menu()
{
    std::cout <<"\nWelcome to the Movie Manager, where you can write all your favorite things about a Movie\n"
        << "\nThe Movie Manager:\n"
        << "1. Display Movie Information\n"
        << "2. Add A Movie\n"
        << "3. Find Movie by ID\n"
        << "4. Remove A Movie\n"
        << "5. Add Movie information to an selected Movie\n"
        << "6. Add how much the movie made in the Box Office \n"
        << "7. See Someones review score of your movie\n"
        << "0. Quit Movie Manager\n"
        << "Your Choice: ";
}

// loops through a list using iterators
list<Movie>::iterator find_by_movienum(list<Movie>& movie_listings)
{

    string input;
    cout << "What is the Movie ID #: ";
    getline(cin, input);
    int id = std::stoi(input);

    list<Movie>::iterator it;
    for (it = movie_listings.begin(); it != movie_listings.end(); it++)
    {
        if (it->get_movie_number() == id)
        {
            return it;
        }
    }
    return it;
}