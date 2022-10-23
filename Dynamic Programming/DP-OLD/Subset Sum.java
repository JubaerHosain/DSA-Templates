

/**
 * using backtracking algorithm
 * @author jubaer
 */
public class SubsetSum {
    private static boolean hasSubset(int[] w, int sum, int length, int i) {
        System.out.println(sum);
        if(sum == 0){
            return true;
        }
        if(sum < 0 || i >= length){
            return false;
        }
        
        return  hasSubset(w, sum-w[i], length, i+1) || hasSubset(w, sum, length, i+1);
    }
    
    public static void main(String[] args){
        int[] w = {5, 100, 12, 130, 15, 188, 25};
        int sum = 57, length = 7;
        
        System.out.println(hasSubset(w, sum, length, 0));
    }
}
