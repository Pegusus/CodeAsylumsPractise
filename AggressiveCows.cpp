Problem Link -
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(ll cows,ll positions[],ll n,ll distance)
{
    int count = 1;
    ll last_position = positions[0];

    for(int i = 1;i<n;i++)
    {
        if(positions[i]-last_position>=distance)
        {
            last_position = positions[i];
            count++;
        }
        if(cows==count)return true;
    }
    return false;
}
int main() {

	// Write your code here
    int t;
    cin>>t;
    while(t--)
    {
        ll n,c;
        cin>>n>>c;

        ll positions[n],ans;

        for(int i = 0;i<n;i++)
            cin>>positions[i];
        sort(positions,positions+n);

        ll start = positions[0];
        ll end = positions[n-1]-positions[0];

        while(start<=end)
        {
            ll mid = start + (end-start)/2;

            if(check(c,positions,n,mid))
            {
                ans = mid;
                start = mid+1;

            }
            else
                end = mid-1;
        }
        cout<<ans<<endl;

    }
}
