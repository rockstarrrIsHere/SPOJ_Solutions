#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

#define all(x) x.begin(), x.end()
#define f(i,a,b) for(int i = (a); i <= (b); i++)
#define fd(i,a,b) for(int i = (a); i >= (b); i--)
#define mp make_pair
#define faster_io() ios_base::sync_with_stdio(false)
#define pb push_back
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define TRACE(x) cout << #x << " = " << x << "\n";
#define vii vector<pair<int,int>>

const ll INF = 1000000005;
const ll INFLL = 1000000000000000005ll;
const ll MOD = 1000000007;

// --------------------------------------------------------------------------

const int RIGHT = 131072;
const int SIZE = 265000;

int A[SIZE], L[SIZE], R[SIZE], M[SIZE];
int N, Q;

void build(int n, int a, int b)
{
    if(a == b)
    {
        L[n] = R[n] = M[n] = 1;
        return;
    }

    int mid = (a+b) / 2;
    build(2*n, a, mid);
    build(2*n+1, mid+1, b);

    int sz = (b-a+1) / 2;
    L[n] = L[2*n] == sz && A[mid] == A[mid+1] ? L[2*n] + L[2*n+1] : L[2*n];
    R[n] = R[2*n+1] == sz && A[mid] == A[mid+1] ? R[2*n] + R[2*n+1] : R[2*n+1];
    M[n] = max(max(max(M[2*n], M[2*n+1]), L[n]), R[n]);
    if(A[mid] == A[mid+1]) M[n] = max(M[n], R[2*n] + L[2*n+1]);
}

int query(int l, int r, int n, int a, int b)
{
    if(a > r || b < l) return 0;
    if(a >= l && b <= r) return M[n];

    int mid = (a+b) / 2;
    int ql = query(l, r, 2*n, a, mid);
    int qr = query(l, r, 2*n+1, mid+1, b);

    if(r <= mid) return ql;
    if(l > mid) return qr;

    int at_left = min(mid-l+1, R[2*n]);
    int at_right = min(r-mid, L[2*n+1]);
    int middle = A[mid] == A[mid+1] ? at_left + at_right : 0;
    return max(max(ql,qr), middle);
}

int main()
{
    while(true)
    {
        scanf("%d",&N);
        if(!N) return 0;
        scanf("%d",&Q);
        f(i,1,N) scanf("%d",&A[i]);
        build(1,1,RIGHT);
        while(Q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n", query(l,r,1,1,RIGHT));
        }
    }
}
