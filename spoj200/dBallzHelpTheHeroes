#include <iostream>
#include <cstdio>

typedef long long int ll;

using namespace std;

int main()
{
    int t; cin>>t;
    ll energyBlast[1005];
    ll distraction[1005];

    while(t--)
    {
       ll energy, length;
        scanf("%lld %lld",&energy, &length);
        ll optimalAnswer[1000005]={0};
       for(int i=0;i<length;i++)
           scanf("%lld", &energyBlast[i]);

       for(int i =0; i<length; i++)
           scanf("%lld", &distraction[i]);


       for(ll i=0; i<=energy; i++)
          {
             for(int j = 0; j< length; j++)
                {
                    if(i-energyBlast[j] >=0)
                    {
                        optimalAnswer[i] = max(optimalAnswer[i],distraction[j]+optimalAnswer[i-energyBlast[j]]);
                    }
                }
          }
          printf("%lld\n",optimalAnswer[energy]);


    }
    return 0;
}
