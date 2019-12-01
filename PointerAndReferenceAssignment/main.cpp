#include <iostream>
using namespace std;

void print(int array[], size_t size){
    for(size_t i{0}; i<size; i++){
        cout << array[i] << " ";
    }
}

int* apply_all(int array1[], size_t size1, int array2[], size_t size2) {
    size_t size_result {size1*size2};
    int *array_result = new int[size_result];
    int index {0};
    for(size_t i {0}; i<size2; i++){
         for(size_t j {0}; j<size1; j++){
             int value { array2[i] * array1[j] };
             array_result[index] = value;
            index++;
         }
    }
    return array_result;
    
}

int main(){
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1: " << endl; 
    print(array1,5);
    
    cout << "\nArray 2: " << endl;
    print(array2,3);
    
    int *result = apply_all(array1,5,array2,3);
    cout << "Result: ";
    print(result,15);
    delete [] result;
    return 0;
}
