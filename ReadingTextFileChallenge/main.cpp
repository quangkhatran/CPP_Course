#include <iostream>
#include <fstream>
#include <string>

int get_score(std::string correct_answers, std::string student_answers){
    int score {0};
    for(size_t i {0}; i< correct_answers.length(); i++){
        if(student_answers[i]==correct_answers[i]){
            score++;
        }
    }
    return score;
}

void draw_a_line(int length){
    std::string line (length,'-');
    std::cout << line << std::endl;
}

int main(){
    std::ifstream input_file{};
    input_file.open("../responses.txt");
    if(!input_file){
        std::cout << "Cannot open the file" << std::endl;
        return 1;
    }
    std::cout << "File opened. Ready to go" << std::endl;
    std::string correct_answers;
    input_file >> correct_answers;
    //std::cout << correct_answers << std::endl;
    std::string student{};
    std::string student_answers{};
    std::cout << std::setw(20) << std::left << "Student" << std::setw(20) << std::right << "Score" << std::endl;
    draw_a_line(40);
    while(!input_file.eof()){
        input_file >> student >> student_answers;
        //std::cout << student << ": " << student_answers << ": " << get_score(correct_answers,student_answers) << std::endl;
        std::cout << std::setw(20) << std::left << student << std::setw(20) << std::right << get_score(correct_answers,student_answers) << std::endl;
    }
    input_file.close();
    return 0;
}
