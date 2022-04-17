import java.util.Arrays;
import java.util.Scanner;
 
public class Solution {
 
    private static int[] manachersAlgo(String text) {
        int n = text.length();
        int[] lpsArray = new int[n];
        Arrays.fill(lpsArray, 1);
 
        int centre = 0, right = 0;
        for(int i = 1; i < n-1; i++) {
            int mirror = centre - (i-centre);
            if(i < right)
                lpsArray[i] = Math.min(lpsArray[mirror], right-i);
 
            while(i - lpsArray[i] >= 0 && i + lpsArray[i] <= n-1
            && text.charAt(i - lpsArray[i]) == text.charAt(i + lpsArray[i])) 
                lpsArray[i]++;
 
            if(i + lpsArray[i] > right) {
                centre = i;
                right = i + lpsArray[i];
            }
        } 
 
        return lpsArray;
    }
 
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
 
        //System.out.print("Enter a String: ");
        String input = scanner.next();
      
//         String text = "#";
//         for(int i = 0; i < input.length(); i++)
//             text += input.charAt(i) + "#";
//         text += "#";
//String appending in java takes n for each append
//So overall complexity becomes n^2, StringBuilder or StringBuffer can solve this problm
 
        String text = input.replace("", "#");
        int[] lpsArray = manachersAlgo(text);
 
        int maxLen = 0, maxInx = 0;
        for(int i = 0; i < lpsArray.length; i++) {
            int curr = ((lpsArray[i]*2) - 2) / 2;
            if(curr > maxLen ) {
                maxLen = curr;
                maxInx = i;
            }
        }
 
        int firstInx = maxInx - maxLen;
        String ans = text.substring(firstInx, firstInx + (2*maxLen+1));
        System.out.println(ans.replaceAll("#", ""));
        
        scanner.close();
    }
}
