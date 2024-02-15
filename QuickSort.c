#include<stdio.h>

//Function to swap two elements
void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

//Function to partition array on the basis of pivot
int partition(int arr[], int low, int high){
	int pivot = arr[high]; 			//pivot
	int i = (low-1);			//index of lower elements
	int j;
	for(j = low; j <= high-1; j++){
		if(arr[j]<=pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return(i+1);
}

//Function to implement quick sort
void quickSort(int arr[], int low, int high){
	if(low<high){
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi-1);
		quickSort(arr, pi+1, high);
	}
}

//Function to print array elements
void printArray(int arr[], int size){
	int i;
	for(i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
}

//Main function
int main(){
	int n;
	printf("Enter the number of elements in array: ");
	scanf("%d", &n);
	int arr[n];
	printf("\nEnter the elements: ");
	int i;
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	quickSort(arr, 0, n-1);		//Perform quick sort
	printf("\nSorted array in ascending order: ");
	printArray(arr, n);
}
