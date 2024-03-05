#include<stdio.h>
#include<stdlib.h>
int main(){
	int c[2][2];
	int i,j;
	int P,Q,R,S,T,U,V;
	int x[2][2];
	int y[2][2];
	printf("Enter the elements of first matrix: ");
	for(i=0; i<2; i++){
		for(j=0;j<2;j++){
			scanf("%d", &x[i][j]);
		}
	}
	printf("Enter the elements of second matrix: ");
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			scanf("%d", &y[i][j]);
		}
	}
	printf("The first matrix is: \n");
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			printf("%d\t", x[i][j]);
		}
		printf("\n");
	}
	printf("The second matrix is: \n");
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			printf("%d\t", y[i][j]);
		}
		printf("\n");
	}
	P = (x[0][0]+x[1][1])*(y[0][0]+y[1][1]);
	Q = (x[1][0]+x[1][1])*y[0][0];
	R = (x[0][0]*(y[0][1]-y[1][1]));
	S = (x[1][1]*(y[1][0]-y[0][0]));
	T = (x[0][0]+x[0][1])*y[1][1];
	U = (x[1][0]-x[0][0]*(y[0][0]+y[0][1]));
	V = (x[0][1]-x[1][1])*(y[1][0]+y[1][1]);
	c[0][0] = P+S-T+V;
	c[0][1] = R+T;
	c[1][0] = Q+S;
	c[1][1] = P+R-Q+U;
	printf("The product is: \n");
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
