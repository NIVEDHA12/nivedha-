
#include <stdio.h> 
#include<stdlib.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

int gcd(int x, int y) 
{ 
    if (y==0) 
       return x; 
    return gcd(y, x%y); 
} 
  
void swap(int x,int y)
 {
    int temp;
    temp=x;
    x=y;
    y=temp;
     
 }

int pour(int from_m, int to_n, int d) 
{ 
    
    int from = from_m; 
    int to = 0; 
  
    
    int step = 1; 
  
    
    while (from != d && to != d) 
    { 
       
        int temp = min(from, to_n - to); 
        to   += temp; 
        from -= temp;  
        step++; 
          if (from == d || to == d) 
            break; 
  
        
        if (from == 0) 
        { 
            from = from_m; 
            step++; 
        } 
  
       
        if (to == to_n) 
        { 
            to = 0; 
            step++; 
        } 
    } 
    return step; 
} 
  

int minSteps(int m, int n, int d) 
{ 
    
    if (m > n) 
        swap(m, n); 
  
    
    if (d > n) 
        return -1; 
  
    
    if ((d % gcd(n,m)) != 0) 
        return -1; 
  
    
    return min(pour(n,m,d),   
               pour(m,n,d));  
} 
  

int main() 
{ 
    int n, m, d;
    printf("size of jar 1:");
    scanf("%d",&m);
    printf("size of jar 2:");
    scanf("%d",&n);
    printf("desired:");
    scanf("%d",&d);
    
  
    printf("Minimum number of steps required is %d",minSteps(m, n, d)); 
  
    return 0; 
} 
