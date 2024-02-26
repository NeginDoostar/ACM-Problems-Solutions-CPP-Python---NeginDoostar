#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, m;
bool ans;
vector<int>v1, v2;
vector<bool>used;

void bt(int, int);

int main()
{
    int a, b, x, y;
    while (cin >> N && N)
    {
        cin >> m;

        ans = 0;
        v1.clear();
        v2.clear();
        used.clear();
        used.assign(m + 1, 0);

        cin >> a >> b;
        v1.push_back(a);
        v2.push_back(b);
        cin >> x >> y;
        //m
        for (int i = 0; i<m; i++)
        {
            cin >> a >> b;
            v1.push_back(a);
            v2.push_back(b);
        }
        //
        v1.push_back(x);
        v2.push_back(y);
        bt(0, v2[0]);
        if (!ans) cout << "NO\n";
        else cout << "YES\n";
    }
}

void bt(int n, int last)
{
    if (n == N)
    {
        if (last == v1[v1.size() - 1]) ans = 1;
    }

    for (int i = 1; i <= m && !ans; i++)
    {
        if (used[i]) continue;
        if (n<N && last == v1[i])
        {
            used[i] = 1;
            bt(n + 1, v2[i]);
            used[i] = 0;
        }
        else if (n<N && last == v2[i])
        {
            used[i] = 1;
            bt(n + 1, v1[i]);
            used[i] = 0;
        }
    }
}
