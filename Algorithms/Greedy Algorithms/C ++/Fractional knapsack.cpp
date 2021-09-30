#include <bits/stdc++.h> 

using namespace std; 

struct Item{
	int value;
	int weight;
};

bool cmp(struct Item a, struct Item b){
	double r1 = (double)a.value / a.weight;
	double r2 = (double)b.value / b.weight;
	return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int n){
	sort(arr, arr + n, cmp);
	int curWeight = 0; // Current weight in knapsack
	double finalvalue = 0.0; // Result (value in Knapsack)
	// Looping through all Items
	for (int i=0; i<n; i++){
		if (curWeight + arr[i].weight <= W){
			curWeight += arr[i].weight;
			finalvalue += arr[i].value;
		}else{
			int remain = W - curWeight;
			finalvalue += arr[i].value * ((double) remain / arr[i].weight);
			break;
		}
	}
	return finalvalue;
}

int main(){
	int W, N; // W-Weight of knapsack, N-Number of items
	cout << "Enter the number of items: ";
	cin >> N;
	
	Item i_arr[N];
	cout << "Enter the weight of knapsack: ";
	cin >> W;
	
	for(int i=0; i<N; i++){
		cout << "Enter the " << i << "th item volume: " ;
		cin >> i_arr[i].value;
	}
	for(int i=0; i<N; i++){
		cout << "Enter the " << i << "th item price: ";
		cin >> i_arr[i].weight;
	}
		
	cout << "Maximum value we can obtain: " << fractionalKnapsack(W, i_arr, N);
	
	return 0;
}
