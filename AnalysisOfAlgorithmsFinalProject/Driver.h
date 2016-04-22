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
#include <time.h>

using namespace std;

class Driver
{
public:
	Driver();
	~Driver();
	double dynamicTime(char *m, char *n, int size);
	double recursiveTime(char *m, char *n, int size);
	char Y[100];
	char X[100];
private:
	int size;
};

Driver::Driver()
{
	/* Create the two arrays for the test cases */
	srand(time(NULL));
	size = 100;
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

double Driver::dynamicTime(char *n, char *m, int size)
{
	dynamic dyna;
	/* Make sure to get both temp arrays ready to be able to be fed to the dynamic fucntion */
	
	char ** tempY = new char*[100];
	for (int i = 0; i < 100; ++i)
		tempY[i] = new char[size];
	
	char ** tempX = new char*[100];
	for (int i = 0; i < 100; ++i)
		tempX[i] = new char[size
		];

	int current = 0;
	for (int i = 1; i < 20; i++)
	{
		for (int j = 0; j < size; j++)
		{
			tempY[i][j] = n[current];
			tempX[i][j] = m[current];
			current++;
		}
		current == 0;
	}

	typedef std::chrono::high_resolution_clock Clock;
	typedef std::chrono::milliseconds milliseconds;
	
	Clock::time_point startTime = Clock::now();
	for (int i = 0; i < 30; i++)
	{
		dyna.LCS(tempY[i], tempX[i], size, size);
	}
	Clock::time_point endTime = Clock::now();

	milliseconds ms = std::chrono::duration_cast<milliseconds>(endTime - startTime);

	double result = ms.count() / double(30) * 1000;

	return result/2;
}

double Driver::recursiveTime(char *n, char *m, int size)
{
	Recursive recur;
	int arraySize = 10;
	/* Make sure to get both temp arrays ready to be able to be fed to the dynamic fucntion */

	char ** tempY = new char*[30];
	for (int i = 0; i < 30; ++i)
		tempY[i] = new char[size];

	char ** tempX = new char*[30];
	for (int i = 0; i < 30; ++i)
		tempX[i] = new char[size];

	int current = 0;
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < size; j++)
		{
			tempY[i][j] = n[current];
			tempX[i][j] = m[current];
			current++;
		}
		current == 0;
	}

	typedef std::chrono::high_resolution_clock Clock;
	typedef std::chrono::milliseconds milliseconds;

	Clock::time_point startTime = Clock::now();

	for (int i = 0; i < 30; i++)
	{
		recur.RecursiveLCS(tempY[i], tempX[i], size, size);
	}
	Clock::time_point endTime = Clock::now();

	milliseconds ms = std::chrono::duration_cast<milliseconds>(endTime - startTime);

	double result = ms.count()/double(30) * 1000;

	return result;
}