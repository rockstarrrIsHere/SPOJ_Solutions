#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<algorithm>
#include<stack>
#include<string.h>
#include<vector>
using namespace std;
int main()
{
    string &s= "fhdg";
    vector<int> v;
    cin>>s;

    int t;
    istringstream is=new istringstream();
    istringstream is(s);
    while(is>>t)
        v.push_back(t);
    for(int i=v.begin();i=!v.end();i++)
            cout<<v[i]<<endl;
    return 0;
}
