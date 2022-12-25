import java.io.*;
import java.util.*;


public class CoinChange {
    public static long getWays(int n, int sum, int[] coins) {
        long[][] dp = new long[n][sum+1];
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= sum; j++){
                if(j == 0){
                    dp[i][j] = 1;
                } else {
                    long excluding = 0;
                    long including = 0;
                    
                    if(i > 0){     				//excluding coins[i]
                        excluding  = dp[i-1][j];
                    }
                    if(j >= coins[i]){  //including coins[i]
                        including = dp[i][j-coins[i]];  //coins[i] can multiple times, if use exactly one time then dp[i-1][j-coins[i]]              
                    }
                    
                    dp[i][j] = excluding + including;
                    
                    // if i started with 1 then
                    // if(j < a[i])                            //excluding a[i]
                    //     dp[i][j] = dp[i-1][j];
                    // else                                    // excluding  + including
                    //     dp[i][j] = dp[i-1][j] + dp[i][j-a[i]];
                }
                
            }
        }
        
        return dp[n-1][sum];
    }

    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        
        int sum = scan.nextInt();
        int n = scan.nextInt();
        int[] coins = new int[n];
        
        for(int i = 0; i  < n; i++){
            coins[i] = scan.nextInt();
        }
        
        System.out.println(getWays(n, sum, coins));
    }
}







// linear space [can take same element multiple times]


// C++ implementation to count ways
// to sum up to a given value N
#include <bits/stdc++.h>

using namespace std;

// function to count the total
// number of ways to sum up to 'N'
int countWays(int arr[], int m, int N)
{
	int count[N + 1];
	memset(count, 0, sizeof(count));
	
	// base case
	count[0] = 1;
	
	// count ways for all values up
	// to 'N' and store the result
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < m; j++)

			// if i >= arr[j] then
			// accumulate count for value 'i' as
			// ways to form value 'i-arr[j]'
			if (i >= arr[j])
				count[i] += count[i - arr[j]];
	
	// required number of ways
	return count[N];
	
}

// Driver code
int main()
{
	int arr[] = {1, 5, 6};
	int m = sizeof(arr) / sizeof(arr[0]);
	int N = 7;
	cout << "Total number of ways = "
		<< countWays(arr, m, N);
	return 0;
}



