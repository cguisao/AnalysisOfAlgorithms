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
	Driver d;
	int size = 5;

	int hi = d.dynamicTime(15, 15, 15);
	int hola = d.recursiveTime(15, 15, 15);

	cout << hi << endl;
	cout << hola << endl;
	cout << endl;

	system("PAUSE");
	return 0;
}