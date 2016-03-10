//Sean Reddell
//Shiv Sulkar
//CPE225
//Lab 5

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>


float my_sqrt(float x);
float sin_sqrt();

int main()
  {
    //TEST CASE 1
    float x = my_sqrt(2.0);
    printf("Root of 2.0: %f\n", x);
    
    //TEST CASE 2
    x = my_sqrt(5.0);
    printf("Root of 5.0: %f\n", x);
    
    //TEST CASE 3
    x = my_sqrt(25.0);
    printf("Root of 25.0: %f\n", x);
	
	
	//TEST SIN
	x = sin_sqrt();
	printf("sin function: %f\n", x);
	
	
    
    return 0;
  }

float my_sqrt(float x)
{
	float error = 0.000001;//allowed error
	float guess = 0;//just initializing the variable
	if(x>2){//because anything two of below requires is modified algorithm 
		guess = x/2;
		while(guess*guess-x>error){
			guess=guess-(((guess*guess)-x)/(2*guess));
		}
	}
	else{//anything 2 or below gives strange results
		guess = x/2;
		float quotient = x/guess;
		float average = (quotient+guess)/2;
		while((average*average-x)>error){
			guess = average;
			quotient = x/guess; 
			average =  (quotient+guess)/2;
		}
		guess = average;
	}
	return guess;
}
float sin_sqrt(){
	float error = 0.000001;//allowed error
	float guess1 = 3;
	float guess2 = 0;
	while(abs(guess1-guess2)>error){ // continue until the error is within range
		guess2 = guess1; // adjust the old guess 
		guess1 = guess1-tan(guess1); // compute the new guess
	}
	return guess1;
}