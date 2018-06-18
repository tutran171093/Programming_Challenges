#include<stdio.h>
#include <iostream>
#include<fstream>
#include <stdlib.h>
#include<string.h>

using namespace std;


int isJollyJumper(int a[], int n);
int isAll1ToNOccur(int result[], int n);
void readInput(char *fileName);

int main() {
	//int a[] = {};
	
	readInput("JollyJumpers.txt");
			
	return 0;
}

int isJollyJumper(int a[], int n) {
	int result[n + 1];
	for(int i = 0; i < n - 1; i++) {
		int diff = abs(a[i] - a[i+1]);
		if(diff < n) {
			result[diff] = 1;
		}
	}
	return isAll1ToNOccur(result, n);	
}

int isAll1ToNOccur(int result[], int n) {
	for(int i = 1; i < n; i++) {
		if(result[i] == 0)
			return 0;
	}	
	return 1;
}

void readInput(char *fileName) {
	FILE *file;
	file = fopen(fileName, "r");
	int n;
	while(fscanf(file, "%d", &n) == 1) {
		int a[n];
		for(int i = 0; i < n; i++) {
			fscanf(file, "%d", &a[i]);
		}
		if(isJollyJumper(a, n) == 1)
			cout << "Jolly" << "\n";
		else
			cout << "Not Jolly" << "\n";
	}
}
