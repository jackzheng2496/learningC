#include <stdio.h> 
#include <stdlib.h>

typedef int (*operations)(int a, int b); 

void do_some(int a, int b, operations op) {
	int x = op(a,b); 
	printf("%d\n", x);
}

int mul_2(int a, int b) {
	return a * b; 
}

int add_x(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int main(int argc, char *argv[]) {
	int arg1 = atoi(argv[1]);
	int arg2 = atoi(argv[2]); 

	char *op = argv[3];

	switch (*op) {
		case 'm': 
			do_some(arg1, arg2, mul_2); 
			break;
		case 'a': 
			do_some(arg1, arg2, add_x); 
			break; 
		case 's': 
			do_some(arg1, arg2, sub); 
			break;
		default: 
			printf("Option invalid\n"); 
	}

	return 0;
}
