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
