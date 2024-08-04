
int mySqrt(int x){
int start=0;
        int end=x;
        long long int ans=0;
        while(start <= end){
               long long int mid=(start+end)/2;
               long long int val=mid*mid;
               if( val == x){
                   return mid;
                }

               if( val < x){
                       ans = mid;
                       start = mid+1;
               }

               if( val > x){
                       end = mid-1;
               }
        }
   return ans;
}
