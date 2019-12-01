#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <iostream>
#include <string>

class Movie
{
private:
    std::string name;
    std::string rating;
    int watched_count;
    
public:
    // constructor
    Movie(std::string name_val = "None", std::string rating_val = "A", int watched_count_val = 0); 
   
    
    // copy constructor 
    Movie(const Movie &source);
    
    // destructor
    ~Movie();
    
    // getter
    std::string get_name();
    std::string get_rating();
    int get_watched_count();
    int add_watched_count();
    void display();
    
};

#endif // _MOVIE_H_
