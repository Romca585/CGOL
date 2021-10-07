#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "cgolfunc.h"

int main ( int argc, char *argv[] ) {
   system("clear");
   int ROWS = 0;
   int COLLUMNS;
   int numTicks;
   int d;
   int repetition = 0;
   int liveCells = 0;
   int deadCells = 0;


   if (argc < 3){
       numTicks = 50;
   }else{
       numTicks = atoi(argv[2]);
   }
	
   FILE *f1;
   FILE *f;
   int row = 0;
   int i;
   int j;
   char cont[2];
   int cont1 = 1;
   char start[2];
   char line[500];
   char line1[500];
   int collumn = 0;
   int a;
   int b;
   int ticks = 1;
   char *worldOne[20][40];
   char *updatedWorld[20][40];

	if ( (argc > 3) || (argc < 2) ){
	    printf("Usage: ./cgol <filename.seed> <ticks>\n");
	    return(-1);
	}

	if ( (f = fopen(argv[1], "r")) != NULL ){
		
		while ( fgets ( line1, 100, f ) != NULL ){
			ROWS++;
			
		}
		COLLUMNS = strlen(line1)/2;
	} else {
	      printf ( "Cannot open %s\n", argv[1] );
	      return ( -2 );
	}	

	if((ROWS != 20) || COLLUMNS != 40){
	    return(-1);
	}

	/*2 same files are opened, one is to check number if rows/cols, the other to get inputs*/
	f1 = fopen(argv[1], "r");
	while ( fgets ( line, 100, f1 ) != NULL ){  
	    reduceSpace(line); /*using this to remove spaces in the .seed files*/
	    collumn = 0;
	    a = 0;
	    while (a < strlen(line)){
	        if (line[a] == 49){
	            worldOne[row][collumn] = "X";
	            collumn++;  /*converts 1s an 0s to Xs and blanks*/
	        }else if (line[a] == 48){
	            worldOne[row][collumn] = " ";
	            collumn++;
	        }
	        a++;
            }
	    row++;
        }

	printf(" ");
	for (d = 0; d < 40; d++){ /*top border of the box*/
	    printf("-");
	}

        printf("\n");
	for (i = 0; i < 20; i++){
	    for (j = 0; j < 40; j++){
		if(j == 0){
		    printf("|");  /*while printing the world, also prints the side of the boxes*/
		}
		printf("%s",worldOne[i][j]);
		if(j == 39){
		    printf("|");  
		}
	
	    }
	printf("\n");
	}

   printf(" ");
   for (j = 0; j < 40; j++){  /*bottom of the box*/
       printf("-");
   }


   printf("\nStart? (y or n)\n");  /*asks user if they want to begin, asks again if wrong imput*/
   scanf("%s", start);
   if ( (strcmp(start , "y") != 0) && (strcmp(start , "Y") != 0) &&(strcmp(start , "n") != 0) && (strcmp(start , "N") != 0)){
       while ( (strcmp(start , "y") != 0) && (strcmp(start , "Y") != 0) &&(strcmp(start , "n") != 0) && (strcmp(start , "N") != 0)){
           printf("Only the single characters Y or N are acceptable.\n");
           printf("Start? (y or n)\n");
           scanf("%s", start);
       }
   }if ( (strcmp(start , "n") == 0) || (strcmp(start , "N") == 0)){
	return(0);
   
   }else if ( (strcmp(start , "y") == 0) || (strcmp(start , "Y") == 0)){
	while(cont1 == 1){
	   for(b = 0; b < numTicks;b++){
		system("clear");
		for (i = 0; i < 20; i++){
		    for (j = 0; j < 40; j++){    /*below the program defines how many dead or alive*/
			liveCells = 0;           /*neighbours each cell has*/
	   		deadCells = 0;
			if (i == 0){ /*looks at the first row*/
			    if (j == 0){
			    	if (*worldOne[i][j+1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
				
				}if (*worldOne[i+1][j] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
				
				}if (*worldOne[i+1][j+1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;  /*looks at a scenario where program is looking*/
			     	}		  /*at the first cell located at 0,0*/


			     }else if(j == 39){

				if (*worldOne[i][j-1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
				
				}if (*worldOne[i+1][j] == 'X'){  /*looks at the last cell in the first row*/
				    liveCells++;
				}else{
				    deadCells++;
				
				}if (*worldOne[i+1][j-1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
			     	}

			     }else{
				 if (*worldOne[i][j-1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;

				}if (*worldOne[i][j+1] == 'X'){ 
				    liveCells++;
				}else{
				    deadCells++; /*looks at all OTHER possible first row possibilities*/
				

				}if (*worldOne[i+1][j] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
				
				}if (*worldOne[i+1][j+1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
			     	}if (*worldOne[i+1][j-1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
				}

			    }




			}else if (i == 19){ /*looks at last row*/
			    if (j == 0){
			    	if (*worldOne[i-1][j] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
				
				}if (*worldOne[i][j+1] == 'X'){ /*last row, first character*/
				    liveCells++;
				}else{
				    deadCells++;
				
				}if (*worldOne[i-1][j+1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
			     	}


			     }else if(j == 39){

				if (*worldOne[i][j-1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
				
				}if (*worldOne[i-1][j] == 'X'){  /*last row, last character*/
				    liveCells++;
				}else{
				    deadCells++;
				
				}if (*worldOne[i-1][j-1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
			     	}

			     }else{
				 if (*worldOne[i][j-1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;

				}if (*worldOne[i][j+1] == 'X'){ /*all other in last row*/
				    liveCells++;
				}else{
				    deadCells++;
				

				}if (*worldOne[i-1][j] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
				
				}if (*worldOne[i-1][j+1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
			     	}if (*worldOne[i-1][j-1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
				}

			    }

			}else{
			    if(j == 0){
				if (*worldOne[i][j+1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;

				}if (*worldOne[i+1][j+1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
				

				}if (*worldOne[i-1][j+1] == 'X'){ /*row unspefic, looks at first character*/
				    liveCells++;	          /* in each*/
				}else{
				    deadCells++;
				
				}if (*worldOne[i-1][j] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
			     	}if (*worldOne[i+1][j] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
				}



				
			    }else if(j == 39){
				if (*worldOne[i][j-1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;

				}if (*worldOne[i+1][j-1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
				

				}if (*worldOne[i-1][j-1] == 'X'){ /*row unspefic, looks at last character*/
				    liveCells++;		  /* in each*/
				}else{	
				    deadCells++;
				
				}if (*worldOne[i-1][j] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
			     	}if (*worldOne[i+1][j] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
				}



		            }else{

				if (*worldOne[i-1][j-1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;


				}if (*worldOne[i-1][j+1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
				

				}if (*worldOne[i-1][j] == 'X'){
				    liveCells++;
				}else{
				    deadCells++; /*once all exceptions are finished being looked at*/
						 /*program looks at all oter possibilities*/

				}if (*worldOne[i+1][j+1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;


			     	}if (*worldOne[i+1][j-1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;


				}if (*worldOne[i+1][j] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
				

				}if (*worldOne[i][j+1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;


			     	}if (*worldOne[i][j-1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;			

				}
			    }
			}
			if (*worldOne[i][j] == ' '){
			    if (liveCells == 3){
				updatedWorld[i][j] = "X";
			    }else{
				updatedWorld[i][j] = " ";
			    }
			}else if (*worldOne[i][j] == 'X'){ /*applies the rules of the game to each cell*/
			    if (liveCells < 2){
				updatedWorld[i][j] = " ";

			    }else if (liveCells == 2 || liveCells == 3){
				updatedWorld[i][j] = "X";

			    }else if (liveCells > 3){
				updatedWorld[i][j] = " ";
			    }
			}
		}
		    }
		  repetition = 0;
	          for (i = 0; i < 20; i++){ /*this chunk checks for repetitions between 2 ticks*/
		    for (j = 0; j < 40; j++){
                        if (worldOne[i][j] == updatedWorld[i][j]){
			    repetition++;
                        }
                    }
		  }if (repetition > (20 * 40-1) ){ /*if repetition found program is terminated*/
			    return(0);
		  }


		  printf(" "); /*prints top of box*/
		  for (j = 0; j < 40; j++){
		       printf("-");
		  }
                  printf("\n");
		  for (i = 0; i < 20; i++){
		    for (j = 0; j < 40; j++){
			if(j == 0){
			    printf("|"); /*prints the new world + sides of box*/
			}
			printf("%s",updatedWorld[i][j]);
			if(j == 39){
			    printf("|");
			}
			
			worldOne[i][j] = updatedWorld[i][j];
		    }
		  printf("\n");
		  }
		   printf(" ");
	   for (j = 0; j < 40; j++){
	       printf("-");
	       if (j == 39){ /*prints bottom of box + tick counter*/
		   printf("%d",ticks);
	       }
	   }printf("\n");

	   system("sleep 0.25"); /*system pauses and repeats as specified*/
	   ticks++;
		
   	}printf("Continue? (y or n)\n"); /*repeats the number of ticks again*/
	 scanf("%s",cont);
	 if ( (strcmp(cont , "y") != 0) && (strcmp(cont , "Y") != 0) &&(strcmp(cont , "n") != 0) && (strcmp(cont , "N") != 0)){
       	     while ( (strcmp(cont , "y") != 0) && (strcmp(cont , "Y") != 0) &&(strcmp(cont , "n") != 0) && (strcmp(cont , "N") != 0)){
           printf("Only the single characters Y or N are acceptable.\n");
           printf("Continue? (y or n)\n");
           scanf("%s", cont);
             }

	 }if ( (strcmp(cont , "n") == 0) || (strcmp(cont , "N") == 0)){
	     cont1 = 0;
	     return(0);
	
	 }else if ( (strcmp(cont , "y") == 0) || (strcmp(cont , "Y") == 0)){
	     cont1 = 1;
	 }
	}

    }	    

return(0);
}
