package newpackage;


public class MatrixChain {
    
    public static void main(String[] args){
        int[] p = {10, 30, 5, 60};
        int n = p.length;
        
        System.out.println(MatrixChainOrder(n, p));
    }

    private static int MatrixChainOrder(int n, int[] p) {
        int[][] cost = new int[n][n], m = new int[n][n];
       
        
        for(int d = 1; d < n-1; d++){
            for(int i = 1; i < n-d;  i++){
                int j = i+d;
                int min = Integer.MAX_VALUE;
                
                for(int k = i; k < j; k++){
                    int value = cost[i][k] + cost[k+1][j] + p[i-1]*p[k]*p[j];
                    
                    if(value < min){
                        min = value;
                        m[i][j] = k;
                    }
                }
                cost[i][j] = min;
            }
        }
        
        return cost[1][n-1];
    }
}
