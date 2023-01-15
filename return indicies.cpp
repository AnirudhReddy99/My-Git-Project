class solution {
    public int[] twosum(int[] nums, int target) {
          
          for(int i=0; i<nums.lenght; i++)
         {
              for (int j=i+1; j<nums.lenght; j++)
              {
                    if(nums[i]+nums[j]==target)
                        return new int[]{i, j};
              }
         }
         throw new IllegalArgumentException("Invalid Elements"); 
     
     }
}