#include<stdio.h>
struct Pair{
	int max;
	int min;
};

struct Pair maxMinDAC(int arr[], int low, int high){
	struct Pair result;
	struct Pair left;
	struct Pair right;
	int mid;
	
	//If only one element in the array
	if(low == high){
		result.max = arr[low];
		result.min = arr[high];
		return result;
	}
	
	//If there are two elements in the array
	if(high == low+1){
		if(arr[low] < arr[high]){
			result.min = arr[low];
			result.max = arr[high];
		}
		else{
			result.min = arr[high];
			result.max = arr[low];
		}
		return result;
	}
	
	//If there are more than two elements in the array
	mid = (low+high)/2;
	left = maxMinDAC(arr, low, mid);
	right = maxMinDAC(arr, mid+1, high);
	
	//Compare and get the maximum of both parts
	result.max = (left.max > right.max) ? left.max : right.max; 
	
	//Compare and get the minimum of both parts
	result.min = (left.min < right.min) ? left.min : right.min;
	return result;
}

int main(){
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the elements: ");
	int i;
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	struct Pair result = maxMinDAC(arr, 0, n-1);
	printf("Maximum element is: %d\n", result.max);
	printf("Minimum element is: %d\n", result.min);
	return 0;
}
