#include<stdio.h>
#include <iostream>
#include<fstream>
using namespace std;

void findMines(int a[][100], int n, int m);
void printResult(int a[][100], int n, int m);
int isValidSpot(int a[][100], int i, int j, int n, int m);
void readInput(char *fileName);

int main(){
	
	char *fileName = "MineSweepers.txt";
	readInput(fileName);
	
	return 0;
}

void findMines(int a[][100], int n, int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == -1) {
				a[i-1][j-1] += (isValidSpot(a, i-1, j-1, n, m))?1:0;
				a[i-1][j] += (isValidSpot(a, i-1, j, n, m))?1:0;
				a[i-1][j+1] += (isValidSpot(a, i-1, j+1, n, m))?1:0;
				a[i][j+1] += (isValidSpot(a, i, j+1, n, m))?1:0;
				a[i+1][j+1] += (isValidSpot(a, i+1, j+1, n, m))?1:0;
				a[i+1][j] += (isValidSpot(a, i+1, j, n, m))?1:0;
				a[i+1][j-1] += (isValidSpot(a, i+1, j-1, n, m))?1:0;
				a[i][j-1] += (isValidSpot(a, i, j-1, n, m))?1:0;
			}
		}
	}
	printResult(a, n, m);
}

int isValidSpot(int a[][100], int i, int j, int n, int m) {
	if(i >=0 && i < n && j >= 0 && j < m && a[i][j] != -1) {
		return 1;
	}
	return 0;
}

void printResult(int a[][100], int n, int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == -1)
				cout << "*";
			else
				cout << a[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

void readInput(char *fileName) {
	FILE *file;
	file = fopen(fileName, "r");
	
	int n, m;
	do {
		fscanf(file, "%d", &n);
		fscanf(file, "%d", &m);
		//Igonre break line code
		fgetc(file);
		
		int a[100][100];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++){
				if(fgetc(file) == '.')
					a[i][j] = 0;
				else
					a[i][j] = -1;
			}
			//Igonre break line code
			fgetc(file);
		}
		findMines(a, n, m);
	} while((n != 0 && m != 0) && n != EOF);
}
