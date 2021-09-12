//returns the exact position otherwise -1(unlike c++ upper and lower bound)

class Solution {
    private int lowerBound(int[] nums, int target){
        int index = -1;
        int left = 0, right = nums.length-1;
        
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid] >= target)
                right = mid-1;
            else
                left = mid+1;
            if(nums[mid] == target)
                index = mid;
        }
        
        return index;
    }
    
    private int upperBound(int[] nums, int target){
        int index = -1;
        int left = 0, right = nums.length-1;
        
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid] <= target)
                left = mid+1;
            else
                right = mid-1;
            if(nums[mid] == target)
                index = mid;
        }
        
        return index;
    }
    
    public int[] searchRange(int[] nums, int target) {
        int first = lowerBound(nums, target);
        int last = upperBound(nums, target);
        
        return new int[]{first, last};
    }
}
