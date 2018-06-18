#include<stdio.h>
#include <iostream>
#include<fstream>
#include<string.h>
#include <stdlib.h>

using namespace std;

struct tokenWord {
	char *words;
	tokenWord *next;
};

int L, D, N;
char *wordInAlienLanguage[5000];

tokenWord *queue[1000000];
int size = 0;

int counWords(tokenWord *first);
int checkExistsWord(char *word);
int checkContains(char *word);
void push(tokenWord * node);
tokenWord *pop();
int readInput(char *fileName);

int main() {
	
	readInput("AlienLanguage_LargeData.txt");
	
	return 0;
	
}

int counWords(tokenWord *first) {
	int result = 0;
	for(int i = 0; i < strlen(first->words); i++) {
		tokenWord *word = (struct tokenWord*) malloc(sizeof(tokenWord));
		word->words = (char *) malloc(sizeof(char) * 1000);
		word->words[0] = first->words[i];
		word->words[1] = '\0';
		word->next = first->next;
		push(word);
	}
	while(size > 0) {
		tokenWord *word = pop();
		if(word->next != NULL) {
			for(int i = 0; i < strlen(word->next->words); i++) {
				tokenWord *wordNew = (struct tokenWord*) malloc(sizeof(tokenWord));
				char *currentText = (char *) malloc(sizeof(char) * 1000);
				int j = 0;
				for(j; j < strlen(word->words); j++) {
					currentText[j] = word->words[j];
				}
				currentText[j] = word->next->words[i];
				currentText[j + 1] = '\0';

				wordNew->words = currentText;
				wordNew->next = word->next->next;
				if(checkContains(currentText) == 1)
					push(wordNew);
			}
		}
		else {
			result += checkExistsWord(word->words);
		}
	}
	return result;
}

int checkExistsWord(char *word) {
	for(int i = 0; i < D; i++) {
		if(strcmp(word, wordInAlienLanguage[i]) == 0)
			return 1;
	}
	return 0;
}

int checkContains(char *word) {
	for(int i = 0; i < D; i++) {
		if(strstr(wordInAlienLanguage[i], word) != NULL)
			return 1;
	}
	return 0;
}

void push(tokenWord * node) {
	for(int i = size; i >= 1; i--){
		queue[i] = queue[i-1];
	}
	queue[0] = node;
	size++;
}

tokenWord *pop() {
	tokenWord *result;
	if(size > 0) {
		result =  queue[size - 1];
	}
	else {
		result = NULL;
	}
	size--;
	return result;
}

int readInput(char *fileName) {
	FILE *file;
	file = fopen(fileName, "r");
	
	fscanf(file, "%d", &L);
	fscanf(file, "%d", &D);
	fscanf(file, "%d", &N);
	//Igonre break line code
	fgetc(file);
	
	for(int i = 0; i < D; i++) {
		wordInAlienLanguage[i] = (char *) malloc(sizeof(char) * 1000);  
		fgets(wordInAlienLanguage[i], 1000, file);
		strtok(wordInAlienLanguage[i], "\n");
	}
	
	for(int k = 0; k < N; k++) {
		char data[1000];
		fgets(data, sizeof(data), file);
		if(data[strlen(data) - 1] == '\n')
			data[strlen(data) - 1] = '\0';
		tokenWord *first = NULL;
		for(int i = 0; i < strlen(data); i++) {
			tokenWord *word = (struct tokenWord*) malloc(sizeof(tokenWord));
			word->words = (char *) malloc(sizeof(char) * 1000);
			word->next = NULL;
			int j = 0;
			if(data[i] == '(') {
				while(data[++i] != ')'){
					word->words[j++] = data[i];
				}
			}
			else {
				word->words[j++] = data[i];
			}
			word->words[j] = '\0';
			if(first == NULL)
				first = word;
			else {
				tokenWord *temp = first;
				while(temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = word;
			}
		}
		cout << "Case #" << k + 1 << ": " << counWords(first) << "\n";
	}
}
