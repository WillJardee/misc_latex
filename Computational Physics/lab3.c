#include <stdio.h>
#include <math.h>
#include <time.h>	//For a 'random' seed for rand

// intializing all the functions that will be called
void randomNumbers();

int srand();
int rand();
double sqrt();

int main(){
	randomNumbers();	//A interior function that does all the work
	return(0);
}

void randomNumbers(){
	long integers, upperLimit, randomNum;	//The parameters given by the user

	printf("Enter the number of random integers to generate: ");
	scanf(" %li", &integers);
	printf("Enter the upper limit of numbers to generate: ");
	scanf(" %li", &upperLimit);

	long small = upperLimit + 1;	//This sets the "smallest" value to a value larger than possible, so the first generated value must replace it
	long large = 0;			//This sets the "largest" value to the smallest possible value, so either all values are 0, or a value will replace it
	double average, stdDev, sum, sumSquares; //sum and sumSquares are initally set at double to avoid issues with casting later in the program
	int i;

	srand(time(NULL));		//The time giveds a good ilusion to a random seed, so we will start there
	for (i=0; i<integers; i++){
		randomNum = rand() % (upperLimit) + 1;		
		//The modulus of some value and the max plus one will return a value less than the max plus one
		
		if (small > randomNum){
			small = randomNum;	
			//If the smallest recorded value is bigger than the current value we will record this new lowest
		}
		
		//I thought about an else if here to speed things up, but that neglects the case that integers = 1
		if (large < randomNum){
			large = randomNum;
			//Just like for the small, checks if we have a new largest
		}
		sum += randomNum;
		//Summing the numbers for later calculations
		sumSquares += pow(randomNum, 2);
		//Summing the number's squares for later calculations
	}
	average = sum/integers;
	stdDev = sqrt(sumSquares/integers - pow(average, 2));
	//Using the equations for averaging and standard deviation - I assume that the randomNumbers function is satisfactory for the function for average and std dev. Adding those functions would needlessly add more lines to the code.

	printf("\nWith %li numbers from 1 to %li, generated randomly:\n", integers, upperLimit);
	printf("Smallest: %li, Largest: %li, Average: %.2lf, Std Deviation: %.2lf.\n", small, large, average, stdDev);
}
