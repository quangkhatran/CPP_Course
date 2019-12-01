#include <iostream>
#include "Movie.h"
#include "Movies.h"

using namespace std;
int main(){
    
    Movie movie1("Frozen", "A", 1);
    movie1.display();
    
    Movie movie2("Game of Thrones", "B", 2);
    movie2.display();
    
    Movies movies {};
    movies.add_movie(movie1);
    movies.add_movie(movie2);
    movies.display();
    
    movies.add_watched_count("Game Of Thrones");
    movies.display();
    
    movies.add_watched_count("The Lion King");
    Movie movie3("The Lion King", "A", 3);
    movie3.add_watched_count();
    movies.add_movie(movie3);
    movies.add_watched_count("The Lion King");
    movies.display();
    
    Movie movie4("Frozen", "A", 1);
    movies.add_movie(movie4);
    movies.display();
    return 0;
}

