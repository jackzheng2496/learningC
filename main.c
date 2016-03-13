#include <stdio.h> 
#include <string.h> 

#define INPUT 95

void fill_array(char args[], int *ptr);
int find_max(int *ptr, int size);

int main(int argc, char *argv[]) {
	int i = 0; 

	//Hard-coded number of user-inputted characters
	int args[INPUT] = {0};
	int *ptr = args; 

	for (i = 0; argv[i] != '\0'; i++) {
		fill_array(argv[i], ptr);
	}

	int max_int = find_max(ptr, INPUT);

	for (i = max_int; i > 0; i--) {
		printf("%d ", i);

		for (int j = 0; j < INPUT; j++) {
			if (args[j] >= i) {
				printf("|");
			} 
		}

		printf("\n");
	}

	printf("  ");

	for (i = 0; i < INPUT; i++) {
		if (args[i] > 0) {
			printf("%c", i + 32);
		}
	}

	printf("\n");

	return 0;
}

void fill_array(char args[], int *ptr) {
	int i = 0; 

	for (i = 0; args[i] != '\0'; i++) {
		char ch = args[i]; 
		ch = ch - 32;	//Zero index the character 

		*(ptr + ch) = *(ptr + ch) + 1;
	}
}

int find_max(int *ptr, int size) {
	int i = 0; 
	int max_int = 0; 

	for (i = 0; i < size; i++) {
		if (*(ptr + i) > max_int) {
			max_int = *(ptr + i);
		}
	}

	return max_int;
}

