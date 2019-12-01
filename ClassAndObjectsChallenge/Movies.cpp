#include "Movies.h"

Movies::Movies()
{
}

Movies::~Movies()
{
}

bool Movies::add_movie(Movie movie)
{
   
    for(auto m:movies){
        if(m.get_name() == movie.get_name()) {
            std::cout << "Movie already exists, so no need to add" << std::endl;
            return false;
        }
    } 
    movies.push_back(movie);
    std::cout << "Movie added" << std::endl;
    return true; 
}

bool Movies::add_watched_count(std::string name)
{
    for(auto &m:movies){
        if(m.get_name() == name) {
                m.add_watched_count();
                return true;
        }
    }
    std::cout << name << " cannot be found. You need to add this movie to the movies collection first before increasing the watched count." << std::endl;
    return false;
}

void Movies::display()
{
        for(auto m:movies){
            m.display();
        }
}

