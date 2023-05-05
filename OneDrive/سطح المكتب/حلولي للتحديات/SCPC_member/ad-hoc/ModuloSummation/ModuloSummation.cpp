/* problem : https://atcoder.jp/contests/abc103/tasks/abc103_c?lang=en
 * explanation :
 * let m = a[0] * a[1] * a[2] ... a[n-1]
 * m mod a[i] = 0 for every i
 * but if we take m-1
 * (m-1) mod a[i] = a[i]-1 for every i
 * and that is the best we can get
 * so f(m-1) = (a[0]-1) + (a[1]-1) .. (a[n-1]-1)
 * and of course we don't have to calculate m-1 
 * since we know the value of f(m-1)
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	int ans = 0;
	for (int i=0;i<n;i++){
		cin >> a[i];
		ans += a[i]-1;
	}
	cout << ans;
}
// solved by : Ahmad Alhashim
