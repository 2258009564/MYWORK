#include <bits/stdc++.h>
using namespace std;
#define BUFF ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define int long long
#define endl '\n'

signed main()
{
    BUFF;
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> cards(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cards[i];
    }

    // 函数：查找一个给定数组中可以组成的最大顺子的长度
    auto find_max_len = [&](vector<int> &cards) -> int
    {
        int left = 0, max_len = 0;
        int missing = 0;

        // 扩展窗口
        for (int right = 0; right < n; right++)
        {
            // 如果当前牌和前一张牌不连续，则增加缺失的牌数
            if (right > 0 && cards[right] != cards[right - 1] + 1)
            {
                missing++;
            }

            // 当使用的鬼牌超过k时，需要缩小窗口
            while (missing > k)
            {
                if (cards[left + 1] != cards[left] + 1)
                {
                    missing--;
                }
                left++;
            }

            // 更新最大顺子长度
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    };

    // 处理递增顺子的情况
    int max_len = find_max_len(cards);

    // 处理递减顺子的情况：先反转牌的顺序
    reverse(cards.begin(), cards.end());

    // 找到递减顺子的最大长度
    max_len = max(max_len, find_max_len(cards));

    cout << max_len << endl;
    return 0;
}
