 int * g (void)  
{  
  int x = 10;  
  return (&x);  
}  
  
[P2] int * g (void)  
{  
  int * px;  
  *px = 10;  
  return px;  
} 
   
[P3] int *g (void)  
{  
  int *px;  
  px = (int *) malloc (sizeof(int));  
  *px = 10; 
  return px;  
}  