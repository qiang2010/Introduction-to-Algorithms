#include <iostream>

using namespace std;

const int MAX_NUM = 50;
struct node{
  char data;
  node *left= 0;
  node *right = 0;
};

// 为了方便起见，不使用动态分配，而是使用静态内存分配
node Tree[MAX_NUM];
int  loc = 0;
// *****构建二叉树的函数如下*****
    /*构建二叉树方法一
    *
    *输入：先根序列，空用#表示
    *返回：根结点的指针
    * eg.   AB##CD##E##  #代表空
    */
node * buildBinaryTree1(){



}

  /*构建二叉树方法二
    * 输入：先根序列 和 中根序列
    * 返回： 根节点的指针
    */
node * buildBinaryTree2(){


}
// *****遍历二叉树的函数*****
void preOrder(Node *){
}


int main(){


}
