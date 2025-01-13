#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例: 输入: n = 4, k = 2 输出: [ [2,4], [3,4], [2,3], [1,2], [1,3], [1,4], ]
*/

vector<vector<int>> result;
vector<int> path;

auto it = path.begin();

void backtracking()
{
    if (startindex == )
    {
        result.push_back(path);
        return;
    }

    for (int i = startindex; i < v.size(); i++)
    {
        path.push_back(i);
    }
}


/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出: [ [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1] ]
*/




/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例: 输入: nums = [1,2,3] 输出: [ [3],   [1],   [2],   [1,2,3],   [1,3],   [2,3],   [1,2],   [] ]
*/




signed main()
{
    
}