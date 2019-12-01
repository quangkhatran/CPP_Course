#include <iostream>
#include <iomanip> 
class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

int main() {
        std::cout << "Please enter the name of the new song: " << std::endl;
        std::string new_song_name;
        getline(std::cin, new_song_name);
        
        std::cout << "Please enter the artist of the new song: " << std::endl;
        std::string new_song_artist;
        getline(std::cin, new_song_artist);
        
        std::cout << "Please enter the rating of the new song: " << std::endl;
        int new_song_rating;
        std::cin >> new_song_rating;
        
        
        Song song {new_song_name, new_song_artist, new_song_rating};
        std::cout << song << std::endl;
        return 0;
}