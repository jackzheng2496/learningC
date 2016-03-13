Jack Zheng 
This will track my progress in learning the C language. 

- Testing another git commit. -3/8/16
- printf() is dangerous, be careful of the types while formatting. -3/8/16
- Arrays are in the format 'type name[]'. There aren't really set boundaries
  so if your array was lets say, int age[] = {1, 2, 3}, you can access
  age[100] and there wouldn't be a compilation error. The number that is 
  outputted varies and this is definitely can be a source of upcoming bugs.  
  -3/9/16
- Forward declarations allow use of functions before defining them. 
  Not too sure how that works because I thought C just read instructions from 
  top to bottom. I am assuming there exist some sort of jump command in place 
  of those predefined functions ?? -3/10/16
- Pointers hold the address of where the variables are being held in memory.
  ex) char *names[] = {"jack"}; 
      'names' hold the address of where the first element of the array is held
       in this case, 'names' points to "jack". 
  Pointers can be used to access the elements of an array the same way index
  works. 
  - 3/11/16
- Struct is a block of memory that groups data variables together. There are 
  two main methods of making structs. One is to allocate memory using malloc().
  All the variables of said struct are referenced through pointers x->y.
  Creating structs through malloc requires you to free up the memory used after.
  The second method is creating structs using the stack. You create the struct
  like how you normally create variables and the you can access the struct 
  variables through x.y. Using this method, you do not need to worry about
  memory leaks. -3/12/16
- Struct practice: When I tried to change a string in a struct, it gave me an 
  error about accessing memory I wasn't suppose to. I guess this is because 
  when strdup() allocated memory the string, it was specific to the string 
  that was available during creation. -3/13/16
