#include<iostream>
#include<string>
#include<vector>
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
    cout << "=============================" << endl;
    cout << "---Printing Prefix table---" << endl;
    for(int i = 0; i < size; i++){
        cout << i << ": " << array[i] << endl;
    }
    cout << "=============================" << endl;
}

vector<int> KMP(int *prefix_table, string pattern, string text){
    vector<int> match_positions;
    int size_of_text = text.length();
    int pattern_size = pattern.length();

    int i = 0; 
    while(i < size_of_text){

        for(int j = 0; j < pattern_size; j++){ 
            if(pattern[j] != text[i]){
                int shift = prefix_table[j];
                if(j == 0 ){
                    i++;
                    break;
                }
                else{
                    j = shift-1;
                }
            }
            else{
                i++;
                if(j == pattern_size-1){
                    match_positions.push_back(i-pattern_size);
                }
            }
        } 
    }

    if(match_positions.size() > 0){
        cout << "=============================" << endl;
        cout << "---Printing Matches table---" << endl;
        for(int  i = 0; i < match_positions.size(); i++){
            cout << "Matches found at: " << match_positions[i] << endl; 
        }
        cout << "=============================" << endl;
    }
    else{
        cout << "No matches found" << endl;
    }


    return match_positions;
}

int main(){
    string text, pattern;
    text = "ABDKABCADABJRHKRABCADAB";
    pattern  = "ABCADAB";
    int size_of_pattern = pattern.length();
    int prefix_table[size_of_pattern];
    prefix_table[0] = 0;
    createPrefixTable( prefix_table, pattern, size_of_pattern);
    printPrefixTable(prefix_table, size_of_pattern);

    KMP(prefix_table, pattern, text);
}
