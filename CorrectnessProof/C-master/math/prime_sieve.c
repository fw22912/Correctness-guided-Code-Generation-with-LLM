
#include <assert.h>	
#include <stdio.h>	
#include <stdlib.h>	

const unsigned long long MAX_SIZE = 1000000;  


void prime(int *p)
{
	for(long long int i=3;i<=MAX_SIZE;i+=2) { p[i]=1; }
	for(long long int i=3;i<=MAX_SIZE;i+=2)
	{
		if(p[i]==1) {
		    for(long long int j=i*i;j<=MAX_SIZE;j+=i) {
			p[j]=0;
		    }
		}
	}
	p[2]=1;
	p[0]=p[1]=0;    
}

int count(int *arr, const int size){
  int k=0;
  for(int i=0;i<=size;i++){
    if(arr[i]==1){
      k++;
    }
  }
  return k;
}


static void test()
{
    
    const int size = 10; 
    printf("Test Case 1...");
    int arr[1000005]={0};   
    prime(arr);
    assert(count(arr,size)==4);
    printf("Passed\n");
}


int main(int argc, const char *argv[])
{
    test();	
    return 0;
}
