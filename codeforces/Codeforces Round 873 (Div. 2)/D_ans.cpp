#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1000010;

ll a[N];
ll mina[N];

void solve()
{
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		ans+=(n-i+1)*(i-1);
	}
	for(ll i=1;i<=n;i++)
	{
		ll k=a[i];
		ll l=i;
		ll r=i;
		ll h=i;
		while(h>0&&a[h]>=k) 
		{
			h--;
		}
		l=h;
		while(l>0&&a[l]<=k) 
		{
			l--;
		}
		while(r<=n&&a[r]>=k) 
		{
			r++;
		}
		ans-=(r-i)*(h-l); 
    cout<<(r-i)*(h-l)<<'\n';
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T=1;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
