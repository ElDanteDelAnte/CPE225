//Sean Reddell
//Shiv Sulkar
//CPE225
//Lab 6

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WORDLIMIT 4096
#define CHARLIMIT 32
//FUNCTIONS
int function1a();
int function1b(int a, int b);
int function3(int x, int y, int z);
void fileToScreen();
void uniquewords();

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
    fileToScreen();
    uniquewords();
  }

//PART1a
int function1a(){
	printf("J value = %d, Y value = %f, C value = %c, S value = %s\n", j , y,c, &s[0]);
	return 0;
}

//PART1b
int function1b(int a, int b){
	j=a;
	y=b;
	return 0;
}

void fileToScreen(){
	FILE* input = fopen("toScreen.txt", "r");
	
	//Write a program to open a text file for input and display it on the screen.
	char content = NULL;
	while (content != EOF)
	{
		fscanf("%c", &content);
		printf("%c", content);
	}
	
	fclose(input);
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



void uniquewords(){
	
	FILE* input = fopen("inputFile.txt","r");
	char temp[CHARLIMIT];
	char words[WORDLIMIT][CHARLIMIT];
	int wordRepeats[WORDLIMIT];
	int uniqW = 0;
	int status;
	
	//until end of file/array full
	for (status = fscanf(input, "%s", temp);
             status != EOF && uniqW <= WORDLIMIT;
             status = fscanf(input, "%s", temp))      //read a word
	{
		int unique = 1;    //boolean
		temp[31] = '\0';   //ensure null-termination
		
		//check if unique
                for (int i = 0; i < uniqW; i++)
                {
                        //if duplicate
                        if (strcmp(temp, words[i]) == 0)
                        {
                                wordRepeats[i] = wordRepeats[i] + 1;
                                unique = 0;
                        }
                }
	        //didn't find duplicate
                if (unique)
                  strncpy(words[uniqW++], temp, CHARLIMIT);
	
	}
	
	//print count
	printf("There are %d different words.\n", uniqW);
}








