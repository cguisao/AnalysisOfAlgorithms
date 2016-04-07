// ***********************************************************************
//
// (c) Copyright 2014 Carlos Guisao 
//
//  All rights reserved.
//
//  cguisao@fau.edu
//
// ***********************************************************************
#include <iostream>

using namespace std;

class dynamic
{
public:
	dynamic();
	~dynamic();
	int LCS(char *X, char *Y, int m, int n);
	int max(int x, int y);

private:
};

dynamic::dynamic()
{
}

dynamic::~dynamic()
{
}

int dynamic::LCS(char *X, char *Y, int m, int n)
{
	//int L[6][6];
	int N = m + 1;
	int M = n + 1;

	// dynamic allocation
	int** L = new int*[N];
	for (int i = 0; i < N; ++i)
		L[i] = new int[M];

	int answer = 0;
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
			{
				L[i][j] = 0;
			}
			else if (X[i - 1] == Y[j - 1])
			{
				L[i][j] = L[i - 1][j - 1] + 1;
			}
			else
			{
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
			}
		}
	}

	answer = L[m][n];

	/* delocate memory from the heap */

	for (int i = 0; i < N; ++i)
		delete[] L[i];
	delete[] L;

	return answer;
}

int dynamic::max(int a, int b)
{
	return (a > b) ? a : b;
}