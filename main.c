#include <stdio.h>
#include <ctype.h>

#define MAX_INPUT 1000

void compute(char input[]);
int getvalue(char *input, int *ptr);

int main(int argc, char *argv[]) {
	char c; 
	int i = 0;
	char input[MAX_INPUT];

	while ((c = getchar()) != EOF) {
		input[i++] = c;
	}

	input[i] = '\0';
	compute(input);

	return 0;
}

void compute(char input[]) {
	int i = 0;
	int *ptr = &i;
	int arg1, arg2;
	arg1 = arg2 = 0;
	char op;

	for (i = 0; input[i] != '\0'; i++) {
		char c = input[i]; 

		if (isdigit(c)) {
			if (arg1 && !arg2)
				arg2 = getvalue(&input[i], ptr);
			if (!arg1) 
				arg1 = getvalue(&input[i], ptr);
			i = *ptr;
		}

		if (c == '+' || c == '-' || c == '*' || c == '/')
			op = c; 

		if (arg1 && arg2 && op) {
			switch (op) {
				case '+':
					arg1 = arg1 + arg2; 
					break; 
				case '-':
					arg1 = arg1 - arg2; 
					break;
				case '*':
					arg1 = arg1 * arg2; 
					break;
				case '/':
					arg1 = arg1 / arg2; 
					break; 
					
			}

			printf("%d\n", arg1);
			arg1 = arg2 = 0; 
			op = 0; 

		}

	}
}

int getvalue(char *input, int *index) {
	int i = 0; 
	int total = 0;

	for (i = 0; isdigit(*(input + i)); i++) {
		total = total * 10 + (*(input + i) - '0');
	}
	
	*index = *index + i;

	return total;
}