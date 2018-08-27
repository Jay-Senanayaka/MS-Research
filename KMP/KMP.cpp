#include<iostream>
#include<string>
using namespace std;

void createPrefixTable(int *ptr_to_array, string pattern, int size){
    int counter = 1;
    int i  = 0;
    int current = 1;
    while(current < size){
        if(pattern[i] == pattern[current]){
            ptr_to_array[current] = counter;
            i++;
            current++;
            counter++;
        }
        else{
            i = 0;
             ptr_to_array[current] = 0;
             counter = 1;
             current++;
        }
    }
}

void printPrefixTable(int *array, int size){
    for(int i = 0; i < size; i++){
        cout << i << ": " << array[i] << endl;
    }
}

int main(){
    string text, pattern;

    pattern  = "ABCADAB";
    int size_of_pattern = pattern.length();
    int prefix_table[size_of_pattern];
    prefix_table[0] = 0;
    createPrefixTable( prefix_table, pattern, size_of_pattern);
    printPrefixTable(prefix_table, size_of_pattern);

}