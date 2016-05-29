#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int counter = 1;
    while(1)
    {
    string braces;
    cin>>braces;
    if( braces[0] == '-' )
        {
            break;
        }
    else
        {
            int lenBraces = braces.length(); 
            stack <char> braceStack;
            for(int i=0; i<lenBraces; i++)
            {
                if(braceStack.empty())
                {
                    braceStack.push(braces[i]);
                }
                else
                {
                    if(braces[i]=='}' && braceStack.top() == '{')
                        braceStack.pop();
                    else
                        braceStack.push(braces[i]);
                }
            }
            cout<<counter++<<". ";
            int open = 0, close = 0;
            while( ! braceStack.empty() )
            {
                if( braceStack.top() == '{' )
                    open++;
                else
                    close++;

                braceStack.pop();
            }

            int ans = close/2; 
            ans += close%2;
            if(open&1)
                open++;
            ans+=open/2;
            

            cout<<ans<<endl;
        }

    }
    return 0;
}
