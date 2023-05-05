#include <bits/stdc++.h>
using namespace std;
#define int long long

//https://codeforces.com/contest/1763/problem/B

//explanation
// PQ is used to find the min (insert with minus 'min-heap') 

int32_t main() {
    int t;cin>>t;

    while(t--){
        priority_queue<pair<int,int>> pq;
        int n,k;cin>>n>>k;
        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
        }
        int c;
        //fill PQ 
        for (int i = 0; i < n; ++i) {
            cin>>c;
            //minus to become min-heap
            pq.push({-c,-arr[i]});
        }

        int mx = *max_element(arr,arr+n);
        int power = k;
        pair<int,int> a=pq.top();

        while(k>0&&!pq.empty()){
            if(k>=mx){
                break;
            }
            while(!pq.empty()){
                if(-a.second<=power){
                    pq.pop();
                    a= pq.top();
                }
                else break;
            }
            k =k-(-a.first);
            if(k<0) break;
            power = power+k;
            pq.push(a);
        }
        //if kill all
        if(power>=mx) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}

//solve by : Anas Alamri