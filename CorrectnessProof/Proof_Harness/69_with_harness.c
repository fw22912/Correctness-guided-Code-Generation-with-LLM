#include <assert.h>
#include <stdlib.h>

//using the binary search method is one of the efficient ones for this problem statement.
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
//if mid is less than the square root of the number(x) store the value of mid in ans.
               if( val < x){
                       ans = mid;
                       start = mid+1;
               }
//if mid is greater than the square root of the number(x) then ssign the value mid-1 to end.               
               if( val > x){
                       end = mid-1;
               }
        }
   return ans;
}


void proof_harness_mySqrt() {
    int x;
    __CPROVER_assume(x >= 0);
    int result = mySqrt(x);
    long long int sq = (long long int)result * (long long int)result;
    if (sq <= x) {
        assert(sq <= x && x < (result + 1) * (result + 1));
    } else {
        assert((result - 1) * (result - 1) <= x);
    }
}


void proof_harness_main() {
    int x;
    __CPROVER_assume(x >= 0);
    mySqrt(x);
}

void combined_proof_harness() {
    proof_harness_mySqrt();
    proof_harness_main();
}