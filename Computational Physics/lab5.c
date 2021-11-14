#include<stdio.h>
#include<string.h>		//for strcmp
#include<math.h>		//for pow
#include<stdlib.h>		//for malloc

//Initializing functions
int search(char*[], int, char*);

int main(){
	//Initializing the values given for resistors
	char *colors[11] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "grey", "white"};
	int values[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 8, 9};

	//Initializing all other values uses
	char ans;
	int targetVal, band1Val, band2Val, band3Val, valid;
	double resistorValue;

	do{
		//To avoid a segmentation error and size error these are recreated everytime.
		//In a real program I would desire to find a way to do this that doesn't waste so much space.
		char* band1 = (char*) malloc(sizeof(char)*30);
		char* band2 = (char*) malloc(sizeof(char)*30);
		char* band3 = (char*) malloc(sizeof(char)*30);

		//Sets the initial condition to valid
		valid = 1;

		printf("Enter the colors of the resistor's three bands, beginning with the band nearest the end. Type the colors in lowercase letters only, NO CAPS.\n");	
	
		//Checking for band 1
		printf("Band 1 => ");
		scanf("%s", band1);
		targetVal = search(colors, 11, band1);
		//Each time if the value is not found (returning -1), then prints "invalid color" and sets valid to 0
		if(targetVal != -1){
			band1Val = values[targetVal];
		} else{
			printf("Invalid color: %s\n", band1);
			valid = 0;
		}

		//For band 2 and 3 the process is the same, except now we check for validity before asking for the band color
		if(valid == 1){
			printf("Band 2 => ");
			scanf("%s", band2);
			targetVal = search(colors, 11, band2);
		if(targetVal != -1){
			band2Val = values[targetVal];
		} else{
			printf("Invalid color: %s\n", band2);
			valid = 0;
		}}	

		if(valid == 1){
			printf("Band 3 => ");
			scanf("%s", band3);
			targetVal = search(colors, 11, band3);
		if(targetVal != -1){
			band3Val = values[targetVal];
		} else{
			printf("invalid color: %s\n", band3);
			valid = 0;
		}}

		//If everything is valid up this point, calculate the resistor value as described in the problem
		if(valid == 1){
			resistorValue = (band1Val*10 + band2Val)*pow(10,band3Val-3);
			printf("Resitance value : %.1lf kilo-ohms\n", resistorValue);
		}

		//Prompts the user if they want to repeat until they give a y or n.
		printf("Do you want to decode another resistor?\n=> ");
		scanf(" %c", &ans);	

		//Checks for a valid 'n', or 'y' for the answer and asks again if it not
		while(ans!='n' && ans!='N' && ans!='y' && ans!='Y'){
			printf("Bad answer, try again\n");
			printf("Do you want to decode another resitor?\n=> ");
			scanf(" %c", &ans);
		}
	//if a n is given the code doesn't rerun
	}while(ans != 'n' && ans != 'N');	
}


//Helper search method to look for strings in an array 
int search(char *colors[], int listSize, char* target){
	int targetVal = -1;		//If there is no change -1 is returned
	for(int i=0; i<listSize; i++){
		//goes through each value in the colors list and checks if the given string matches with strcmp
		if(strcmp(colors[i], target) == 0){
			targetVal = i;
		}
	}						
	return targetVal;
}
