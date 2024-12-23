#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2410 lang=cpp
 * @lcpr version=20002
 *
 * [2410] 运动员和训练师的最大匹配数
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        // players are more than trainers so we add trainers' index first
        // remember that less trainer matches less player first u will get the ac;
        int indexPlayers = 0, totalMatches = 0;

        for (int indexTrainers = 0; indexTrainers < trainers.size(); indexTrainers++)
        {
            if (indexPlayers < players.size() && players[indexPlayers] <= trainers[indexTrainers])
            {
                // when successfully match player and trainer we add indexPlayers to continue the next player 'cause we must move indexPlayers;
                indexPlayers++;
                totalMatches++;
            }
        }
        return totalMatches;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,7,9]\n[8,2,5,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n[10]\n
// @lcpr case=end

 */
