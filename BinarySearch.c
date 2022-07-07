// *Made by IsacJSantos*
// This piece of code was made to compare simple search and binary search speeds

#include <stdio.h>

//Prototypes
int BinarySearch(int start, int end, int arg);
int SimpleSearch(int arg);

// Constants
#define length 1000

//Global Variables1
int Numbers[length];
int BSIterations = 0; // The binary search total iterations
int SSIterations = 0; // The simple search total iterations

int main(void) {
	
  	printf("=-=-=-=-= Binary Search vs Simple Search =-=-=-=-=\n\n");	
  
  	// Fill the array
  	for(int i = 1; i <= length; i ++){
  		Numbers[i - 1] = i;
  	}
  	
  	// get user input
  	int input = 0;
  	printf("Enter a number from 0 to %d: ",length);	
  	scanf("%d", &input);
  	printf("\n\n");	
  	
	printf("--- Binary Search ---\n\n");	
  	BinarySearch(0, length - 1, input);
	printf("BinarySearch Iterations: %d\n", BSIterations);
	
	printf("\n------------------------------\n\n");
	
	printf("--- Simple Search ---\n\n");	
	SimpleSearch(input);
	printf("SimpleSearch Iterations: %d\n", SSIterations);	
	
	printf("\n=-=-=-=-=-=-=-=-=-=\n\n");	
	
	system("pause");
  	return 0;
}

int BinarySearch(int start, int end, int arg){
	
	BSIterations++;
	if(start > end){
		printf("Not found\n");
		return - 1;
	}
	
	int mid = (start + end) / 2;
	if(Numbers[mid] == arg){
		printf("found %d in index %d\n", Numbers[mid], mid);
		return mid;
	}
	else if(Numbers[mid] < arg){
		return BinarySearch(mid + 1, end, arg);
	}
	else{
		return BinarySearch(start, mid -1, arg);
	}
	
}

int SimpleSearch(int arg){
	for(int i = 0; i < length; i++){
		SSIterations++;
		if(arg == Numbers[i]){
			printf("found %d in index %d\n", Numbers[i], i);
			return i;
		}
	}
	printf("Not found\n");
	return - 1;
}