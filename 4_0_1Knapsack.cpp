#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int knapsack(int w, const vector<int>& weights,const vector<int>& profits,int n)
{
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(weights[i-1]<=j)
            {
                dp[i][j]=max(profits[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}


int main(){
    int n, W;
    
    cout << "Enter the number of items: ";
    cin >> n;
    
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    vector<int> profits(n), weights(n);

    cout << "Enter the profit and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " profit and weight: ";
         cin >> profits[i] >> weights[i];
    }

    int maxProfit = knapsack(W, weights, profits, n);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
    
}