#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "limits.h"

//HINT: for distributions, 
//adding to all except 1 to equ =  substracting from 1 to equ

#define _arrcount(arr)  sizeof(arr)/sizeof(arr[0])


int max(int count,int* arr){
	int m = 0;

	for(int i = 0; i < count; i++){
		if(arr[i] > m){
			m = arr[i];
		}
	}


	return m;
}


int min(int count,int* arr){
	int m = INT_MAX;

	for(int i = 0; i < count; i++){
		if(arr[i] < m){
			m = arr[i];
		}
	}


	return m;
}


int equal(int arr_count, int* arr){

	int choices[] = {1,2,5};

	int dec = min(_arrcount(choices),choices);
	int total_rounds = max(_arrcount(choices),choices) / dec;
	int* round_array = malloc(sizeof(int) * total_rounds);
	memset(round_array,0,sizeof(int) * total_rounds);

	int cur_min = min(arr_count,arr);

	for(int i = 0; i < total_rounds; i++){
		int* cur = round_array + i;

		for(int j = 0; j < arr_count; j++){
			int diff = arr[j] - cur_min;
			for(int k = _arrcount(choices) - 1; k != -1; k--){
				int c = choices[k];
				*cur += diff /c; 
				diff = diff % c;
			}
		}

		cur_min -= dec;
	}

	int answer = min(total_rounds,round_array);
	free(round_array);

	return answer;
}



int main(int argc, char** argv){

	int arr[] = {10,7,12};
	int count = _arrcount(arr);

	int rounds = equal(count,arr);

	printf("MIN ROUNDS: %d\n",rounds);

	return 0;
}
