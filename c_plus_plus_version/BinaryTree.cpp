#include <iostream>

using namespace std;

const int MAX_NUM = 50;
struct node{
  char data;
  node *left;
  node *right;
  node(){
  left = right = 0;
  }
};

// ++ 为了方便起见，不使用动态分配，而是使用静态内存分配
// ++ 假定树中的节点数目小于 MAX_NUM
node Tree[MAX_NUM];
int  loc = 0;
// *****构建二叉树的函数如下*****
    /*构建二叉树方法一
    * 非递归
    *输入：先根序列，空用#表示
    *返回：根结点的指针
    * eg.   AB##CD##E##  #代表空
    */
    string pre ;
    int preOrderLoc = 0;
node * buildPreOrder(int a);
node* buildBinaryTreeFromPreOrder(){
    cout<<"Please input preorder with # for null"<<endl;
    cin>>pre;
    return buildPreOrder(0);
}
node * buildPreOrder(int a){
    // 递归结束判断，当为 # 表明是null
    if (pre[a] == '#'){  return 0;}

    // 递归建立左子树
    preOrderLoc++;
    node * left  = buildPreOrder(preOrderLoc);
    // 递归建立右子树
    preOrderLoc++;
    node * right = buildPreOrder(preOrderLoc);
    node *temp = &Tree[loc];
    loc++;
    cout<<"loc:"<<loc<<endl;
    (*temp).data  = pre[a];
    (*temp).left = left;
    (*temp).right = right;
    return temp;
}

  /*构建二叉树方法二
    * 输入：先根序列 和 中根序列
    * 返回： 根节点的指针
    */
node * buildBinaryTreeFromPreAndInOrder(){


}
// *****遍历二叉树的函数*****
// *****递归先序遍历*****
void preOrderRec(node *root){
    if(root == 0 ) return;
    cout<<(*root).data<<" ";
    preOrderRec((*root).left);
    preOrderRec((*root).right);
}

// ***** 层次遍历输出二叉树*****
void levelOrderPrint(node * root){

}

int main(){
    preOrderRec(buildBinaryTreeFromPreOrder());


}
