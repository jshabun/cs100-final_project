#ifndef __MENU_HPP__
#define __MENU_HPP__

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "movie.hpp"
#include "base.hpp"
#include "category.hpp"
#include "Scan.hpp"
#include "display.hpp"
#include "mainFunctions.hpp"

using namespace std;

void intro();
void menu();
void option1(Scan* title);
void option2(Scan* title);
void option3(Scan* title);
void option4(Scan* title);
void option5(Scan* title);
int quit();

#endif //__MENU_HPP__
