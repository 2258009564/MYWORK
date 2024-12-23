/**
 * File: binary_search_tree.cpp
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* 二元搜尋樹 */
class BinarySearchTree {
  private:
    TreeNode *root;

  public:
    /* 建構子 */
    BinarySearchTree() {
        // 初始化空樹
        root = nullptr;
    }

    /* 析構方法 */
    ~BinarySearchTree() {
        freeMemoryTree(root);
    }

    /* 獲取二元樹根節點 */
    TreeNode *getRoot() {
        return root;
    }

    /* 查詢節點 */
    TreeNode *search(int num) {
        TreeNode *cur = root;
        // 迴圈查詢，越過葉節點後跳出
        while (cur != nullptr) {
            // 目標節點在 cur 的右子樹中
            if (cur->val < num)
                cur = cur->right;
            // 目標節點在 cur 的左子樹中
            else if (cur->val > num)
                cur = cur->left;
            // 找到目標節點，跳出迴圈
            else
                break;
        }
        // 返回目標節點
        return cur;
    }

    /* 插入節點 */
    void insert(int num) {
        // 若樹為空，則初始化根節點
        if (root == nullptr) {
            root = new TreeNode(num);
            return;
        }
        TreeNode *cur = root, *pre = nullptr;
        // 迴圈查詢，越過葉節點後跳出
        while (cur != nullptr) {
            // 找到重複節點，直接返回
            if (cur->val == num)
                return;
            pre = cur;
            // 插入位置在 cur 的右子樹中
            if (cur->val < num)
                cur = cur->right;
            // 插入位置在 cur 的左子樹中
            else
                cur = cur->left;
        }
        // 插入節點
        TreeNode *node = new TreeNode(num);
        if (pre->val < num)
            pre->right = node;
        else
            pre->left = node;
    }

    /* 刪除節點 */
    void remove(int num) {
        // 若樹為空，直接提前返回
        if (root == nullptr)
            return;
        TreeNode *cur = root, *pre = nullptr;
        // 迴圈查詢，越過葉節點後跳出
        while (cur != nullptr) {
            // 找到待刪除節點，跳出迴圈
            if (cur->val == num)
                break;
            pre = cur;
            // 待刪除節點在 cur 的右子樹中
            if (cur->val < num)
                cur = cur->right;
            // 待刪除節點在 cur 的左子樹中
            else
                cur = cur->left;
        }
        // 若無待刪除節點，則直接返回
        if (cur == nullptr)
            return;
        // 子節點數量 = 0 or 1
        if (cur->left == nullptr || cur->right == nullptr) {
            // 當子節點數量 = 0 / 1 時， child = nullptr / 該子節點
            TreeNode *child = cur->left != nullptr ? cur->left : cur->right;
            // 刪除節點 cur
            if (cur != root) {
                if (pre->left == cur)
                    pre->left = child;
                else
                    pre->right = child;
            } else {
                // 若刪除節點為根節點，則重新指定根節點
                root = child;
            }
            // 釋放記憶體
            delete cur;
        }
        // 子節點數量 = 2
        else {
            // 獲取中序走訪中 cur 的下一個節點
            TreeNode *tmp = cur->right;
            while (tmp->left != nullptr) {
                tmp = tmp->left;
            }
            int tmpVal = tmp->val;
            // 遞迴刪除節點 tmp
            remove(tmp->val);
            // 用 tmp 覆蓋 cur
            cur->val = tmpVal;
        }
    }
};

/* Driver Code */
int main() {
    /* 初始化二元搜尋樹 */
    BinarySearchTree *bst = new BinarySearchTree();
    // 請注意，不同的插入順序會生成不同的二元樹，該序列可以生成一個完美二元樹
    vector<int> nums = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};
    for (int num : nums) {
        bst->insert(num);
    }
    cout << endl << "初始化的二元樹為\n" << endl;
    printTree(bst->getRoot());

    /* 查詢節點 */
    TreeNode *node = bst->search(7);
    cout << endl << "查詢到的節點物件為 " << node << "，節點值 = " << node->val << endl;

    /* 插入節點 */
    bst->insert(16);
    cout << endl << "插入節點 16 後，二元樹為\n" << endl;
    printTree(bst->getRoot());

    /* 刪除節點 */
    bst->remove(1);
    cout << endl << "刪除節點 1 後，二元樹為\n" << endl;
    printTree(bst->getRoot());
    bst->remove(2);
    cout << endl << "刪除節點 2 後，二元樹為\n" << endl;
    printTree(bst->getRoot());
    bst->remove(4);
    cout << endl << "刪除節點 4 後，二元樹為\n" << endl;
    printTree(bst->getRoot());

    // 釋放記憶體
    delete bst;

    return 0;
}
