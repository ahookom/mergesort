#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int sort(int *array, int n){

	if(n<2)return 0;
	int lsize;
	if(n%2>0) lsize=(n+1)/2;
	else lsize=n/2;

	int rsize=(n-lsize);
	int left[lsize];
	int right[rsize];

	int i=0;

	while(i<lsize){
	left[i]=array[i];

	//printf("left while loop copied %d\n", left[i]);
	i++;
	}

	while(i<n){
	right[i-lsize]=array[i];
	//printf("right while loop copied %d\n", right[i-lsize]);
	i++;
	}

	sort(left, lsize);
	sort(right, rsize);


	//This is the actual sorting part.
	int r=0, l=0;
	i=0;

	while(i<n&&r<rsize&&l<lsize){

		if(left[l]<right[r]){
		array[i]=left[l];
		i++;
		l++;
		}
		else{
		array[i]=right[r];
		i++;
		r++;
		}

	}

	if(i<n){

		while(r<rsize){
		array[i]=right[r];
		r++;
		i++;
		}

		while(l<lsize){
		array[i]=left[l];
		l++;
		i++;
		}

	}

	//for(int i=0;i<n;i++) printf("%d   ", array[i]);
	//printf("\n");
	return 0;
}



int main(){

	//create an array of pseudorandom integers between 0-50
	srand(time(NULL));

	const int ELEMENTS=(rand()%50);
	int array[ELEMENTS];

	for(int i=0;i<ELEMENTS;i++){
		array[i]=(rand()%50);
	}

	//print original list of random numbers
	for(int i=0;i<ELEMENTS;i++) printf("%d   ", array[i]);

	printf("\n\n");

	//run the numbers through the mergesort algorithm	
	sort(array, ELEMENTS);

	//print list of sorted numbers
	for(int i=0;i<ELEMENTS;i++) printf("%d   ", array[i]);

	printf("\n");
	return 0;
}
