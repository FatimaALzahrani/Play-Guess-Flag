/*
Problem: Maximal AND
Link: https://codeforces.com/contest/1669/problem/H
Tags: Bitmasks, Greedy

Explaination:
bitwise AND requires all bits in a position x to be 1, so in the result bit x is 1.
So for every bit going from bit with largest value to smallest value:
1. Count how many zeros
2. If we have enough operations to make them one (i.e. k >= zeros_count), then we convert it and we add to the result that bit\

Complexity: O(n*log2(max(a)))
*/

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(), x.end()
using namespace std;
const int N = (int)2e5 + 1;
const int MOD = (int)1e9 + 7;
const ll INF = INT_MAX;

int n, k, a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int sol = 0;
        for (int i = 30; i >= 0; i--) {
            int zeros_count = 0;
            for (int j = 0; j < n; j++)
                if ((a[j] & (1 << i)) == 0) zeros_count++;
            if (k >= zeros_count) {
                k -= zeros_count;
                sol += (1 << i);
            }
        }
        cout << sol << endl;
    }
}
// Solved by: Muaath Alqarni