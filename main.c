#include <stdio.h>

int main(int argc, char *argv[]) { 
	int age = 19;
	char initial = 'J'; 
	char last_initial = 'Z'; 
	char name[] = "Jack Zheng"; 
	char address[] = "2040 E 28th Street"; 
	double height = 67.75; 
	char university[] = "Stony Brook University"; 

	printf("I have a friend named %s.\n", name);
	printf("His first initial is %c and last initial is %c.\n", initial, last_initial);
	printf("I believe his age is %d.\n", age); 
	printf("He lives at %s when he is not at school.\n", address);
	printf("He goes to %s.\n", university);
	printf("His height is %f.\n", height);

	return 0;

}