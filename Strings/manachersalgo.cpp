#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M= 1000000007;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
bool cmp(pair<int,int> &a, pair<int,int> &b)
{
    return (a.second < b.second) ; 
}
void manacher(string s)
{
    vector<int> lps(s.size(),0);
    int r = 0,c = 0 ;
    int n = s.size(); 
    for(int i = 1 ; i< n-1;i++)
    {
        int mirror = c-(i-c);
        if(i<r)
        {
            lps[i] = min(lps[mirror],r-i);
        }
        while(s[i+lps[i]+1] == s[i-lps[i]-1]){
            lps[i]++;
        // cout << lps[i] << " ";
        }
    // cout <<endl;
        if(i+lps[i]>r)
        {
            c = i;
            r = i+lps[i];
        }
    }
    int len = 0;
    int idx = -1;
    // for(auto it : lps)
        // cout << it << endl;
    for(int i = 1; i<n ; i++)
    {
        if(lps[i] > len){
            len = lps[i];
            idx = i; 
        }
    }
    int firstidx = idx - len +1;
    int actidx = (firstidx-2)/2;
    // cout<<len<<endl;
    cout << actidx<<" "<<actidx+len  << endl;

}
int main(void)
{    fast; 
    ll t ; t = 1; 
    // cin >> t;
    while(t--){
        string s = "@#a#b#a#b#a#b#a#&";
        manacher(s);
    }               
}
// vector<ll> a;
// for(auto &i : a)cin >> i;
// for(auto it : a)cout << it << " ";
// for(int i = 0; i<n ;i++)
// cout << endl;
