#include<stdio.h>

//Function for Insertion Sort
void insertionSort(int arr[], int n){
	int i, j, key;
	for(i=1; i<n; i++){
		key = arr[i];
		j=i-1;
		
		while(j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j=j-1;
		}
		arr[j+1] = key;
	}
}

//Function for printing the sorted array
void printArray(int arr[], int n){
	int i;
	printf("Sorted sub-array is: ");
	for(i=0; i<n; i++){
		printf("%d", arr[i]);
		printf(" ");
	}
	printf("\n");
}

int main(){
	int i, n;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter elements for array: ");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	insertionSort(arr, n);
	printArray(arr, n);
	return 0;
}
