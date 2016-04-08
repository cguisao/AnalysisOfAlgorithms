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
#include <time.h>
#include "Driver.h"

using namespace std;

int main()
{
	
	/* Creating the two arrays for testing purposes */

	//srand(time(NULL));
	//int const size = 18;
	//char Y[size];
	//for (int i = 0; i < size; i++)
	//{
	//	int n = rand() % 26;
	//	char c = (char)(n + 65);
	//	Y[i] = c;
	//}
	//srand(1);

	///* Makes sure that both arrays have different characters */
	//std::this_thread::sleep_for(std::chrono::seconds(1));

	//srand(time(NULL));
	//char X[size];
	//for (int i = 0; i < size; i++)
	//{
	//	int n = rand() % 26;
	//	char c = (char)(n + 65);
	//	X[i] = c;
	//}
	//srand(3);

	dynamic n;
	Recursive w;
	Driver d;
	int size = 5;

	clock_t startTime = clock();
	//int hi = n.LCS(Y, X, size, size);
	int hi = d.dynamicTime(5, 5, 5);
	clock_t endTime = clock();

	clock_t startTime2 = clock();
	//int hola = w.RecursiveLCS(Y, X, size, size);
	clock_t endTime2 = clock();

	cout << hi << endl;
	//cout << hola << endl;
	cout << endl;

	///*for (int i = 0; i < size; i++)
	//{
	//	cout << Y[i] << "\t";
	//}

	//for (int i = 0; i < size; i++)
	//{
	//	cout << X[i] << "\t";
	//}*/

	cout << endl;
	system("PAUSE");
	return 0;
}