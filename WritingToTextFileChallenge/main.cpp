#include <iostream>
#include <fstream>

int main(){
    std::ifstream input_file;
    std::ofstream output_file;
    input_file.open("../romeoandjuliet");
    output_file.open("../romeoandjuliet_out.txt");
    if(!input_file){
        std::cerr << "Cannot open the input file" << std::endl;
        return 1;
    }
    if(!output_file){
        std::cerr << "Cannot open the output file" << std::endl;
        return 1;
    }
    int line_number {0};
    std::string line;
    /*
     // version 1: insert numbers on every single line, no matter the line is empty or not
    while(getline(input_file,line)){
        line_number++;
        output_file << std::left << std::setw(20) << line_number  << line << std::endl;
    }
     */
     // version 2: insert numbers on the non-empty lines
    while(getline(input_file,line)){
        if(line.length() > 1){
            line_number++;
            output_file << std::left << std::setw(20) << line_number  << line << std::endl;
        } else {
            output_file << std::endl;
        }
    }
    std::cout << "Finished" << std::endl;
    input_file.close(); 
    output_file.close();
    return 0;
}
