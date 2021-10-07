#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "cgolfunc.h"


int main ( int argc, char *argv[] ) {
   system("clear");
   

   if (argc != 5){
       printf("Usage: ./dynCGOL <filename.seed> <ticks> <rows> <collumns>\n");
       return(-1);
   }


   int ROWS = 0;
   int COLLUMNS;
   int numTicks;
   int d;
   int repetition = 0;
   int liveCells = 0;
   int deadCells = 0;
   numTicks = atoi(argv[2]);
   ROWS = atoi(argv[3]);
   COLLUMNS = atoi(argv[4]);
   int rowCounter = 0;
   int collumnCounter;
   FILE *f;
   FILE *f1;
   int row = 0;
   int i;
   int j;
   char cont[2];
   int cont1 = 1;
   char start[2];
   char line[500];
   char line1[500];
   int collumn = 0;
   int index1;
   int index2;
   int ticks = 1;
   char *worldOne[ROWS][COLLUMNS];
   char *updatedWorld[ROWS][COLLUMNS];



	if ( (f = fopen(argv[1], "r")) != NULL ){
		
		while ( fgets ( line1, 100, f ) != NULL ){
			rowCounter++;
			
		}
		collumnCounter = strlen(line1)/2;

		if((rowCounter != ROWS) || collumnCounter != COLLUMNS){
		    return(-1);
		}
	} else {
	      printf ( "Cannot open %s\n", argv[1] );
	      return ( -2 );
	}

		/*2 same files are opened, one is to check number if rows/cols, the other to get inputs*/

	f1 = fopen(argv[1], "r");
	while ( fgets ( line, 100, f1 ) != NULL ){  
	    reduceSpace(line); /*using this to remove spaces in the .seed files*/
	    collumn = 0;
	    index1 = 0;
	    while (index1 < strlen(line)){
	        if (line[index1] == 49){
	            worldOne[row][collumn] = "X";
	            collumn++;			/*converts 1s an 0s to Xs and blanks*/
	        }else if (line[index1] == 48){
	            worldOne[row][collumn] = " ";
	            collumn++;
	        }
	        index1++;
            }
	    row++;
        }

	printf(" ");
	for (d = 0; d < COLLUMNS; d++){  /*top border of the box*/
	    printf("-");
	}

        printf("\n");
	for (i = 0; i < ROWS; i++){
	    for (j = 0; j < COLLUMNS; j++){
		if(j == 0){
		    printf("|"); /*while printing the world, also prints the side of the boxes*/
		}
		printf("%s",worldOne[i][j]);
		if(j == COLLUMNS - 1){
		    printf("|");
		}
	
	    }
	printf("\n");
	}

   printf(" ");
   for (j = 0; j < COLLUMNS; j++){ /*bottom of the box + tick counter once the last "-" is printed*/
       printf("-");
   }


   printf("\nStart? (y or n)\n"); /*asks user if they want to begin, asks again if wrong imput*/
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
	   for(index2 = 0; index2 < numTicks;index2++){
		system("clear");
		for (i = 0; i < ROWS; i++){
		    for (j = 0; j < COLLUMNS; j++){	/*below the program defines how many dead or alive*/
			liveCells = 0;			/*neighbours each cell has*/
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
				    deadCells++;	/*looks at a scenario where program is looking*/
							/*at the first cell located at 0,0*/
				}if (*worldOne[i+1][j+1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
			     	}


			     }else if(j == COLLUMNS - 1){

				if (*worldOne[i][j-1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
				
				}if (*worldOne[i+1][j] == 'X'){ /*looks at the last cell in the first row*/
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
				    deadCells++;/*looks at all OTHER possible first row possibilities*/
				

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




			}else if (i == ROWS - 1){ /*looks at last row*/
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


			     }else if(j == COLLUMNS - 1){

				if (*worldOne[i][j-1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
				
				}if (*worldOne[i-1][j] == 'X'){ /*last row, last character*/
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

				}if (*worldOne[i][j+1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;
				

				}if (*worldOne[i-1][j] == 'X'){ /*all other in last row*/
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



				
			    }else if(j == COLLUMNS - 1){
				if (*worldOne[i][j-1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;

				}if (*worldOne[i+1][j-1] == 'X'){ /*row unspefic, looks at last character*/
				    liveCells++;		  /* in each*/
				}else{
				    deadCells++;
				

				}if (*worldOne[i-1][j-1] == 'X'){
				    liveCells++;
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
				    deadCells++;

				
				}if (*worldOne[i+1][j+1] == 'X'){
				    liveCells++;
				}else{
				    deadCells++;  /*once all exceptions are finished being looked at*/
						  /*program looks at all oter possibilities*/

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
				updatedWorld[i][j] = " "; /*applies the rules of the game to each cell*/
			    }
			}else if (*worldOne[i][j] == 'X'){
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
	          for (i = 0; i < ROWS; i++){ /*this chunk checks for repetitions between 2 ticks*/
		    for (j = 0; j < COLLUMNS; j++){ 
                        if (worldOne[i][j] == updatedWorld[i][j]){
			    repetition++;
                        }
                    }
		  }if (repetition > (ROWS * COLLUMNS-1) ){ /*if repetition found program is terminated*/
			    return(0);
		  }


		  printf(" ");
		  for (j = 0; j < COLLUMNS; j++){ /*prints top of box*/
		       printf("-");
		  }
                  printf("\n");
		  for (i = 0; i < ROWS; i++){
		    for (j = 0; j < COLLUMNS; j++){
			if(j == 0){
			    printf("|");
			}
			printf("%s",updatedWorld[i][j]); /*prints the new world + sides of box*/
			if(j == COLLUMNS - 1){
			    printf("|");
			}
			
			worldOne[i][j] = updatedWorld[i][j];
		    }
		  printf("\n");
		  }
		   printf(" ");
	   for (j = 0; j < COLLUMNS; j++){
	       printf("-");  /*prints bottom of box + tick counter*/
	       if (j == COLLUMNS - 1){
		   printf("%d",ticks);
	       }
	   }printf("\n");

	   system("sleep 0.25"); /*system pauses and repeats as specified*/
	   ticks++;
		
   	}printf("Continue? (y or n)\n");/*repeats the number of ticks again*/
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
