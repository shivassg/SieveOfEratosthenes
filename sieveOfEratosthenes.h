/* 
 * File:   sieveOfEratosthenes.h
 * Author: Shiva Shankar Ganesan
 * Created on October 5, 2018
 * Compiler Used: g++
 * Description of the file: Header file which contains function and variables declaration
 */



#ifndef SIEVEOFERATOSTHENES_H
#define SIEVEOFERATOSTHENES_H

#include<iostream>

enum printMode {
	PRINT_ENTIRE_CONTENTS,
	PRINT_NUMBER_LIST
};

class sieveOfEratosthenes{
    
private:
    int **steps;
    int step_row_size;
    int n;
    int current_row;
    int current_number;
    printMode mode;
    void initializeValues(int n);
    void allocateSteps();
    void reallocateSteps();
    
    void printRow(int *row, bool stepByStep=true);
    
    
public:
    
    sieveOfEratosthenes(); //Default constructor
    void compute();
    void setN();
    void freeSteps();
    void setInput(int n,std::string mode);
            
};



#endif /* SIEVEOFERATOSTHENES_H */

