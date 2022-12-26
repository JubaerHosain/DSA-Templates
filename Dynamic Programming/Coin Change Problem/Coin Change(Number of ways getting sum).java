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
                    if(j >= coins[i]){          //including coins[i]
                        // coins[i] can pick multiple times
                        // if want to pick exactly one time then use dp[i-1][j-coins[i]]              
                        including = dp[i][j-coins[i]];  
                    }
                    
                    dp[i][j] = excluding + including;
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
#include <bits/stdc++.h>
using namespace std;

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
			if (i >= arr[j])
				count[i] += count[i - arr[j]];
	
	return count[N];
	
}


int main()
{
	int arr[] = {1, 5, 6};
	int m = sizeof(arr) / sizeof(arr[0]);
	int N = 7;
	cout << "Total number of ways = "
		<< countWays(arr, m, N);
	return 0;
}



