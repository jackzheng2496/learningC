#include <stdio.h> 
#include <ctype.h>
#include <string.h> 

void print_string(char argv[]); 
int is_vowel(char ch);

void print_args(int argc, char *argv[]) {
	int i = 0; 

	for(i = 0; i < argc; i++) {
		print_string(argv[i]);
	}
}


void print_string(char argv[]) {
	int i = 0;

	for(i = 0; i < strlen(argv); i++) {
		char ch = argv[i];

		if(ch >= 65 && ch <= 90) {
			ch += (32 - i);
		} else if(ch >= 97 && ch <= 122) {
			ch -= (32 - i);
		} else {
			continue;
		}

		if(is_vowel(ch) == 1) {
			printf("%c%d", ch, ch);
		} else {
			printf("%c%c", ch, ch);
		}
	}

	printf("\n");
}

int is_vowel(char ch) {
	int vowel = 1; 

	switch(ch) {
		case 'a':
		case 'A': 
		case 'e': 
		case 'E': 
		case 'i': 
		case 'I': 
		case 'o': 
		case 'O': 
		case 'u': 
		case 'U': 
			vowel = 1; 
			break; 
		default: 
			vowel = 0;
	}

	return vowel;
}

int main(int argc, char *argv[]) {
	print_args(argc, argv);

	return 0;
}