#include <iostream>
#include <string>

using namespace std;

string add_spaces(int number_of_spaces){
    string s{};
    for(int i {0}; i < number_of_spaces; i++){
        s += " ";
    }
    return s;
}

int main(){
    cout << "Enter a string: " << endl;
    string s{};
    getline(cin, s);
    cout << "Your string: " << s << endl;
    for(int i {0}; i < s.length(); i++){
            cout << add_spaces( s.length() - 1 - i);
            
            for(int j {0}; j <= i; j++){
                cout << s[j];
            }
            
            for(int k {i}; k > 0; k--){
                cout << s[k-1];
            }
            
            cout << add_spaces( s.length() - 1 - i) << endl;
    }
    
    return 0;
}

/*
// Letter Pyramid
// Written by Frank J. Mitropoulos

#include <iostream>
#include <string>


int main()
{
    std::string letters{};

    std::cout << "Enter a string of letters so I can create a Letter Pyramid from it: ";
    getline(std::cin, letters);

    size_t num_letters = letters.length();

    int position {0};

    // for each letter in the string
    for (char c: letters) {

        size_t num_spaces = num_letters - position;
        while (num_spaces > 0) {
            std::cout << " ";
            --num_spaces;
        }

        // Display in order up to the current character
        for (size_t j=0; j < position; j++) {
            std::cout << letters.at(j);
        }

        // Display the current 'center' character
        std::cout << c;

        // Display the remaining characters in reverse order
        for (int j=position-1; j >=0; --j) {
            // You can use this line to get rid of the size_t vs int warning if you want
            auto k = static_cast<size_t>(j);
            std::cout << letters.at(k);
        }

        std::cout << std::endl; // Don't forget the end line
        ++position;
    }

    return 0;
}
*/
