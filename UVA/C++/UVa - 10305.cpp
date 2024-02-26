// question: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1246
#include<iostream>
using namespace std;

int main()
{
    int n, m, u, v, cnt;
    int adj[101][101];
    int inDegree[101];
    int used[101];
    bool flag;

    while (cin >> n >> m && n)
    {
        cnt = 0;
        flag = 0;
        for (int i = 0; i<101; i++)
        {
            for (int j = 0; j<101; j++) adj[i][j] = 0;
            inDegree[i] = 0;
            used[i] = 0;
        }

        for (int i = 0; i<m; i++)
        {
            cin >> u >> v;
            if(adj[u][v]==0) inDegree[v]++;
            adj[u][v] = 1;
        }

        while (cnt<n)
        {
            for (int i = 1; i <= n && cnt<n; i++)
            {
                if (used[i] == 0 && inDegree[i] == 0)
                {
                    used[i] = 1;
                    cnt++;
                    if (flag) cout << " ";
                    flag = 1;
                    cout << i;

                    for (int j = 1; j <= n; j++) if (adj[i][j]) inDegree[j]--;
                }
            }
        }
        cout << endl;
    }
}
