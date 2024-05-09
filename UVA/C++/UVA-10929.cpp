#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    long long int sum;
    int mode;
    while(cin>>s && s!="0")
    {
        sum=0;
        mode=1;
        for(int i=s.size()-1;i>=0;i--)
        {
            sum+=((s[i]-'0')*mode);
            if(mode==1) mode*=10;
            else mode/=10;
        }
        if(sum%11) cout<<s<<" is not a multiple of 11.\n";
        else cout<<s<<" is a multiple of 11.\n";
    }
}
