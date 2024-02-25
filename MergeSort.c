#include<stdio.h>
#include<stdlib.h>

//Merges two subarrays of arr[]
//first subarray is arr[l...m]
//second subarray is arr[m+1...r]

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m-l+1;
	int n2 = r-m;
	
	int L[n1], R[n2];   //Create temp arrays
	
	//copy data to temp arrays L[] and R[]
	for(i=0; i<n1; i++)
		L[i] = arr[l+i];
	
	for(j=0; j<n2; j++)
		R[j] = arr[m+1+j];
		
	//merge the temp arrays back into arr[l...r]
	i=0;
	j=0;
	k=l;
	
	while(i<n1 && j<n2){
		if(L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	//Copy the remaining elements of L[], if there are any 
	while(i<n1){
		arr[k] = L[i];
		i++;
		k++;
	}
}

//l is for left index and r is for right index of the sub array of arr to be sorted

void mergeSort(int arr[], int l, int r)
{
	if(l<r){
		int m = l+(r-l)/2;
		
		//Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

//Function to print the array
void printArray(int A[], int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	int i, n;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the elements: ");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	mergeSort(arr, 0, n);
	printf("\nSorted array is: ");
	printArray(arr, n);
	return 0;
}
