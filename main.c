#include <stdio.h> 

int main(int argc, char *argv[]) {
	int age[] = {19, 20, 24, 3, 5};

	//	Two ways of making strings in C  
	char name[] = "Jack Zheng";	// '\0' is implied

	//	'\0' is explicitly placed in this one
	char full_name[] = {'J', 'A', 'C', 'K', ' ', 'Z', 'H', 'E', 'N', 'G', '\0'};

	printf("My name is %s.\n", name);

	//	Prints out '11', null byte terminating the string
	printf("The amount of characters in name is: %ld\n", sizeof(name) / sizeof(char));
	printf("My other name is %s.\n", full_name);
	printf("The first element in age is %d.\n", age[0]);

	//	Apparently this does not give a compilation error, 
	//	value printed out is random each time. 
	printf("Lets try an element not in array's range %d.\n", age[100]);

	return 0; 

}