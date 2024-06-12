#include <stdio.h>
// Function to return the maximum of two integers
int max(int a, int b) 
{
    return (a > b) ? a : b;
}
// Function to solve the 0/1 Knapsack Problem
int knapSack(int W, int wt[], int val[], int n) 
{
    int i, w;
    int K[n + 1][W + 1];
    // Build the table K[][] in bottom-up manner
    for (i = 0; i <= n; i++) 
	{
        for (w = 0; w <= W; w++) 
		{
            if (i == 0 || w == 0) 
			{
                K[i][w] = 0;
            } 
			else if (wt[i - 1] <= w) 
			{
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            } 
			else 
			{
                K[i][w] = K[i - 1][w];
            }
        }
    }
    // Return the maximum value that can be put in the knapsack of capacity W
    return K[n][W];
}
int main() 
{
    int i,n, W;
    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);
    int val[n], wt[n];
    // Input values and weights of items
    printf("Enter values of items:\n");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &val[i]);
    }
    printf("Enter weights of items:\n");
    for ( i = 0; i < n; i++) 
	{
        scanf("%d", &wt[i]);
    }
    // Input capacity of knapsack
    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);
    // Call knapSack function and print the result
    printf("Maximum value in knapsack = %d\n", knapSack(W, wt, val, n));   
    return 0;
}

