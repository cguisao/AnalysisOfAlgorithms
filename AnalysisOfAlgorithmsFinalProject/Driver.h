// ***********************************************************************
//
// (c) Copyright 2016 Carlos Guisao 
//
//  All rights reserved.
//
//  cguisao@fau.edu
//
// ***********************************************************************
#include <iostream>
#include "Dynamic.h"
#include "Recursive.h"
#include <chrono>
#include <thread>

using namespace std;

class Driver
{
public:
	Driver();
	~Driver();
	double dynamicTime(int k, int n, int m);
	double recursiveTime(int k, int n, int m);

private:
	char Y[18];
	char X[18];
	int size;
};

Driver::Driver()
{
	/* Create the two arrays for the test cases */
	srand(time(NULL));
	size = 18;
	Y[size];
	for (int i = 0; i < size; i++)
	{
		int n = rand() % 26;
		char c = (char)(n + 65);
		Y[i] = c;
	}
	srand(1);

	/* Makes sure that both arrays have different characters */
	std::this_thread::sleep_for(std::chrono::seconds(1));

	srand(time(NULL));
	X[size];
	for (int i = 0; i < size; i++)
	{
		int n = rand() % 26;
		char c = (char)(n + 65);
		X[i] = c;
	}
	srand(1);
}

Driver::~Driver()
{
}

double Driver::dynamicTime(int k, int n, int m)
{
	/* Make sure to get both temp arrays ready to be able to be fed to the dynamic fucntion */
	char tempY[18];
	char tempX[18];
	dynamic dyna;

	for (int i = 0; i < k; i++)
	{
		tempY[i] = Y[i];
		tempX[i] = X[i];
	}

	clock_t startTime = clock();
	double answer = dyna.LCS(Y, X, size, size);
	clock_t endTime = clock();

	return answer;
}