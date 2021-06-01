#include "movie.hpp"
#include "category.hpp"
#include "base.hpp"
#include "Scan.hpp"
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "boost/boost/tokenizer.hpp"

using namespace std;
using namespace boost;

vector<Movie*> Scan::getMovies() {
	return this->movies;
}

map<string, Movie*> Scan::getMovMap() {
		return this->movMap;
}

void Scan::setFilters(Strat* filters) {
		filter = filters;
}

void Scan::setMovies(vector<Movie*>movs) {
		this->movies = movs;
}

void Scan::sort() {
		filter->sort(this);
}

bool Scan::isMovie(string movName) {
		map<string, Movie*>::iterator tmp;
		tmp = movMap.find(movName);
		if(tmp == movMap.end()) {
			return false;
		}
		return true;
}

void Scan::scanMovies() {
		string line = "";
		string inFile = "IMDB-Movie-Data.csv";
		
		ifstream myCSV;
		myCSV.open(inFile);

		string movTitle = "";
		string director = "";
		string genre = "";
		int date;
		double rating;
		vector<string> genres;

		if(!myCSV.is_open()) {
			cout << "Error: Couldn't Open " << inFile << endl;
			return;
		}

		while(getline(myCSV, line)) {
			tokenizer<escaped_list_separator<char> > tok(line);
        	tokenizer<escaped_list_separator<char> >::iterator start = tok.begin();
        
        	Movie* curMovie = new Movie();

			movTitle = *start;
			start++;

			for(int i =0; i < start->size(); i++){
            	if(start->at(i) != ','){
                	genre +=  start->at(i);
            	}
            	if(start->at(i) == ','){
                	genres.push_back(genre);
                	genre = "";
           		}
        	}
        	genres.push_back(genre);
        	genre = "";
       		start++;

			director = *start;
			start++;

			date = stoi(*start);
    	    start++;

    	    rating = stod(*start);

			curMovie->setTitle(movTitle);
    	    curMovie->setGenres(genres);
	        curMovie->addDirector(director);
    	    curMovie->addYear(date);
	        curMovie->addRating(rating);

			movMap.emplace(movTitle, curMovie);
			movies.push_back(curMovie);
		
 			genres.clear();
	        movTitle = "";
    	    date = 0;
    	    rating = 0;
		
    		}
        
    	myCSV.close();

    	return;
}
