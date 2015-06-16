#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;
    int i;
    i=s.size();
    if(i!=0)
        cout<<s.top();
    cin>>i;
    s.push(i);
    cin>>i;
    s.push(i);
    cout<<s.size();
    return 0;
}
