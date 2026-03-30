```cpp
// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int INF = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 2005;

// --------------------- 基础DP问题 ---------------------

// 01背包问题 - 每个物品最多选一次
int knapsack01(const vector<int> &weights, const vector<int> &values, int capacity)
{
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = capacity; j >= weights[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

    return dp[capacity];
}

// 完全背包问题 - 每个物品可以选无限次
int knapsackComplete(const vector<int> &weights, const vector<int> &values, int capacity)
{
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = weights[i]; j <= capacity; j++)
        {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

    return dp[capacity];
}

// 多重背包问题 - 每个物品有特定数量限制
int knapsackMultiple(const vector<int> &weights, const vector<int> &values,
                     const vector<int> &counts, int capacity)
{
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; i++)
    {
        // 二进制优化 - 将k个物品拆成二进制表示
        int w = weights[i], v = values[i], c = counts[i];
        for (int k = 1; k <= c; k *= 2)
        {
            for (int j = capacity; j >= k * w; j--)
            {
                dp[j] = max(dp[j], dp[j - k * w] + k * v);
            }
            c -= k;
        }

        if (c > 0)
        {
            for (int j = capacity; j >= c * w; j--)
            {
                dp[j] = max(dp[j], dp[j - c * w] + c * v);
            }
        }
    }

    return dp[capacity];
}

// 最长递增子序列 (LIS)
int longestIncreasingSubsequence(const vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

// 最长递增子序列优化版 (O(nlogn))
int longestIncreasingSubsequenceOptimized(const vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    vector<int> tails;

    for (int num : nums)
    {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end())
        {
            tails.push_back(num);
        }
        else
        {
            *it = num;
        }
    }

    return tails.size();
}

// 最长公共子序列 (LCS)
int longestCommonSubsequence(const string &text1, const string &text2)
{
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

// 编辑距离
int editDistance(const string &word1, const string &word2)
{
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
        }
    }

    return dp[m][n];
}

// --------------------- 区间DP ---------------------

// 石子合并问题 - 求合并代价最小值
int mergeStones(const vector<int> &stones)
{
    int n = stones.size();
    if (n <= 1)
        return 0;

    // 前缀和加速区间求和
    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefixSum[i + 1] = prefixSum[i] + stones[i];
    }

    // dp[i][j] 表示合并区间[i,j]的最小代价
    vector<vector<int>> dp(n, vector<int>(n, INF));

    // 初始化：单个石子无需合并
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }

    // 按区间长度递推
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;

            // 尝试在不同位置分割
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + prefixSum[j + 1] - prefixSum[i]);
            }
        }
    }

    return dp[0][n - 1];
}

// --------------------- 树形DP ---------------------

// 树的最大独立集 (在树上选择不相邻的节点使得权值和最大)
void dfsIndependentSet(int node, int parent, const vector<vector<int>> &tree,
                       const vector<int> &values, vector<vector<int>> &dp)
{
    for (int child : tree[node])
    {
        if (child != parent)
        {
            dfsIndependentSet(child, node, tree, values, dp);
            // dp[node][0] - 不选当前节点
            dp[node][0] += max(dp[child][0], dp[child][1]);
            // dp[node][1] - 选当前节点
            dp[node][1] += dp[child][0];
        }
    }
    dp[node][1] += values[node]; // 加上当前节点的权值
}

int maxIndependentSet(const vector<vector<int>> &tree, const vector<int> &values)
{
    int n = values.size();
    // dp[i][0] - 不选节点i的最大值, dp[i][1] - 选节点i的最大值
    vector<vector<int>> dp(n, vector<int>(2, 0));

    dfsIndependentSet(0, -1, tree, values, dp);
    return max(dp[0][0], dp[0][1]);
}

// --------------------- 状态压缩DP ---------------------

// 旅行商问题 (TSP)
int tsp(const vector<vector<int>> &dist)
{
    int n = dist.size();
    // dp[mask][i] 表示已经访问的城市集合为mask，当前在城市i的最短路径
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));

    // 起点为城市0
    dp[1][0] = 0; // 只访问城市0的状态

    for (int mask = 1; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if ((mask >> i) & 1)
            { // 城市i已访问
                for (int j = 0; j < n; j++)
                {
                    if ((mask >> j) & 1 && i != j)
                    { // 城市j也已访问
                        dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + dist[j][i]);
                    }
                }
            }
        }
    }

    // 所有城市都访问并回到起点
    int result = INF;
    for (int i = 1; i < n; i++)
    {
        if (dist[i][0] != INF)
        {
            result = min(result, dp[(1 << n) - 1][i] + dist[i][0]);
        }
    }

    return result;
}

// --------------------- 数位DP ---------------------

// 计算区间[l,r]中满足条件的数字个数
int digitDP(int l, int r)
{
    vector<int> digits;

    // 数位分解函数
    auto getDigits = [&](int num)
    {
        vector<int> result;
        while (num)
        {
            result.push_back(num % 10);
            num /= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    };

    // DP函数，自行定义状态和转移方程
    function<int(int, bool, bool, int)> dp = [&](int pos, bool isLimit, bool isNum, int state)
    {
        // 实现特定问题的状态转移逻辑
        // pos: 当前处理到的位置
        // isLimit: 是否有上界限制
        // isNum: 前面是否已经有数字了
        // state: 问题相关的状态

        if (pos == digits.size())
        {
            return isNum ? 1 : 0; // 根据具体问题调整返回值
        }

        // 这里补充具体问题的状态转移逻辑

        return 0; // 占位返回
    };

    // 计算[0,r]的结果
    digits = getDigits(r);
    int right_result = dp(0, true, false, 0);

    // 计算[0,l-1]的结果
    digits = getDigits(l - 1);
    int left_result = dp(0, true, false, 0);

    // 返回区间结果
    return right_result - left_result;
}

// --------------------- 概率DP ---------------------

// 骰子问题 - 投掷n个骰子，点数和为target的概率
double diceProb(int n, int target)
{
    if (target < n || target > 6 * n)
        return 0.0;

    vector<vector<double>> dp(n + 1, vector<double>(6 * n + 1, 0.0));
    // 初始化：一个骰子
    for (int i = 1; i <= 6; i++)
    {
        dp[1][i] = 1.0 / 6.0;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= 6 * i; j++)
        {
            for (int k = 1; k <= 6 && k < j; k++)
            {
                dp[i][j] += dp[i - 1][j - k] * (1.0 / 6.0);
            }
        }
    }

    return dp[n][target];
}

// --------------------- 实用DP子问题 ---------------------

// 最大子序和 (Kadane算法)
int maxSubArray(const vector<int> &nums)
{
    int currMax = nums[0], globalMax = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        currMax = max(nums[i], currMax + nums[i]);
        globalMax = max(globalMax, currMax);
    }

    return globalMax;
}

// 最大子矩阵和
int maxSubMatrix(const vector<vector<int>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;

    int rows = matrix.size(), cols = matrix[0].size();
    int result = INT_MIN;

    for (int left = 0; left < cols; left++)
    {
        vector<int> tempSum(rows, 0);

        for (int right = left; right < cols; right++)
        {
            // 将二维问题转化为一维
            for (int i = 0; i < rows; i++)
            {
                tempSum[i] += matrix[i][right];
            }

            // 应用Kadane算法找一维最大子序和
            int kadaneMax = tempSum[0];
            int currMax = tempSum[0];

            for (int i = 1; i < rows; i++)
            {
                currMax = max(tempSum[i], currMax + tempSum[i]);
                kadaneMax = max(kadaneMax, currMax);
            }

            result = max(result, kadaneMax);
        }
    }

    return result;
}

// 最长回文子串
string longestPalindrome(const string &s)
{
    int n = s.size();
    if (n == 0)
        return "";

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int start = 0, maxLen = 1;

    // 所有长度为1的子串都是回文
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }

    // 检查长度为2的子串
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    // 检查长度大于2的子串
    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;
                start = i;
                maxLen = len;
            }
        }
    }

    return s.substr(start, maxLen);
}

// 矩阵链乘法
int matrixChainMultiplication(const vector<int> &dims)
{
    int n = dims.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1]);
            }
        }
    }

    return dp[0][n - 1];
}

void solve()
{
    // 测试背包问题
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    cout << "01背包最大价值: " << knapsack01(weights, values, 10) << endl;
    cout << "完全背包最大价值: " << knapsackComplete(weights, values, 10) << endl;

    // 测试LIS
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "最长递增子序列长度: " << longestIncreasingSubsequence(nums) << endl;
    cout << "优化的最长递增子序列长度: " << longestIncreasingSubsequenceOptimized(nums) << endl;

    // 测试LCS
    cout << "最长公共子序列长度: " << longestCommonSubsequence("abcde", "ace") << endl;

    // 测试编辑距离
    cout << "编辑距离: " << editDistance("horse", "ros") << endl;

    // 测试区间DP
    vector<int> stones = {3, 2, 4, 1};
    cout << "石子合并最小代价: " << mergeStones(stones) << endl;

    // 测试最大子序和
    vector<int> subarr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "最大子序和: " << maxSubArray(subarr) << endl;

    // 测试最长回文子串
    cout << "最长回文子串: " << longestPalindrome("babad") << endl;
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
    }
    return 0;
}
```