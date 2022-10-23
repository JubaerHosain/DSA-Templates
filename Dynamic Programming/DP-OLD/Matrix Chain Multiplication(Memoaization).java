package newpackage;


public class MatrixChain {
    public static void main(String[] args){
        int[] p = {40, 20, 30, 10, 30};
        int n = p.length;
        
        int[][] cost = new int[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cost[i][j] = Integer.MAX_VALUE;
            }
        }
        
        System.out.println(MatrixChainOrder(p, cost, 1, n-1));
    }

    private static int MatrixChainOrder(int[] p, int[][] cost, int i, int j) {
        if(cost[i][j] < Integer.MAX_VALUE){
            return cost[i][j];
        }
        
        if(i == j){
            cost[i][j] = 0;
        }
        else{
            for(int k = i; k < j; k++){
                int value = MatrixChainOrder(p, cost, i, k) + MatrixChainOrder(p, cost, k+1, j) + p[i-1]*p[k]*p[j];
                
                if(value < cost[i][j]){
                    cost[i][j] = value;
                }
            }
        }
        
        return cost[i][j];
    }
}
