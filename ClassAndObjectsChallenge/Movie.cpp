#include "Movie.h"

// constructor 
Movie::Movie(std::string name_val, std::string rating_val, int watched_count_val): name{name_val}, rating{rating_val}, watched_count{watched_count_val}{
}

// copy constructor
Movie::Movie(const Movie &source){
    name = source.name;
    rating = source.rating;
    watched_count = source.watched_count;
}

// destructor    
Movie::~Movie()
{
}

std::string Movie::get_name(){return name;}
std::string Movie::get_rating(){return rating;}
int Movie::get_watched_count(){return watched_count;}

void Movie::display() {
    std::cout << name << ", " << rating << ", " << watched_count << std::endl;
}

int Movie::add_watched_count(){
    watched_count += 1;
    std::cout << "Added 1 watched count for the movie " << name << ". Its watched count now is " << watched_count << std::endl;
    return watched_count;
}
