#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* wstrim(char* s);

void main(int argc, char* argv[]){
	// printf("\n");

	if(argc >= 2){
		printf("shell accepts 0 or 1 arguments\n");
		exit(1);
	}

	char* s = (char*) malloc(sizeof(char)*100);
	size_t size = sizeof(char)*100;
	while(1){
		printf("shell> ");
		getline(&s, &size, stdin);
		s = wstrim(s);
		if(strcmp(s, "exit") == 0){
			break;
		}
	}

	exit(0);
}

char* wstrim(char* s){
	while(isspace(s[0])){
		s = &(s[1]);
	}
	while(isspace(s[strlen(s)-1]))
		s[strlen(s)-1] = '\0';
	return s;
}