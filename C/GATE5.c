double f(double x) 
{ 
   if (abs(x*x - 3) < 0.01) return x; 
   else return f(x/2 + 1.5/x); 
} 