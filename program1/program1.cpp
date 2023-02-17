// Jack Turner
// Assignment 1
// February 16 2023

#include "program1.h"

using namespace std;

void checkInt(int check, int arrayIntegers[]){
    int index = 0;
    int notFound = 0;
    for(int i=0;i<100;i++){
        if(arrayIntegers[i] == check){
            notFound ++;
            index = i;
        }
    }
    if(notFound == 0){
        cout << "Integer not found.\n";
    }
    if(notFound > 0){
        cout << "Integer found at index " << index << "\n";
    }
}

void changeInt(int num, int index, int arrayIntegers[]){
    cout << arrayIntegers[index] << " has been changed to " << num << "\n";
    arrayIntegers[index] = num;
}

void deleteInt(int del, int arrayIntegers[], int size){
    for(int i=0;i<size;i++){
        if(arrayIntegers[i] == del){
            arrayIntegers[i] = 0;
        }
    }
}

void addInt(int add, int arrayIntegers[], int size){
    int *newarr = new int[size+1];
    copy(arrayIntegers, arrayIntegers+size, newarr);
    newarr[size+1] = add;
    delete[] arrayIntegers;
    arrayIntegers = newarr;
    arrayIntegers[size+1] = add;
}

int main(){
    int size = 100;
    bool playing = true;
    char input1;
    int count = 0;
    char c;
    int *arrayIntegers = new int[100];
    // int arrayIntegers[100];
    ifstream file;
    file.open("integers.txt");
    string word;
    if(file.good()){
        while(file >> skipws >> c){
            arrayIntegers[count] = c;
            count ++;
        }
    }
    while(playing == true){
        cout << "Select from the following options\n" << "1 Check if integer exists\n" << "2 Modify value in array\n" << "3 Add a new integer\n" << "4 Delete integer\n" << "5 Exit\n";
        cin >> input1;
        switch(input1){
            case '1':
                int input2;
                cout << "Input variable to check for\n";
                cin >> input2;
                checkInt(input2, arrayIntegers);
                break;
            case '2':
                int input3;
                int input4;
                cout << "Enter new integer\n";
                cin >> input3;
                cout << "Enter a position\n";
                cin >> input4;
                changeInt(input3, input4, arrayIntegers);
                break;
            case '3':
                int input5;
                cout << "Enter the number you would like to add\n";
                cin >> input5;
                addInt(input5, arrayIntegers, size);
                size ++;
                break;
            case '4':
                int input6;
                cout << "Enter the index of the number you would like to delete\n";
                cin >> input6;
                deleteInt(input6, arrayIntegers, size);
            case '5':
                playing = false;
                break;
        }
    }
    for(int i=0;i<size;i++){
        cout << arrayIntegers[i] << "\n";
    }
    delete[] arrayIntegers;
}
