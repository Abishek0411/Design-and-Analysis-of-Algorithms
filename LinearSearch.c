#include <stdio.h>  
int linearSearch(int a[], int n, int val) {  
  // Going through array sequencially 
  int i;
  for (i = 0; i < n; i++)  
    {  
        if (a[i] == val)  
        return i+1;  
    }  
  return -1;  
}  
int main() {  
    int i, n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements in the array: ");
    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    int val;
    printf("Enter the element you want to search: ");
    scanf("%d",&val);
   
    int res = linearSearch(a, n, val); // Store result  
    printf("The elements of the array are - ");  
    for (i = 0; i < n; i++)  
    printf("%d ", a[i]);  
    printf("\nElement to be searched is - %d", val);  
    if (res == -1)  
    printf("\nElement is not present in the array");  
    else  
    printf("\nElement is present at %d position of array", res);  
    return 0;  
}  
