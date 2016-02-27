//Sean Reddell
//Shiv Sulkar
//CPE225
//Lab 6

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>
//FUNCTIONS
int function1a();
int function1b(int a, int b);
int function3(int x, int y, int z);

//VARIABLES
int j;
float y;
char c;
char s[128]; /* (string) */

//MAIN
int main()
  {
	int f = function3(1,2,3);
	f = function1b(5,6);
    f = function1a();
  }

//PART1a
int function1a(){
	printf("J value = %d, Y value = %f, C value = %c, S value = %s", j , y,c, &s[0]);
	return 0;
}

//PART1b
int function1b(int a, int b){
	j=a;
	y=b;
	return 0;
}

int function2(){
	//Write a program to open a text file for input and display it on the screen.
	return 0;
}

int function3(int x, int y, int z){
	//(xxx)yyy-zzzz
	int i;
	s[0] = '(';
	for(i = 1; i<13;i++){
		if((i>=1)&&(i<=4)){
			if(i<=3){
				s[i]=x+'0';
			}
			else{
				s[i]=')';
			}
		}
		else if((i>=5)&&(i<=8)){
			if(i<8){
				s[i] = y+'0';				
			}
			else{
				s[i] = '-';				
			}
			
		}
		else{
			s[i] = z+'0';
		}
	}
	return 0;
}