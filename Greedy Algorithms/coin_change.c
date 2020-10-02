#include <stdio.h>
#define COINS 10
#define MAX 100

int coins[COINS] = {5000, 1000, 500, 100, 50, 20, 10, 5, 2, 1};

void findMin(int cost){
	int i, j=0, coinChange[MAX]={0};
	for(i=0; i<=COINS-1; i++){
		while(cost >= coins[i]){
			cost -= coins[i];
			coinChange[j++] = coins[i];
		}
	}

	for(i=0; i<j; i++){
		printf("%d ", coinChange[i]);
	}
}

int main(void){
	int cost;
	
	printf("The value you want to change: ");
	scanf("%d", &cost);
	
	printf("\nYou can have the following as the change of %d: \n", cost);
	findMin(cost);
	
	return 0;
}
