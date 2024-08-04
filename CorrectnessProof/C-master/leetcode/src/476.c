int findComplement(int num)
{
    int TotalBits = 0;
    int temp = num;
    while (temp)
    {  
       
        TotalBits++;  
        temp >>= 1;   
                      
    }
    int i,
        flipNumber = 1;  
                         
                         
    for (i = 1; i < TotalBits; i++)
    {
        flipNumber += UINT32_C(1)
                      << i;  
                             
    }
    num = num ^ flipNumber;
    return num;
}