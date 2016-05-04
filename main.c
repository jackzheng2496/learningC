#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

/*
	Declaring struct of type string using typedef
	I can now refer to struct string as just 'string'

	value: Contains a single pointer to a series of characters
*/
typedef struct string {
	char *value;

} string;


/*
	Custom implementation of strcat 
	Input two char pointers c1 and c2, concetenate c2 to the end of c1 

	TODO: Some crazy errors happening here, need to be reviewed.
*/
char *strcat_custom(char *str1, const char *str2) {
	char *str_end = str1 + strlen(str1);								// Move pointer to null terminator
	str1 = (char *) realloc(str1, strlen(str1) + strlen(str2) + 1); 	// Reallocate enough memory for str1 to contain both values							

	while ((*str_end++ = *str2++));
	*str_end = '\0';

	return str1;
}
/*
	Custom implementation of strdup
	Takes in a char pointer and duplicates the value to another pointer
	using strcpy
*/
char *strdup_custom(const char *value) {
	char *ptr = malloc( strlen(value) + 1 );		// Allocate enough memory for value + one more byte for '\0'
	assert(ptr != NULL);							// Always assert that memory returned is not NULL

	memset(ptr, '\0', strlen(value) + 1);			// Always memset memory allocated from malloc
	strcpy(ptr, value);								// Copy value from char *value to ptr

	return ptr;
}
/*
	Buggy implementation of creating a new string struct with its
	value set to value.

	The new string is made using malloc. It is then checked to see if the
	value returned by malloc is valid. I then memset it to guranteed that
	the memory allocated by malloc is zeroed out.

	Not too sure what strcpy does, but what I wanted it to do was create
	a new char pointer that pointed to a series of characters identical to
	that of char *value.
*/
string *make_string(const char *value) {
	string *new_string = malloc( sizeof(string) );
	assert(new_string != NULL);

	memset(new_string, '\0', sizeof( string )); 	// Always memset memory allocated from malloc

	new_string->value = strdup_custom(value);		// strdup(const char *value) Returns a pointer to memory loaded with the value specified

	return new_string;
}

/*
	A more bookkeeping way to free memory.
	Assert that the value passed in is not null then
	proceed to free the memory allocated from malloc
*/
void string_destroy(string *new_string) {
	assert(new_string != NULL);

	free(new_string->value);
	free(new_string);

}

/*
	This simple program prints out "Hello, World!" if no arguments were passed in from
	command line. Otherwise, it (should) create a new string struct for every argument,
	print out its value, then return the memory used by making the struct.

	Edit: Works! Had to use strdup instead of strcpy.
*/
int main(int argc, char *argv[]) {
	printf("Hello, World!\n");
	char *s = strdup_custom("jack");
	char *str = strdup_custom("zheng");

	char *temp = strcat_custom(s, str); 
	printf("Value is now: %s\n", temp);
	free(temp);
	free(str);

	if (argc > 1) {
		for (int i = 0; i < argc; i++) {
			string *new_string = make_string(argv[i]);
			printf("The value of argument is: %s\n", new_string->value);
			string_destroy(new_string);
		}
		printf("Finished printing out optional arguments\n");
	}
	return 0;
}
