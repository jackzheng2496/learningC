#include <stdio.h>

//	assert() evaluates an expression, if 0 prints out an error message in STDOUT 
#include <assert.h> 

//	Provides malloc(), free(), NULL, maybe strdup()? 
#include <stdlib.h> 
#include <string.h> 

struct Student {
	char *name;
	char *year; 
	int age; 
	int height;
	int weight; 

}; 

//	Allocate enough memory for struct Student and return a pointer to newly created struct
struct Student *Student_create(char *name, char *year, int age, int height, int weight) {
	struct Student *who = malloc(sizeof(struct Student)); 
	assert(who != NULL); 

	who->name = strdup(name); 
	who->year = strdup(year); 
	who->age = age; 
	who->height = height; 
	who->weight = weight; 

	return who; 
}

//	Free the memory used to create the struct 
void Student_destroy(struct Student *who) {
	assert(who != NULL); 

	free(who->name);
	free(who->year);
	free(who);
}

void print_student(struct Student *who) {
	printf("Name: %s\n", who->name);
	printf("\tYear: %s\n", who->year);
	printf("\tAge: %d\n", who->age); 
	printf("\tHeight: %d\n", who->height); 
	printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[]) {
	struct Student *jack = Student_create("Jack", "Sophomore", 19, 67, 140); 

	print_student(jack); 

	jack->age += 10; 
	jack->weight -= 10; 
	jack->height += 20; 

	print_student(jack); 
	//Student_destroy(jack); 

	return 0;
}