#include <stdio.h>

//	assert() evaluates an expression, if 0 prints out an error message in STDOUT 
#include <assert.h> 

//	Provides malloc(), free(), NULL, maybe strdup()? 
#include <stdlib.h> 
#include <string.h> 

//	Practicing struct: Created a Class struct that contained a Teahcer struct. 
//	malloc() knows how much memory to allocate for struct Teacher when I malloc'd sizeof(struct Class)


struct Teacher {
	char *name; 
	char *year; 
	int age; 
	double height; 
	double weight; 

}; 

struct Teacher *Teacher_create(char *name, char *year, int age, double height, double weight) {
	struct Teacher *who = malloc(sizeof(struct Teacher)); 
	assert(who != NULL); 

	who->name = strdup(name); 
	who->year = strdup(year); 
	who->age = age; 
	who->height = height; 
	who->weight = weight; 

	return who;
}

void Teacher_destroy(struct Teacher *who) {
	assert(who != NULL); 

	free(who->name); 
	free(who->year);
	free(who); 
}

void Teacher_print(struct Teacher *who) {
	assert(who != NULL); 

	printf("Name: %s\n", who->name);
	printf("\tYear: %s\n", who->year);
	printf("\tAge: %d\n", who->age); 
	printf("\tHeight: %2.0f\n", who->height); 
	printf("\tWeight: %2.0f\n", who->weight); 
}

struct Class {
	struct Teacher *this_teacher; 
	char *class_name; 
	int class_size; 

};

struct Class *Class_create(char *class_name, int class_size) {
	struct Class *this_class = malloc(sizeof(struct Class)); 
	assert(this_class != NULL); 
	struct Teacher *this_teacher = Teacher_create("Generic", "Generic", 25, 170, 145); 

	this_class->this_teacher = this_teacher;
	this_class->class_name = strdup(class_name); 
	this_class->class_size = class_size; 

	return this_class;
}

void Class_destroy(struct Class *this_class) {
	assert(this_class != NULL); 

	Teacher_destroy(this_class->this_teacher); 
	free(this_class->class_name); 
	free(this_class); 
}

void Class_info(struct Class *this_class) {
	assert(this_class != NULL); 

	Teacher_print(this_class->this_teacher); 
	printf("\tClass Name: %s\n", this_class->class_name); 
	printf("\tClass Size: %d\n", this_class->class_size);

}

int main(int argc, char *argv[]) {
	struct Class *biology = Class_create("Biology", 32);

	Class_info(biology);

	replace_name(biology->this_teacher, "James");
	biology->this_teacher->age = 43; 

	Class_info(biology);
	Class_destroy(biology);

	return 0;
}