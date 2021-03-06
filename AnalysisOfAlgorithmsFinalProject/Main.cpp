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
#include <map>

using namespace std;

int main()
{
	Driver d[5];
	double runningTime[2][5][6];
	for (int j = 0; j < 5; j++)
	{
		for (int i = 2; i <= 12; i++)
		{
			runningTime[0][j][(i-2)] = d[j].dynamicTime(d[j].X, d[j].Y, i*2);
			runningTime[1][j][(i-2)] = d[j].recursiveTime(d[j].X, d[j].Y, i);
		}
	}
	
	// Print part of the program

	for (int i = 0; i < 2; i++)
	{
		cout << "**********************************************************" << endl;
		if (i == 0)
		{
			cout << "                  Dynamic Programming                     " << endl;
			cout << "**********************************************************" << endl;
		}
		if (i == 1)
		{
			cout << "                      Recursion                           " << endl;
			cout << "**********************************************************" << endl;
		}
		for (int j = 0; j < 10; j++)
		{
			cout << j+2 << "   ";
			for (int k = 0; k < 5; k++)
			{
				printf("%4.1f s  \t", (double)runningTime[i][k][j]);
			}
			cout << endl;
		}
	}

	system("PAUSE");
	return 0;
}