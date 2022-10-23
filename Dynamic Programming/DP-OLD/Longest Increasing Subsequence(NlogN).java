import java.util.Arrays;
import java.util.Scanner;

//NlogN time complexity
public class LIS {
    private static int getCeilPos(int[] arr, int[] sub, int low, int high, int val){
        while(low <= high){
            int mid = (low+high)/2;
            
            if(arr[sub[mid]] < val){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return low;
    }
    
    private static int[] lis(int n, int[] arr){
        int[] parent = new int[n];
        int[] sub = new int[n];
        
        int length = 0;
        for(int i = 0; i < n; i++){
            int low = 0, high = length;
            
            int pos = getCeilPos(arr, sub, low, high, arr[i]);
            
            if(pos > 0){
                parent[pos] = sub[pos-1];
            }
            sub[pos] = i;
            
            if(pos > length){
                length = pos;
            }
        }
        
        int[] result = new int[length+1];
        int k = sub[length];
        for(int j = length; j >= 0; j--){
            result[j] = arr[k];
            k = parent[j];
        }
        
        return result;
    }
    
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        
        int n = scan.nextInt();
        int[] arr = new int[n];
        
        for(int i = 0; i < n; i++){
            arr[i] = scan.nextInt();
        }
        
        int[] res = lis(n, arr);
        System.out.print("LIS Lenght: " + res.length + "\nElements: ");
        for(int i = 0; i < res.length; i++){
            System.out.print(res[i] + " ");
        }
    }
}
