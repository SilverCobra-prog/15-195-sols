#include <bits/stdc++.h>
using namespace std;

long long SuperCeiling(long long n) {
    long long p;
    for (p=1; p < n; p = 2*p);
    return p;
}

long long max (long long a, long long b) {return (a>b)? a: b;}
long long min (long long a, long long b) {return (a<b)? a: b;}
long long Parent(long long i) {return i/2;}
long long LeftChild(long long i) {return 2*i;}
long long RightChild(long long i) {return 2*i+1;}
long long glue(long long a, long long b) {
    return a+b;
}

long long identity = 0; 
long long n, N, *A;
void Assign(long long i, long long x) {
    i = i+N;
    A[i] = x;
    for (i = Parent(i); i>0; i = Parent(i)) {
        A[i] = glue (A[LeftChild(i)], A[RightChild(i)]);
    }
}

long long f (long long v, long long l, long long r, long long i, long long j) {
    long long t1, t2, m;
    long long identity = 0; 
    if (l==i && r==j) {
        return A[v];
    } else {
        m = (l+r)/2; 
        t1 = (i <= m)? f (LeftChild(v), l, m, i, (min(m,j))): identity;
        t2 = (j > m)? f (RightChild(v), (m+1), r, (max(i,(m+1))), j): identity;
        return glue (t1, t2);
    }
}
long long RangeSum(long long i, long long j) {
    return f (1, 0, (N-1), i, j);
}

int main() {
    long long n; cin >> n;
    long long q; cin >> q;
    N = SuperCeiling(n);
    A = new long long[2 * N]();
    
    for (long long i = 0; i < n; i++) {
        long long a; cin >> a;
        Assign(i, a);
    }

    while(q--) {
        long long type, i, v;
        cin >> type >> i >> v;
        if(type == 1) {
            Assign(i-1, v);
        } else {
            cout << RangeSum(i-1, v-1) << endl;
        }
    }

}
