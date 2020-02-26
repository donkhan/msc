int ProcessArray(int *listA, int x, int n) 
{ 
    int i, j, k; 
    i = 0; 
    j = n-1; 
    do{ 
        k = (i+j)/2; 
        if (x <= listA[k]) 
            j = k-1; 
        if (listA[k] <= x) 
            i = k+1; 
    } while (i <= j); 
    if (listA[k] == x) 
        return(k); 
    else
        return -1; 
}