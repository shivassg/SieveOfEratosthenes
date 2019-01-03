/* 
 * File:   sieveOfEratosthenes.cpp
 * Author: Shiva Shankar Ganesan
 * Created on October 5, 2018
 * Compiler Used: g++
 * Description of the file: Implementation file of sieveOfEratosthense class 
 */

#include <iostream>
#include <iomanip>
#include "sieveOfEratosthenes.h"

using namespace std;



sieveOfEratosthenes::sieveOfEratosthenes(){
    //Default constructor
}

void sieveOfEratosthenes::setInput(int n,string mode){
    initializeValues(n);
    if(mode=="Entire Contents"){
            this->mode = PRINT_ENTIRE_CONTENTS;
    }else{
        this->mode=PRINT_NUMBER_LIST;
    }
}

void sieveOfEratosthenes::initializeValues(int input){
    n=input;
    current_row=0;
    current_number=2;
    step_row_size=5;
    allocateSteps();
    
    for(int j=2; j<=n;j++){  /* In the first row, fill 2...n *///if n=5 steps[0][0]=2 [0][1]=3 [0][2]=4 [0][3]=5
        steps[current_row][j-2]=j;
    }
}

void sieveOfEratosthenes::allocateSteps() {
    //Given in the problem that it is 5 by n array. So creating 2d array. 
	steps = new int*[step_row_size];  //step_row_size=5     
	for (int i=0; i < step_row_size; i++) {
		steps[i] = new int[n-1]; //Creating the array to hold n values. Array index starts with 0. Hence n-1
	}
}


void sieveOfEratosthenes::printRow(int *row, bool stepByStep) {
	for (int i=0; i< n-1; i++) {
		if (stepByStep) {
			cout <<setw(5);
			if (row[i] == 0) {
				cout << "-" << " ";
			} else {
				cout <<row[i]<< " ";
			}
		} else {
			if (row[i] != 0) {
				cout <<row[i]<< " ";
			}
		}
	}
	cout <<endl;
}

void sieveOfEratosthenes::freeSteps() {
	for (int i=0; i < current_row; i++ ) {
		delete[](steps[i]);
	}
	delete[] steps;
}

void sieveOfEratosthenes::reallocateSteps() {
	int cur_row_size = step_row_size;
	step_row_size += 5;
	int **new_steps = new int*[step_row_size];
	// Allocate memory for new size
	for (int i=0; i < step_row_size; i++) {
		new_steps[i] = new int[n-1];
	}
	// Copy the old contents to the new array and free the old array
	for (int i=0; i < cur_row_size; i++) {
		memcpy(new_steps[i], steps[i], sizeof(int) * n);
		delete[](steps[i]);
	}
	delete[](steps);
	if (mode == PRINT_ENTIRE_CONTENTS) {
		cout <<"Array Resized"<<endl;
	}
	// Replace steps with the newly created steps
	steps = new_steps;
}


void sieveOfEratosthenes::compute(){
    // Print the first row and move to next one
    if (mode == PRINT_ENTIRE_CONTENTS){
        printRow(steps[current_row]);
    }
    
    current_row++;
    while(1){
        if (current_row % 5 == 0) {
			// Need more memory
			reallocateSteps();
	}
        //Copy the values from previous step so we can have crossed out values 
        memcpy(steps[current_row], steps[current_row-1], sizeof(int) * n-1);
        
        if ((current_number * current_number) > n){ //if the square of non-crossed number is greater than n. Then we need to stop
            break;
        }
        
        for (int multiple=current_number * 2; multiple <=n; multiple += current_number ) {
			steps[current_row][multiple-2] = 0;
        }
        
        if (mode == PRINT_ENTIRE_CONTENTS){
			printRow(steps[current_row]);
        }
        
        current_number = current_number + 1; 
        while (steps[current_row][current_number-2] == 0) {
			current_number++;
	}
        current_row++;
    }
    if (mode == PRINT_ENTIRE_CONTENTS) {
		printRow(steps[current_row]);
		cout << endl << "Prime numbers up to " << n <<":" << endl;
    }
    printRow(steps[current_row], false);
}