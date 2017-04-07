#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lim 100120
#define pb push_back
#define S second
#define pb push_back
#define mp make_pair
#define INF 1e17
#define fr(i,j,k) for(ll i=j;i<=k;i++)
#define frd(i,j,k) for(ll i=j;i>=k;i--)
#define F first
#define sd(n) scanf("%lld",&n)
#define pd(n) printf("%lld\n",n)
#define db double
#define pii pair<ll,ll>
ll s;
db num(string q)
{
    db ans=0;
    for(int i=0;i<q.length();i++)
        ans=10*ans+q[i]-'0';
    return ans;
}
vector<db> mul(vector<db>&a,vector<db>&b)
{   int kl=a.size()+b.size();
    if(a.size()<b.size())
        swap(a,b);
    db ans[kl+5];
    for(int i=0;i<kl+5;i++)
    {
        ans[i]=0;
    }
    for(int i=0;i<b.size();i++)
    {
        for(int j=0;j<a.size();j++)
        {
            ans[i+j]+=a[j]*b[i];
        }
    }
    vector<db>v;
    for(int i=0;i<=kl;i++)
        v.pb(ans[i]);
    return v;
}
db getans(string q,db h)
{
    int n=q.length();
    for(int i=0;i<n;i++)
    {
        if(q[i]=='+')
        {
            db u=h-num(q.substr(i+1));
            return getans(q.substr(0,i),u);
        }
        if(q[i]=='-')
        {
            db u=h+num(q.substr(i+1));
            return getans(q.substr(0,i),u);
        }
    }
    db x,y;
    for(int i=0;i<n;i++)
    {
        if(q[i]=='d')
        {
            x=num(q.substr(0,i));
            y=num(q.substr(i+1));
            break;
        }
    }
    vector<db>v;
    vector<db>final_ans;
    v.pb(0); 
    final_ans.pb(0);
    for(int i=1;i<=y;i++)
        {
            v.pb(1);
            final_ans.pb(1);
        }
        for(ll i=2;i<=x;i++)
            final_ans=mul(final_ans,v);        
        db sm=0;
        for(int i=max(h,0.0);i<final_ans.size();i++)
            sm+=final_ans[i];
        double nm=sm;
        double den=pow(y,x);
        nm/=den;
        return nm;
}
int main()
{
    ll t;
    cin>>t;
    for(int u=1;u<=t;u++)
    {
        cout<<"Case #"<<u<<": ";
        db h;
        cin>>h>>s;
        db ans=0;
        for(int k=0;k<s;k++)
        {
            string sr;
            cin>>sr;            
            ans=max(ans,getans(sr,h));
        }
        printf("%.6f\n",ans);
    }
}
