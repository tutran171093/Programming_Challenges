#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

int max(int a, int b);
int longestCommnonSubsequence(char *X, char *Y, int m, int n);

int main() {
	
	char *X = (char*) malloc(100);
	char *Y = (char*) malloc(100);
	printf("Enter X: ");
	gets(X);
	printf("Enter Y: ");
	gets(Y);
	
	printf("Longest Common Subsequence: %d", longestCommnonSubsequence(X, Y, strlen(X), strlen(Y)));
	
	
	return 0;
}

int max(int a, int b) {
	return (a > b)?a:b;
}

int longestCommnonSubsequence(char *X, char *Y, int m, int n) {
	if(m == 0 || n == 0)
		return 0;
	if(X[m - 1] == Y[n - 1])
		return 1 + longestCommnonSubsequence(X, Y, m - 1, n - 1);
	else
		return max(longestCommnonSubsequence(X, Y, m - 1, n), longestCommnonSubsequence(X, Y, m, n - 1));
}
