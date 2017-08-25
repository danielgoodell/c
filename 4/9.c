/* 	Our getch and ungetch do not handle a pushed back EOF correctly. 
*	Decide what their properties out to be if an EOF is pushed back, 
*	then implement your design.
*/  

/*	Answer: after some research I found that old systems char was unsigned by default.
	EOF is defined as an integer with a value of -1 which could not be held by an 
	unsigned char. On my modern system, chars are by default signed and has no problem 
	storing a value of -1 so no changes are necessary. For a system that uses uchars
	the fix would be to define the buffer as an integer buffer so that is able to hold
	negative numbers.
*/
