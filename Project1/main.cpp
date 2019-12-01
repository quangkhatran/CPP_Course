#include <iostream>
#include <vector> 
using namespace std;

void print_menu(){
    cout << "P: Print numbers" << endl;
    cout << "A: Add a number" << endl;
    cout << "M: Display the mean of numbers" << endl;
    cout << "S: Display the smallest number" << endl;
    cout << "L: Display the largest number" << endl;
    cout << "Q: Quit" << endl;
    cout << "Enter your choice" << endl;
}

void print_numbers(vector<double> numbers) {
    for(auto number:numbers){
        cout << number << endl;
    }
}

double find_mean_of_numbers(vector<double> numbers) {
    double sum{0.0};
    for(auto number:numbers){
        sum+=number;
    }
    return sum/numbers.size();
}

double find_smallest_number(vector<double> numbers){
    double smallest_number {numbers[0]};
    for(int i {1}; i < numbers.size(); i++){
        if( numbers[i] < smallest_number ) 
            smallest_number = numbers[i];
    }
    return smallest_number;
}

double find_largest_number(vector<double> numbers){
    double largest_number {numbers[0]};
    for(int i {1}; i < numbers.size(); i++){
        if( numbers[i] > largest_number ) 
            largest_number = numbers[i];
    }
    return largest_number;
}

int main(){
    bool done{false};
    char selection{};
    vector<double> numbers;
    while(!done){
        print_menu();
        cin >> selection;
        if(selection == 'q' || selection == 'Q') {
            done = true;
        } else {
            switch(selection){
                case 'p':
                case 'P': 
                    if(numbers.size() > 0){
                        print_numbers(numbers);
                    } else {
                        cout << "Currently, empty list of numbers" << endl;
                    }
                    break;
                    
                case 'a':
                case 'A': {
                    cout << "What number would you like to add?" << endl;
                    double number_to_add;
                    cin >> number_to_add;
                    numbers.push_back(number_to_add);
                    cout << "Number " << number_to_add << " has been added. The list now becomes: " << endl;
                    print_numbers(numbers);
                    break;
                }
                
                case 'm':
                case 'M': 
                    cout << "Mean of the numbers is: " << find_mean_of_numbers(numbers) << endl;
                    break;
                
                case 's':
                case 'S': {
                    if(numbers.size() > 0) {
                        cout << "The smallest number is: " << find_smallest_number(numbers) << endl;
                    } else {
                        cout << "Currently, empty list of numbers";
                    }
                    break;
                }
                
                case 'l':
                case 'L': {
                    if(numbers.size() > 0) {
                        cout << "The largest number is: " << find_largest_number(numbers) << endl;
                    } else {
                        cout << "Currently, empty list of numbers";
                    }
                    break;
                }
                    
                default: cout << "Please select again." << endl;
            }
                
                    
            
        }
    }
    return 0;
}
