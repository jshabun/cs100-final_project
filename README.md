# Movie Recommender
 

 Authors: [Laura Lopez](https://github.com/laura-stack), [Joshua Shabun](https://github.com/jshabun), [William Mayuga](https://github.com/Aguyam1)
 
 
## Project Description:
In this application movies are organized into categories and subcategories to represent their genres and subgenres respectively. The application allows displaying movies under different categories/subcategories. It also allows adding and removing movies, categories and sub-categories. A user can provide a name of a movie that he/she likes and the application can recommend a list of movies that the user might like. Different recommendation algorithms can be implemented (e.g. based on the movie genre, director, actors ) and the resulting recommendations can also be sorted based on their rating, release date, etc.

Creating a movie recommender seemed interesting to us due to our profound love of movies. It seemed like a project we are all eager to create.

### Langauges/Tools/Technologies:
* `Valgrind` - an instrumentation framework for building dynamic analysis tools   (assists in finding and checking memory leaks)
* `C++` - the main programming language that will be utilized in this project.
* `Git/Github` - git is a local version control program that interfaces with Github, a remote repository.
* `GoogleTest` - a testing framework for C++ code
* `CMake`- allows for easier compilation and testing
* `boost` - a c++ library used for extending c++ capabilites. used in this program for parsing csv file data.

### I/O:
* `input`: movie title, genre, director, release date, rating
* `output`: sorted list of recommendations based on input and sorting selection

### Design Patterns:
* `Composite` - This structural pattern composes objects in terms of a tree structure to represent part as well as a whole hierarchy. Since a movie has multiple aspects of which can be a searchable category, it’ll be difficult to group different movies together based on that.  With this, we can "branch" out from an inputted movie title and compare it with recommended movies to the user based on a related genre, director, and other comparable aspects. Therefore, our Movie object will be the "base" class and it will have subclasses that are related to the movie so that it may be compared to others to generate a recommendation.


* `Strategy` - With this design pattern, we can define multiple search algorithms such as genre, subgenre, etc. With this, the user can specify an aspect of a movie, and the program will search its database for other movies that are grouped with that aspect. If there are many search categories, main code might get overloaded with all the different implemented strategies. Main code must delegate strategies to a linked object to lessen the burden. This way we can add in more strategies and not have to tamper with the main code.

## Class Diagrams
### Strategy Pattern
![Strategy](/images/strategy_pattern.jpg)

Due to the nature of our project, we chose strategy pattern as a way of managing all of our classes and variables. Our project involves sorting as a form of displaying results but the user can chose which way they want their results found and sorted. For example, they may want all movies of a certain year sorted alphabetically. Therefore we use strategy pattern to organize and manage the various sorting algorithms we are implementing.

### Composite Pattern
![Composite](/images/composite_pattern.jpg)

We will be using the composite pattern for our project because we will have different aspects of movies implemented. These different aspects will be implemented as composites and will be able to store the movie title, year of release, director, genre, and rating through inheritance. Additionally, users will be able to search for movie recommendations based on these composites. This development will then allow the user to organize their movie recommendations using the different inherited functions within a sorter function.

## Installation & Usage
### Screenshots
![sc1](/images/sc1.jpg)
![sc2](/images/sc2.jpg)
![sc3](/images/sc3.jpg)
![sc4](/images/sc4.jpg)
![sc5](/images/sc5.jpg)

### Instructions
1. To use this program, it requires a few simple requriements to be installed and that's it.
2. Clone this repository recursively (it should include googletest).
3. This program also requires the `boost` library. It can either be cloned from my repository [here](https://github.com/jshabun/boost.git) or downloaded from the official boost website.
4. In order to run, simply run `cmake .` or if on hammer `cmake3 .`
5. Then compile with `make`.
6. You should have your compiled files ready now. To run the tests simply type `./test`. To run the program run `./recommend`.
7. Choose an option from the menu and follow the prompts. The program quits when you type `Q` or `q` as said in the program menu.

### Tesing & Validation
* To test the program, we created specialized unit tests to test the most important parts of the program. We made sure all of them passed before proceeding on working on other items. We made sure to test after every change. To check the tests you simply run `./test` after compiling with cmake. We also made sure to check the valgrind report (depicted below) by running `valgrind ./test`. 

![valgrind](/images/valgrind.jpg)
