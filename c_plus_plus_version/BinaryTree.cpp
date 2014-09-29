#include <iostream>
#include <queue>
#include <cstddef>
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
string pre ;    //++ pre 存放用于构建二叉树的先根序列，其中#表示NULL
size_t preOrderLoc = 0; // ++ 用于指示pre中的字符
node * buildPreOrder(size_t a);
node* buildBinaryTreeFromPreOrder(){
  cout<<"Please input preorder with # for null"<<endl;
  cin>>pre;
  return buildPreOrder(0);
}
node * buildPreOrder(size_t a){
  // 递归结束判断，当为 # 表明是null
  if (pre[a] == '#'){  return 0;}

  // 递归建立左子树
  preOrderLoc++;
  node * left  = buildPreOrder(preOrderLoc);

  // 递归建立右子树
  preOrderLoc++;
  node * right = buildPreOrder(preOrderLoc);

  // 静态申请一个变量
  node *temp = &Tree[loc];
  loc++;
  // cout<<"loc:"<<loc<<endl;
  (*temp).data  = pre[a];
  (*temp).left = left;
  (*temp).right = right;
  return temp;
}

/*构建二叉树方法二
 * 输入：先根序列 和 中根序列
 * 返回： 根节点的指针
*/
string inOrder; // ++ 中根遍历的序列
node * buildRecur(size_t preLoc1,size_t preLoc2,size_t inLoc1,size_t inLoc2);
node * buildBinaryTreeFromPreAndInOrder(){
  cout<< "Please input preOrder:"<<endl;
  cin>>pre;
  cout<< "Please input inOrder:"<<endl;
  cin>>inOrder;
  return buildRecur(0, pre.size(), 0 , inOrder.size());
}
// 递归通过先根 和 中根 构建二叉树
node * buildRecur(size_t preLoc1,size_t preLoc2,size_t inLoc1,size_t inLoc2){
  if (preLoc1>preLoc2 || inLoc1 > preLoc2 )  return NULL;
  char  tempRoot = pre[preLoc1];
  size_t tempRootLoc = -1;
  for ( size_t i = inLoc1 ; i <= inLoc2; i ++){
    if(inOrder[i] == tempRoot) {
      tempRootLoc = i;
      break;
    }
  }
  int  leftLen = tempRootLoc - inLoc1 ;
  int  rightLen = inLoc2 - tempRootLoc ;
  node * left = buildRecur(preLoc1+1,preLoc1+leftLen,inLoc1,inLoc1+leftLen-1);
  node * right = buildRecur(preLoc1+leftLen+1,preLoc2,tempRootLoc+1,inLoc2);
  node *root = &Tree[loc];
  loc++;
  (*root).data = pre[preLoc1];
  (*root).left = left;
  (*root).right = right;
  return root;
}

// *****遍历二叉树的函数*****
// *****递归先序遍历*****
void preOrderRec(node *root){
  if(root == 0 ) return;
  cout<<(*root).data<<" ";
  preOrderRec((*root).left);
  preOrderRec((*root).right);
}
// ***** 递归中序遍历 *****
void inOrderRec(node * root){
  if ( root == 0 ) return ;
  inOrderRec((*root).left);
  cout<< (*root).data<<" ";
  inOrderRec((*root).right);
}
// ***** 递归后根遍历*****
void postOrderRec(node * root){
  if ( root == 0 ) return ;
  postOrderRec((*root).left);
  postOrderRec((*root).right);
  cout<< (*root).data<<" |";
}
// ***** 层次遍历输出二叉树*****
void levelOrderPrint(node * root){
  queue<*node> que;
  que.push_back(root);
}

int main(){
  //preOrderRec(buildBinaryTreeFromPreOrder());
  node * root =  buildBinaryTreeFromPreAndInOrder();
  cout<<"PreOrder: "<<endl;
  preOrderRec(root);
  cout<<"\n"<<"InOrder: "<<endl;
  inOrderRec(root);
  cout<<"\n"<<"PostOrder: "<<endl;
  postOrderRec(root);

}
