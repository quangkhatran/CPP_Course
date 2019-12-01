#include <iostream>
#include <fstream>
#include <string>
#include <vector> 

void findAllOccurances(std::vector<size_t> & vec, std::string data, std::string toSearch)
{
	// Get the first occurrence
	size_t pos = data.find(toSearch);
 
	// Repeat till end is reached
	while( pos != std::string::npos)
	{
		// Add position to the vector
		vec.push_back(pos);
 
		// Get the next occurrence from the current position
		pos =data.find(toSearch, pos + toSearch.size());
	}
}

int main(){
    std::ifstream input_file;
    input_file.open("../romeoandjuliet.txt");
    if(!input_file){
        std::cout << "Cannot open the file" << std::endl;
        return 1;
    }
    std::cout << "File opened. Ready to go" << std::endl;
    std::string word{};
    std::cout << "Enter a word: " << std::endl;
    std::cin >> word;
    
    int total_occurrences {0};
    int total_words {0};
    std::string reading_word;
    while(!input_file.eof()){
        input_file >> reading_word;
        total_words++;
        std::vector<size_t> vec;
        findAllOccurances(vec, reading_word, word);
        total_occurrences += vec.size();
    }
    std::cout << total_words << " words were searched..." << std::endl;
    std::cout << "The substring " << word << " was found " << total_occurrences << " times"<< std::endl;
    input_file.close();
    return 0;
}
