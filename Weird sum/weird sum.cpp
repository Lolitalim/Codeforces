
// CodeForces Round #775 Div.1 A.Weird Sum
// Calculate the manhattan distances of one table of each color
// Solution: For point (i,j), consider the contribution to the answer between this point and the previous points of the same color
# include<bits/stdc++.h>
# define ll long long
using namespace std;
const int N = 1e5+10;
int n,m,cnt[N]; // n rows,m columns, count for each color
ll ans,mp[N]; // sum of all colors, partial sum of each color

main()
{
    cin >> n >> m; // number of rows and columns in the table
    ll g[n+10][m+10]; // initiate the table

    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j)
        {
            cin >> g[i][j]; // input each cell
            int t = g[i][j]; // store this cell
            ans += (ll)i * cnt[t] - mp[t]; // row: i * (count of the previous same color points) - i partial sum of this color
            cnt[t]++; // count + 1 for this color
            mp[t] += i; // add i of this cell to partial sum of each color
        }

    memset(cnt,0,sizeof cnt); // set count to 0
    memset(mp,0,sizeof mp); // set partial sum of each color to 0

    for(int j = 1;j <= m;++j)
        for(int i = 1;i <= n;++i)
        {
            int t = g[i][j];
            ans += (ll)j * cnt[t] - mp[t];// col: j * (count of the previous same color points) - j partial sum of this color
            cnt[t]++;// count + 1 for this color
            mp[t] += j; // add j of this cell to partial sum of each color
        }
    cout << ans;
}
