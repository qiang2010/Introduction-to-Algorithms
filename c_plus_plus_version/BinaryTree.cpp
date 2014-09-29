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
  return buildRecur(0, pre.size()-1, 0 , inOrder.size()-1);
}
// 递归通过先根 和 中根 构建二叉树
node * buildRecur(size_t preLoc1,size_t preLoc2,size_t inLoc1,size_t inLoc2){
  //cout<<"pos::"<< preLoc1<<" "<<preLoc2<<" "<<inLoc1<<" "<<inLoc2<<endl;
  if (preLoc1>preLoc2 || inLoc1 > inLoc2 )  return 0;
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
  cout<< (*root).data<<" ";
}
// ***** 非递归遍历*****
// ***** 非递归先根遍历*****
void preOrderNon(node * root){

}
// ***** 非递归中根遍历*****
void inOrderNon(node * root){

}
// ***** 非递归先根遍历*****
void postOrderNon(node * root){

}
/* ***** 层次遍历输出二叉树*****
 * 需要使用一个队列， 但是如何在遍历的过程记录每个节点的层次呢？
 *  这里给出一种方法，使用两个变量：
 *      ++ 一个记录当前层的节点数level，一个用于记录上一层的节点数目frontLevel
 *      ++ 初始情况 level = 0, frontLeve = 1;
 *      ++ 每次出队列，frontLeve就自减，每次往队列中添加元素的时候level自增，具体参考代码
 *  同时可以使用一个变量来记录层次，当上面两个变量重置的时候 层次变量自增
*/
void levelOrderPrint(node * root){
  queue< node* > que;
  que.push(root);
  node * temp;
  int level = 0;
  int frontLevel = 1;
  int levelCount = 0;
  while(!que.empty()){
    temp = que.front();
    que.pop();
    cout<< "level:" << levelCount<<" ";
    cout<< (*temp).data<<" ";
    if((*temp).left  != 0 ){
      que.push((*temp).left);
      frontLevel > 0 ? level++ : 0;
    }
    if((*temp).right != 0 ){
      que.push((*temp).right);
      frontLevel >0?  level++ : 0;
    }
    frontLevel--;
    if(frontLevel<=0){
      frontLevel = level;
      level = 0;
      levelCount++;
      cout<<endl;
    }
  }
}

int main(){
  //preOrderRec(buildBinaryTreeFromPreOrder());
  node * root =  buildBinaryTreeFromPreAndInOrder();
  cout<<"loc:"<<loc<<endl;
  cout<<"PreOrder: "<<endl;
  preOrderRec(root);
  cout<<"\n"<<"InOrder: "<<endl;
  inOrderRec(root);
  cout<<"\n"<<"PostOrder: "<<endl;
  postOrderRec(root);
  cout<<"\n"<<"levelOrder:"<<endl;
  levelOrderPrint(root);

}
