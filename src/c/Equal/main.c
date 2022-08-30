#include "stdlib.h"

#include "stdio.h"
#include "limits.h"

//HINT: for distributions, 
//adding to all except 1 to equ =  substracting from 1 to equ

#define _arrcount(arr)  sizeof(arr)/sizeof(arr[0])

int is_equal(int arr_count, int* arr){

	int avg = 0;

	for(int i = 0; i < arr_count; i++){
		avg += arr[i];
	}

	avg /= arr_count;

	for(int i = 0; i < arr_count; i++){
		if(arr[i] != avg){
			return 0;
		}
	}

	return 1;
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

int exclude_index(int count,int* arr){
	int index =-1;
	int max = 0;

	for(int i = 0; i < count; i++){
		if(max < arr[i]){
			max = arr[i];
			index = i;
		}
	}

	return index;
}

int equal(int arr_count, int* arr){
#if 0
	printf("--------\n");
	for(int i = 0; i < arr_count; i++){
		printf("%d ",arr[i]);
	}

	if(is_equal(arr_count,arr)){
		printf("FOUND!\n");
		return 0;
	}

	if(min(arr_count,arr) <= 0){
		return 100;
	}

	printf("\n");
#else
	if(min(arr_count,arr) <= 0){
		return 100;
	}

	if(is_equal(arr_count,arr)){ 
		return 0;
	}
#endif


	int choice_array[] = {1,2,6};
	int rounds_array[_arrcount(choice_array)] = {0};

	for(int i = 0; i < _arrcount(rounds_array); i++){
		rounds_array[i] = INT_MAX;
	}



	for(int i = 0; i < _arrcount(choice_array) ; i++){
		int c = choice_array[i];

		int exclude = exclude_index(arr_count,arr);

		arr[exclude] -= c;
		rounds_array[i] = 1 + equal(arr_count,arr);
		arr[exclude] += c;
	}

	return min(_arrcount(rounds_array),rounds_array);
}



int main(int argc, char** argv){

	int arr[] = {1,1,5};
	int count = _arrcount(arr);

	int rounds = equal(count,arr);

	printf("MIN ROUNDS: %d\n",rounds);

	return 0;
}
