#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x)
        : val(x), left(NULL), right(NULL)
    {
    }
    TreeNode()
        : val(0), left(NULL), right(NULL)
    {
    }
};
//非递归中顺遍历
void InOrderTraverse(TreeNode* root)
{
    stack<TreeNode*> path;
    TreeNode* pcur =root;
    while (pcur!=NULL || path.empty() ==false)
    {
         while (pcur !=NULL)
         {
            path.push(pcur);
            pcur =pcur->left;
         }
         if (path.empty() ==false)
         {
            pcur = path.top();
            cout<< "pop= "<<pcur->val<<endl; 
            path.pop();

            pcur =pcur->right;
         }
         
    }

}

///////////////////////////////////////////////////////////////////////////
class Solution
{
public:
    /**
     * [Convert description]
     * @AuthorHTL wang_cyi
     * @DateTime  二〇二〇年一月八日 17:28:42
     * @param     pRootOfTree              [二叉搜索树的根]
     * @return                             [转换成双链表的头结点]
     * @how
     *  中顺遍历，只能获取currNode 和preNode。
     *  2点确定一线
     *  试图三点解决这个问题是错误的。
     */
    TreeNode* ConvertByStack(TreeNode* pRootOfTree)
    {
         if (NULL == pRootOfTree)
         {
             return NULL;
         }
   
        
        stack<TreeNode*> path;
        TreeNode* currNode =pRootOfTree;
        
        TreeNode* preNode =NULL;
        TreeNode* head = NULL;
        
        while (currNode !=NULL || !path.empty())
        {
            while (currNode !=NULL)
            {
               path.push(currNode);
               currNode = currNode->left;
            }

            if (!path.empty())
            {
                currNode = path.top();
                path.pop(); 
                // 当前节点左子tree为null，当前节点pop,
                //当前currNode->right为null，currNode 上一个节点Pop

                if (preNode == NULL)
                {  //fist node
                   head = currNode;
                }
                else
                {
                    //swap
                    preNode->right =currNode;
                    currNode->left =preNode;

                }
                
                preNode =currNode;//change
                currNode = currNode->right;//change
            }
            
            
        }
        
        return head;
          
    }

  /**
     * [ConvertRecursion 递归的将root为根的二叉排序树专户才能成双向链表]
     * @AuthorHTL
     * @DateTime  2020年1月8日 18:15:53
     * @param     root                     [当前递归的二叉排序树的根节点]
     * @param     pLastNode                [中序遍历中指向前一个节点的指针]
     */
    void ConvertRecursion(TreeNode *root, TreeNode **pLastNode)
    {
       if (root == NULL)
       {
          return ;
       }

       TreeNode *pCurrNode = root;

        //////////////////////////
        /// 首先中序 递归左子树
        //////////////////////////
       // if(pCurrNode->left != NULL)
        //{
            ConvertRecursion(pCurrNode->left, pLastNode);
       // }
        
        if (*pLastNode == NULL)
        {
            //第一个节点
        }else
        {
             (*pLastNode)->left = pCurrNode;
              pCurrNode->right = *pLastNode;
        }
        
        

        *pLastNode =pCurrNode; //变化
          
         //////////////////////////
         /// 首先中序 递归右子树
        //////////////////////////


        //if(pCurrNode->right != NULL)
       // {
            ConvertRecursion(pCurrNode->left, pLastNode);
        //}
       
    }
};
int main()
{
    //    4
    //  3   5
    //2
    TreeNode tree[4];
    tree[0].val = 4;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];
    tree[1].val = 3;
    tree[1].left = &tree[3];
    tree[1].right = NULL;
    tree[2].val = 5;
    tree[2].left = NULL;
    tree[2].right = NULL;
    tree[3].val = 2;
    tree[3].left = NULL;
    tree[3].right = NULL;

    InOrderTraverse(&tree[0]);

    Solution so;
    so.ConvertByStack(&tree[0]);
}