#include <bits/stdc++.h>
using namespace std;
int main() {
   int t,n;
   int ans[1002]={0};
   int var[2672]={0};

   /*Precomputation*/

   for(int i=2;i<2671 ;++i)
   {
      if(var[i]==0)
      {
         /*if var[i]=0, this means that
         the number is prime, we increment
         count of all its multiples by 1*/
         for(int j=2*i; j<2671 ; j+=i)
            var[j]++;
      }
   }
   /*Store first 1000 Lucky numbers*/
   for(int i=30,j=0;i<2671 && j<1001;++i)
      if(var[i]>=3)
         ans[j++]=i;

   scanf("%d",&t);
   while(t--)
   {
      scanf("%d",&n);
      printf("%d\n",ans[n-1]);
   }

   return 0;
}
