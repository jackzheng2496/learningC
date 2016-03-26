#include <stdio.h> 
#include <ctype.h>

#define MAX_INPUT 100

void expand(char s[], char t[]);

int main(int argc, char *argv[]) {
	char s[] = "-0-9A-Da-d-kM-P-"; 
	char t[MAX_INPUT];

	expand(s, t);
	printf("%s\n", t);

	return 0;
}

void expand(char s[], char t[]) {
	char start; 
	int i, j, dash; 

	dash = start = j = 0; 

	for (i = 0; s[i] != '\0'; i++) {
		char c = s[i]; 

		if (isalnum(c) && start && dash) {
			for (int k = 0; k + start <= c; k++, j++) {
				t[j] = k + start;
			}

			start = dash = 0;

			if (s[i+1] == '-') {
				start = s[i];
			}

		} else {

			if (!start && isalnum(c)) 
				start = s[i]; 
			
			if (!dash && c == '-')
				dash = 1; 

			if ((dash && !start) || (dash && s[i+1] == '\0')) {
				t[j++] = '-';
			}
		}
	}
	t[j] = '\0';

}