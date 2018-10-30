#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	//variables for the user
   	char str[100];
    	size_t length = 0;
	int j = 0, lowRank = 0, highRank = 0;
	long mID = 0;

	int pseudoID = 0;
	long double tempID;
	long double last;
	ssize_t stringID;
	char *throwAway = NULL;

	//ask user to enter ID
    	printf( "Enter an ID: " );
	//get the line from the user input
    	stringID = getline(&throwAway, &length, stdin);
	//convert the string to an integer
    	mID = strtol(throwAway, NULL, 10);

	//ask user to low rank
    	printf( "Enter a low rank: " );
	//reset variables
	throwAway = NULL;
	length = 0;
	//get the line from the user input
    	stringID = getline(&throwAway, &length, stdin);
	//convert the string to an integer
    	lowRank = strtol(throwAway, NULL, 10);

	//ask user to high rank
    	printf( "Enter a high rank: " );
	//reset variables
	throwAway = NULL;
	length = 0;
	//get the line from the user input
    	stringID = getline(&throwAway, &length, stdin);
	//convert the string to an integer
    	highRank = strtol(throwAway, NULL, 10);
	
	printf("\n");

	if(mID == 0 || lowRank == 0 || highRank == 0)
	{
		//ask user again in case something went wrong
		printf( "Enter an ID: " );
	    	stringID = getline(&throwAway, &length, stdin);
	    	mID = strtol(throwAway, NULL, 10);

	    	printf( "Enter a low rank: " );
		throwAway = NULL;
		length = 0;
	    	stringID = getline(&throwAway, &length, stdin);
	    	lowRank = strtol(throwAway, NULL, 10);

	    	printf( "Enter a high rank: " );
		throwAway = NULL;
		length = 0;
	    	stringID = getline(&throwAway, &length, stdin);
	    	highRank = strtol(throwAway, NULL, 10);
		//go through each rank from the user input
		for(j = lowRank; j <= highRank; ++j){
			//set a temporary ID to apply things to
			tempID = mID;
			//divide the temporary ID 2.5
			tempID /= 2.5;
			//Add the rank to the temporary ID
			tempID += j;
			//Multiply the ID by 2
			tempID *= 2.0;
			//get ceiling operator
			last = roundl(tempID);
			//assign it to an int
			pseudoID = last; 
			//print out results
			printf("\n%d", pseudoID);
			printf(", %d ", j);
		}
		
	}
	else{
		//go through each rank from the user input
		for(j = lowRank; j <= highRank; ++j){
			//set a temporary ID to apply things to
			tempID = mID;
			//divide the temporary ID 2.5
			tempID /= 2.5;
			//Add the rank to the temporary ID
			tempID += j;
			//Multiply the ID by 2
			tempID *= 2.0;
			//get ceiling operator
			last = roundl(tempID);
			//assign it to an int
			pseudoID = last; 
			//print out results
			printf("\n%d", pseudoID);
			printf(", %d ", j);
		}

	}

	printf("\n");
    	return 0;

}

