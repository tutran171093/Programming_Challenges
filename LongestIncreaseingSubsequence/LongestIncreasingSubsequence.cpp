#include<stdio.h>
#include<string.h>
#include <math.h>
#include <iostream>
using namespace std;

int longestIncreasingSubsequence(int a[], int n, int i, int result, int preVal);
int max(int a, int b);

int main() {
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	
	cout << longestIncreasingSubsequence(arr, 8, 0, 0, 0);
	
	return 0;
}

int longestIncreasingSubsequence(int a[], int n, int i, int result, int preVal) {
	if(i == n)
		return result;
	if(i == 0)
		return longestIncreasingSubsequence(a, n, i + 1, 1, a[0]);
	if(a[i] > preVal)
		return longestIncreasingSubsequence(a, n, i + 1, result + 1, a[i]);
	else
		return max(longestIncreasingSubsequence(a, n, i + 1, 1, a[i]), longestIncreasingSubsequence(a, n, i + 1, result, preVal));
}

int max(int a, int b) {
	return (a > b) ? a : b;
}
