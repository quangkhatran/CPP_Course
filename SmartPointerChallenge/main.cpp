#include <iostream>
#include <memory>
#include <vector>

class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const {return data; }
    ~Test() {std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

// Function prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>>&vec);

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make(){
    std::shared_ptr<Test> test_ptr = std::make_shared<Test>();
    std::vector<std::shared_ptr<Test>> vec;
    vec.push_back(test_ptr);
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> ptr = std::make_unique<std::vector<std::shared_ptr<Test>>>(vec);
    return ptr;
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num){
    vec.clear();
    for(size_t i {0}; i<num; i++){
        std::cout << "Please enter the "<< i+1 << "-th number: " << std::endl;
        int value;
        std::cin >> value;
        std::shared_ptr<Test> test_ptr = std::make_shared<Test>(value);
        vec.push_back(test_ptr);
    }
    
}

void display(const std::vector<std::shared_ptr<Test>>&vec){
    std::cout << "Display the numbers: " << std::endl;
    for(const auto &shared_ptr_to_test:vec){
            std::cout << shared_ptr_to_test->get_data() << std::endl;
    }
}

int main() {
    
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    
     return 0;
}
