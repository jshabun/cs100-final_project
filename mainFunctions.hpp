#ifndef __MAINFUNCTIONS_HPP__
#define __MAINFUNCTIONS_HPP__

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "movie.hpp"
#include "base.hpp"
#include "category.hpp"
#include "Scan.hpp"
#include "display.hpp"
#include "menu.hpp"

using namespace std;

void recommend(vector<Movie*> vals, string movie_title, map<string, Movie*> movieMap);
int divide(vector<Movie*> &vals, int left, int right);
void movieSort(vector<Movie*> &vect);
void quickSort(vector<Movie*> &vals, int left, int right);

#endif //__MAINFUNCTIONS_HPP__
