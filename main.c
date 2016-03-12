#include <stdio.h> 

int main(int argc, char *argv[]) {
	int ages[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
	char *names[] = {"jack", "juby", "jorman", "jick"}; 

	//Pointer to ages 
	int *cur_age = ages; 

	//Pointer to names which in itself, is a pointer to "jack"
	char **cur_name = names;

	//All types of pointers are 8 bytes in 64 bit systems
	printf("%ld\t%ld\n", sizeof(cur_name), sizeof(cur_age));

	int size = sizeof(names) / sizeof(cur_name);

	int i = 0;

	for (i = 0; i < size; i++) {
		printf("The age of %s is %d\n", *(cur_name + i), *(cur_age + i));
	}

	return 0;
}