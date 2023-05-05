/*
Problem: Maximum Distance
Link: https://codeforces.com/gym/102951/problem/A
Tags: Brute force

Explaination:
We will try every possible combination of two points

Complexity: O(n^2)
*/

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(), x.end()
using namespace std;
const int N = (int)5000 + 1;
const int MOD = (int)1e9 + 7;
const ll INF = INT_MAX;

int n, x[N], y[N];
ll dist(int p1, int p2)
{
	ll dx = x[p1] - x[p2];
	ll dy = y[p1] - y[p2];
	return (dx * dx) + (dy * dy);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < n; i++)
		cin >> y[i];
	ll sol = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			sol = max(sol, dist(i, j));
		}
	}
	cout << sol;
}
// Solved by: Muaath Alqarni