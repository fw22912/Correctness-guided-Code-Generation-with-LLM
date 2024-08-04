
int min(int a, int b) { return ((a < b) ? a : b); }


int maxArea(int *height, int heightSize)
{
    
    int start = 0;
    int end = heightSize - 1;
    int res = 0;

    while (start < end)
    {
        
        int currArea = (end - start) * min(height[start], height[end]);

        if (currArea > res)
            res = currArea;

        if (height[start] < height[end])
            start = start + 1;
        else
            end = end - 1;
    }

    return res;
}
