#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)
int n;
vector<vector<int>> a;
int m;
vector<vector<int>> b;

int main()
{
    scanf("%d", &n);
    a.resize(n);
    forn(i, n)
    {
        int c;
        scanf("%d", &c);
        a[i].resize(c);
        forn(j, c) scanf("%d", &a[i][j]);
    }
    scanf("%d", &m);
    b.resize(m);
    forn(i, m)
    {
        b[i].resize(n);
        forn(j, n)
        {
            scanf("%d", &b[i][j]);
            --b[i][j];
        }
    }
    sort(b.begin(), b.end());
    vector<int> ult(n);
    forn(i, n) ult[i] = int(a[i].size()) - 1;
    if (!binary_search(b.begin(), b.end(), ult))
    {
        forn(i, n) printf("%d ", ult[i] + 1);
        puts("");
        return 0;
    }
    int mx = 0;
    vector<int> ans(n, -1);
    forn(i, m)
    {
        vector<int> tmp = b[i]; // starting from banned build
        int sum = 0;
        forn(j, n) sum += a[j][tmp[j]]; // get sum
        forn(j, n) if (tmp[j] != 0)
        {             // iterate through slots, degrade it if possible
            --tmp[j]; // degrade
            if (!binary_search(b.begin(), b.end(), tmp) && sum - a[j][tmp[j] + 1] + a[j][tmp[j]] > mx)
            { // if it is not banned and current sum is max
                mx = sum - a[j][tmp[j] + 1] + a[j][tmp[j]];
                ans = tmp;
            }
            ++tmp[j]; // restore
        }
    }
    forn(i, n)
    {
        printf("%d ", ans[i] + 1);
    }
    puts("");
}