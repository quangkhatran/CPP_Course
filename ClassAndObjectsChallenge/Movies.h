#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <vector> 
#include "Movie.h"

class Movies
{
private:
    std::vector<Movie> movies;
    
public:
    Movies();
    ~Movies();
    bool add_movie(Movie movie);
    bool add_watched_count(std::string name);
    void display();
};

#endif // _MOVIES_H_
