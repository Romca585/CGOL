#include <stdio.h>
#include <string.h>

/* 
 * Program Name: reduceSpace.c
 * Author(s): Roman Savelyev
 * Purpose: replaces all extra spaces and tabs
 */ 


/*function is used in order to remove the spaces between 1s and 0s in the .seed files*/

int reduceSpace ( char* line ) {
    int index = 0;
    int x1 = 0;
    int x2 = 0;

	while(index < strlen(line)-1){
		if ( (line[index] == 32) || (line[index] == 9) ){
			x1 = 0;
			while( (line[index] == 32) || (line[index] == 9) ) { /*Scans for spaces and tabs, and then adds one to x1 every time a consecutive index is a space or tab*/
				x1++;
				index++;
			}if (x1 > 0){
				x2 = index; /*using x1, the program moves the indexes over in order to 'remove' the space/tabs*/
				while(x2-x1 < strlen(line)-x1){
					line[x2-x1] = line[x2];
					x2++;
				}
			}line[strlen(line)-x1] = 0;
			   
		}else if ( (line[index] != 32) || (line[index] != 9) ){
			index++;
		}
				    
	}


return(0);
}
