#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include <iterator>

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

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    // This function should display 
    // Playing: followed by the song that is playing
   
    std::cout << "Playing: " << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    // This function should display the current playlist 
    // and then the current song playing.
    for(auto song: playlist){
        std::cout << song << std::endl;
    }
    std::cout << "Current song playing: " << current_song << std::endl;
    
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    
    
   
    char selection {'l'}; // default selection: list the current playlist
    bool quit {false};
    while(!quit){
        display_menu();
        std::cin >> selection;
        switch(selection){
            case 'f':
            case 'F':  {
                current_song = playlist.begin();
                play_current_song(*current_song);
                break;
            }
            case 'n':
            case 'N': { 

                if(*current_song == playlist.back())
                    current_song = playlist.begin();
                else
                    current_song++;
                play_current_song(*current_song);
                break;
            }
            case 'p':
            case 'P': { 
                
                if(current_song == playlist.begin())
                {
                    current_song--;
                    current_song--;
                }
                else
                    current_song--;
                play_current_song(*current_song);
                break; 
            }
            case 'a':
            case 'A': { 
                std::string new_song_name;
                std::string new_song_artist;
                int new_song_rating;
                
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                
                std::cout << "Please enter the name of the new song: ";
                getline(std::cin, new_song_name);
                
                std::cout << "Please enter the artist of the new song: ";
                getline(std::cin, new_song_artist);
                
                std::cout << "Please enter the rating of the new song: ";
                std::cin >> new_song_rating;
                
                Song new_song {new_song_name, new_song_artist, new_song_rating};
                playlist.push_back(new_song);                
                current_song = std::find(playlist.begin(), playlist.end(), new_song);
                play_current_song(*current_song);
                
                break;
            }
            case 'l':
            case 'L':  {
                display_playlist(playlist, *current_song);
                break;
            }
            case 'q':
            case 'Q':
                quit = true;
                break;
            default: {
                std::cout << "Sorry, we don't have that option. Please select again." << std::endl;
                break;
                
            }
        }
    }
    
    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}
