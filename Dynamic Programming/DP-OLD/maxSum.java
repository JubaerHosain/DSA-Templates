import java.util.Scanner;


public class MaxSum {
    static int maxSubsequenceSum(int n, int[] array) {
        int max = array[0];
        
        for(int i = 1; i < n; i++){
            max = Math.max(max, Math.max(max+array[i], array[i]));
        }
   
        
        return max;
    }
    
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        
        while(test -- > 0){
            int n = scan.nextInt();
            int[] array = new int[n];
            
            for(int i = 0; i < n; i++){
                array[i] = scan.nextInt();
            }
            
            int res = maxSubsequenceSum(n, array);
            System.out.println(res);
        }
    }
}
