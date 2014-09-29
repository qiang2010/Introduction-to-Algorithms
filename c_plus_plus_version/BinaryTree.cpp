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
// ++ Ϊ�˷����������ʹ�ö�̬���䣬����ʹ�þ�̬�ڴ����
// ++ �ٶ����еĽڵ���ĿС�� MAX_NUM
node Tree[MAX_NUM];
int  loc = 0;
// *****�����������ĺ�������*****
/*��������������һ
 * �ǵݹ�
 *���룺�ȸ����У�����#��ʾ
 *���أ�������ָ��
 * eg.   AB##CD##E##  #�����
 */
string pre ;    //++ pre ������ڹ������������ȸ����У�����#��ʾNULL
size_t preOrderLoc = 0; // ++ ����ָʾpre�е��ַ�
node * buildPreOrder(size_t a);
node* buildBinaryTreeFromPreOrder(){
  cout<<"Please input preorder with # for null"<<endl;
  cin>>pre;
  return buildPreOrder(0);
}
node * buildPreOrder(size_t a){
  // �ݹ�����жϣ���Ϊ # ������null
  if (pre[a] == '#'){  return 0;}

  // �ݹ齨��������
  preOrderLoc++;
  node * left  = buildPreOrder(preOrderLoc);

  // �ݹ齨��������
  preOrderLoc++;
  node * right = buildPreOrder(preOrderLoc);

  // ��̬����һ������
  node *temp = &Tree[loc];
  loc++;
  // cout<<"loc:"<<loc<<endl;
  (*temp).data  = pre[a];
  (*temp).left = left;
  (*temp).right = right;
  return temp;
}

/*����������������
 * ���룺�ȸ����� �� �и�����
 * ���أ� ���ڵ��ָ��
*/
string inOrder; // ++ �и�����������
node * buildRecur(size_t preLoc1,size_t preLoc2,size_t inLoc1,size_t inLoc2);
node * buildBinaryTreeFromPreAndInOrder(){
  cout<< "Please input preOrder:"<<endl;
  cin>>pre;
  cout<< "Please input inOrder:"<<endl;
  cin>>inOrder;
  return buildRecur(0, pre.size()-1, 0 , inOrder.size()-1);
}
// �ݹ�ͨ���ȸ� �� �и� ����������
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

// *****�����������ĺ���*****
// *****�ݹ��������*****
void preOrderRec(node *root){
  if(root == 0 ) return;
  cout<<(*root).data<<" ";
  preOrderRec((*root).left);
  preOrderRec((*root).right);
}
// ***** �ݹ�������� *****
void inOrderRec(node * root){
  if ( root == 0 ) return ;
  inOrderRec((*root).left);
  cout<< (*root).data<<" ";
  inOrderRec((*root).right);
}
// ***** �ݹ�������*****
void postOrderRec(node * root){
  if ( root == 0 ) return ;
  postOrderRec((*root).left);
  postOrderRec((*root).right);
  cout<< (*root).data<<" ";
}
// ***** �ǵݹ����*****
// ***** �ǵݹ��ȸ�����*****
void preOrderNon(node * root){

}
// ***** �ǵݹ��и�����*****
void inOrderNon(node * root){

}
// ***** �ǵݹ��ȸ�����*****
void postOrderNon(node * root){

}
/* ***** ��α������������*****
 * ��Ҫʹ��һ�����У� ��������ڱ����Ĺ��̼�¼ÿ���ڵ�Ĳ���أ�
 *  �������һ�ַ�����ʹ������������
 *      ++ һ����¼��ǰ��Ľڵ���level��һ�����ڼ�¼��һ��Ľڵ���ĿfrontLevel
 *      ++ ��ʼ��� level = 0, frontLeve = 1;
 *      ++ ÿ�γ����У�frontLeve���Լ���ÿ�������������Ԫ�ص�ʱ��level����������ο�����
 *  ͬʱ����ʹ��һ����������¼��Σ������������������õ�ʱ�� ��α�������
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
