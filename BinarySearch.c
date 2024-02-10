#include <stdio.h>  
 
int binary_search(int arr[], int left, int right, int target) {  
    while (left <= right) {  
        int mid = left + (right - left) / 2;  
 
        if (arr[mid] == target) {  
            return mid;  
        } else if (arr[mid] < target) {  
            left = mid + 1;  
        } else {  
            right = mid - 1;  
        }  
    }  
 
    return -1;  // Target not found  
}  
 
int main() {  
    int i, n;
    printf("Enter number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    int target;
    printf("Enter element to be searched");
    scanf("%d",&target);
 
    int index = binary_search(arr, 0, n, target);  
 
    if (index == -1) {  
        printf("Target not found\n");  
    } else {  
        printf("Target found at index %d\n", index);  
    }  
 
    return 0;  
} 
