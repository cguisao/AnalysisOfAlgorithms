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

using namespace std;

class Recursive
{
public:
	Recursive();
	~Recursive();
	int RecursiveLCS(char *X, char *Y, int m, int n);
	int max(int x, int y);
private:

};

Recursive::Recursive()
{
}

Recursive::~Recursive()
{
}

int Recursive::RecursiveLCS(char *X, char *Y, int m, int n)
{
	if (m == 0 || n == 0)
	{
		return 0;
	}
	else if (X[m - 1] == Y[n - 1])
	{
		return 1 + RecursiveLCS(X, Y, m-1, n-1);
	}
	else
	{
		return max(RecursiveLCS(X, Y, m, n - 1), RecursiveLCS(X, Y, m-1, n));
	}
}

int Recursive::max(int a, int b)
{
	return (a > b) ? a : b;
}