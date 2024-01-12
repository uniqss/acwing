
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, long long> PIL;
typedef pair<long long, int> PLI;
#define ALL(__x__) __x__.begin(), __x__.end()

/*
dijkstra算法的流程如下：
1.初始化 dist[1] = 0 ，其余节点的 dist 值为正无穷大
2. 找出一个未被标记的， dist[x] 最小的节点 x ,然后标记节点 x
3. 扫描节点 x 的所有出边 (x, y, z) ，若 dist[y] > dist[x] + z ，则使用 dist[x] + z 更新 dist[y]
4. 重复上述 2~3 两个步骤，直到所有节点都被标记
注意事项：只适用于所有边长非负

这里用力扣 834. Sum of Distances in Tree 作为实验数据
*/

int a[3010][3010], d[3010], n, m;
bool v[3010];
void dijkstra() {
    memset(d, 0x3f, sizeof(d));  // dist数组
    d[1] = 0;
    for (int i = 1; i < n; ++i) {
        int x = 1;
        // 找到未标记节点中dist最小的
        for (int j = 1; j <= n; ++j)
            if (!v[j] && (x == 0 || d[j] < d[x])) x = j;
        v[x] = 1;
        // 用全局最小值点 x 更新其他节点
        for (int y = 1; y <= n; ++y) {
            d[y] = min(d[y], d[x] + a[x][y]);
        }
    }
}

void test(const vector<vector<int>>& edges) {
    // 构建邻接矩阵
    memset(a, 0x3f, sizeof(a));
    for (int i = 1; i <= n; ++i) a[i][i] = 0;
    m = edges.size();
    for (const auto& e : edges) {
        int x = e[0], y = e[1], z = e[2];
        a[x][y] = min(a[x][y], z);
    }
    // 求单源最短路径
    dijkstra();
    for (int i = 1; i <= n; ++i) {
        cout << d[i] << " ";
    }
    cout << endl;
}
int main() {
    test({{}})
    return 0;
}
