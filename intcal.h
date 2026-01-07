#ifndef _intcal_h_
#define _intcal_h_

#define TRUE	1
#define FALSE	0
/******************************
 intarg... integer calc 

 3rd-param(char) 
	1:add
	2:sub
	3:mul
	4:div
	5:mod
 ******************************/
int intcal(const char * a, const char * b, char t_calc, char **result);
int isdigits(char* av);

#endif
