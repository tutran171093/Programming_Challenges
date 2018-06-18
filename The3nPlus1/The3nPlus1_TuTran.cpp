/*
The 3n + 1 Problem
Technique: Dynamic Programming (Memoization - Top Down)
Author: Tu Tran
*/

#include <iostream> 
#include <stdio.h>
using namespace std;

long dataTableOfPreviousCal[1000000];
long sizeOfDataTable = 1000000;
int countCycleLength(unsigned long long n);

int main() {
	//Cycle length of 1 is 1
	dataTableOfPreviousCal[1] = 1;
	
	//i, j is the pair of input
	int i = 1;
	int j = 999999;
	
	//max of cycle length
	int maxOfCycleLength = 0;
	
	//Loop from i to j to find max of cycle length
	for(int k = i; k <= j; k++) {
		//Find the cycle length of each number between i and j
		int cycleLength = countCycleLength(k);
		//Compare and update the max of cycle length
		maxOfCycleLength = (maxOfCycleLength < cycleLength)?cycleLength:maxOfCycleLength;
	}
	
	cout << maxOfCycleLength;
	return 0;
}

int countCycleLength(unsigned long long n) {
	//If the calculation of n is exists in DataTable, then just return it's result.
	if(n < sizeOfDataTable && dataTableOfPreviousCal[n] != 0) {
		return dataTableOfPreviousCal[n];
	}
	int cycleLength;
	if(n % 2 == 0)
		cycleLength = countCycleLength(n / 2) + 1;
	else 
		cycleLength = countCycleLength(n * 3 + 1) + 1;
		
	//DataTable only catch the result for some possible numbers. The memory can not handle the too big number.
	if(n < sizeOfDataTable)
		dataTableOfPreviousCal[n] = cycleLength;
	return cycleLength;
}
