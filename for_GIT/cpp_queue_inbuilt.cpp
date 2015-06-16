#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(5);
    q.push(10);

    cout<<q.back()<<endl;
    q.pop();

    cout<<q.back()<<endl;
    return 0;
}

