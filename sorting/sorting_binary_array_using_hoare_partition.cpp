1 0 1 1 0

Output: 
0 0 1 1 1

_________________________________________________________________________________________________________________

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++___-------------------------

 void binSort(int a[], int n)
    {
       int i=0, j=n-1;
       while(1)
       {
           while(a[i]==0)++i;
           while(a[j]==1)--j;
           if(i<j)
           {
               a[i]=0;
               a[j]=1;
           }
           else
               break;
       }
    }