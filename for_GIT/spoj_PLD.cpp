#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <climits>
#include <cfloat>
#include <cassert>
using namespace std;

#define HASHFUN 137
#define MOD 1000003

bool binarsearch(vector<int>*v,int val,int low,int high);
long long int power(long long int base,long long int expo);

bool has(vector<int>*v,int val){
    if(v->size()==0 || (*v)[0]>val || (*v)[v->size()-1]<val) return false;
    return binarsearch(v,val,0,v->size()-1);
}
bool binarsearch(vector<int>*v,int val,int low,int high){
    if((high-low)<=1){
        if((*v)[low]==val ||  (*v)[high]==val)
            return true;
        return false;
    }
    int mid;
    mid=(low+high)/2;
    if((*v)[mid]==val)
        return true;
    else if((*v)[mid]>val)
        return binarsearch(v,val,low,mid);
    else
        return binarsearch(v,val,mid,high);
}
long long int power(long long int base,long long int expo){
    long long int t;
    if(expo==0)
        return 1;
    if(expo==1)
        return base;
    t=power(base,expo/2);
    return expo%2==0?(t*t)%1000003:(t*t*base)%1000003;
}

int main(){
    int k,n,i;
    long long int hashval,fac;
    string s;
    scanf("%d",&k);
    cin>>s;
    long long int multfactor,divfactor;
    vector<int>*v=new vector<int>[1000003];
    n=s.length();
    hashval=0;fac=1;
    multfactor=power(137,k-1);
    divfactor=power(137,1000001);
    for(i=0;i<k;i++){
        hashval=(hashval+fac*(s[i]-'a'))%1000003;
        fac=(fac*137)%1000003;
    }
    v[hashval].push_back(k-1);
    for(i=k;i<n;i++){
        hashval=(hashval+MOD-(s[i-k]-'a'))%1000003;
        hashval=(hashval*divfactor)%1000003;
        hashval=(hashval+(s[i]-'a')*multfactor)%1000003;
        v[hashval].push_back(i);
    }
    int count=0;
    hashval=0;
    fac=1;
    for(i=n-1;i>=n-k;i--){
        hashval=(hashval+fac*(s[i]-'a'))%1000003;
        fac=(fac*137)%1000003;
    }
    if(has(&v[hashval],n-1))
        count++;
    for(i=n-k-1;i>=0;i--){
        hashval=(hashval+MOD-(s[i+k]-'a'))%1000003;
        hashval=(hashval*divfactor)%1000003;
        hashval=(hashval+(s[i]-'a')*multfactor)%1000003;
        if(has(&v[hashval],i+k-1))
            count++;
    }
    printf("%d\n",count);
    return 0;
}

