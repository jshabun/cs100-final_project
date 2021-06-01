#include "movie.hpp"
#include <iostream> 
#include <vector>
#include <string>

using namespace std;

string Movie::getMovieDirector() { 
   return this->director;
}

int Movie::getMovieYear() {
   return this->year;
}

double Movie::getMovieRating() {
   return this->rating; 
}

string Movie::getMovieTitle() {
   return this->title;
} 

vector<string> Movie::getMovieGenres() {
   return this->genres;
}

void Movie::addDirector(string dir) {
   this->director = dir; 
}

void Movie::addYear(int ye) {
   this->year = ye; 
}

void Movie::addRating(double rat) {
   this->rating = rat; 
}

void Movie::setTitle(string tit) {
   this->title = tit; 
}

void Movie::addGenre(string gen) {
   this->genres.push_back(gen); 
}

void Movie::setGenres(vector<string> gens) {
     this->genres = gens; 
}

void Movie::print() {
   cout << endl << this->title << endl << "Director: " << director << endl << "Year released: " << year << endl << "Rating: " << rating << endl << "Genres: "; 
   for(int i = 0; i < genres.size(); i++) {
	cout << genres.at(i) << " " ; 
   }
 return; 
}
