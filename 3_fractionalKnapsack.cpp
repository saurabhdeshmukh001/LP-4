

#include <iostream>
#include<algorithm>
using namespace std;


struct Item {
	int profit, weight;

	
	Item()
	{
	    profit=0,weight=0;
	}
	
};


static bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.profit / (double)a.weight;
	double r2 = (double)b.profit / (double)b.weight;
	return r1 > r2;
}


double fractionalKnapsack(int W, struct Item arr[], int N)
{
	
	sort(arr, arr + N, cmp);

	double finalvalue = 0.0;

	
	for (int i = 0; i < N; i++) {
		
		
		if (arr[i].weight <= W) {
			W -= arr[i].weight;
			finalvalue += arr[i].profit;
		}

		
		else {
			finalvalue
				+= arr[i].profit
				* ((double)W / (double)arr[i].weight);
			break;
		}
	}

	
	return finalvalue;
}


int main()
{
	int W = 50;
    int N;
    cout << "Enter the number of items: ";
    cin >> N;
    Item arr[N];
    
    for (int i = 0; i < N; i++) {
        cout << "Enter profit and weight for item " << i + 1 << ": ";
        cin >> arr[i].profit >> arr[i].weight;
    }
    	
    	cout << fractionalKnapsack(W, arr, N);
	return 0;
}
