int findMin(int *nums, int numsSize)
{
    int low = 0, high = numsSize - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] < nums[high])
            high = mid;
        
        else
            low = mid + 1;
    }
    return nums[low];
}
