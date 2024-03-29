#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

std::string clean_string(std::string str) {
    std::string result;
    for(size_t i{0}, len = str.size(); i<len; i++){
        if ((ispunct(str[i])) || (str[i] ==  ' ' ))
        { 
            str.erase(i--, 1); 
            len = str.size(); 
        } 
    }
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c){ return std::tolower(c); });
    return str;
}

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    std::deque<char> chars;
    for(size_t i{0}; i<s.length()/2; i++){
        chars.push_back(s[i]);
    }

    size_t start_index;
    if(s.length() % 2==0) {
        start_index = s.length()/2;
    } else {
        start_index = s.length()/2+1;
    }
    for(size_t i{start_index}; i<s.length(); i++){        
        if( s[i] != chars.back() ) {
            return false;
        } else {
            chars.pop_back();
        }        
    }
    
    return true;
}

int main()
{
    
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    //std::cout << std::boolalpha;
    std::cout << std::setw(40) << std::left << "Result (true=1, false=0)" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(40) << std::left << is_palindrome(clean_string(s))  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}