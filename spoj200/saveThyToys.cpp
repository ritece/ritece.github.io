#include <iostream>
 
using namespace std;
 
int main()
{
     int t; cin>>t;
 
    while(t--)
    {
        int n; scanf("%d",&n);
        long long int price[100010];
        long long int finalCollection[100010];
 
        for(int i=0; i<n; i++)
             {
                 scanf("%lld",&price[i]);
                 finalCollection[i]=0;
             }
 
        //cout<<getMax(price, finalCollection, n, 0)<<endl;
        for(int i=n-1; i>=0; i--)
        {
            long long int a = price[i];
            if(i+2<n)
                a += finalCollection[i+2];
 
            long long int b=0;
            if(i+1 < n)
                b+= price[i]+price[i+1];
            if(i+4 < n)
                b+= finalCollection[i+4];
 
            long long int c = 0;
            if(i+2 < n)
                c+= price[i]+price[i+1]+price[i+2];
            if(i+6 < n)
                c+= finalCollection[i+6];
 
            finalCollection[i] = max(a, max(b,c));
 
        }
 
        printf("%lld\n",finalCollection[0]);
    }
    return 0;
}
