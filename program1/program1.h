// Jack Turner
// Assignment 1
// February 16 2023

#include <iostream>
#include <array>
#include <string>
#include <fstream>

using namespace std;

void checkInt(int check, int arrayIntegers[]);
    // Takes in number to check for and the array
    // Prints that if the number has been found or not
void changeInt(int num, int index, int arrayIntegers[]);
    // Takes in the number to change, the index, and the array
    // Modifies the array with the new value
void deleteInt(int del, int arrayIntegers[], int size);
    // Takes in the index of the number to delete, the array, and the size of the array
    // Deletes the integer selected from the array
void addInt(int add, int arrayIntegers[], int size);
    // Takes in the number to add, the array, and the size
    // Adds integer to the end of the array


