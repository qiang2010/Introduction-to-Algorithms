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
    string pre ;
    int preOrderLoc = 0;
node * buildPreOrder(int a);
node* buildBinaryTreeFromPreOrder(){
    cout<<"Please input preorder with # for null"<<endl;
    cin>>pre;
    return buildPreOrder(0);
}
node * buildPreOrder(int a){
    // �ݹ�����жϣ���Ϊ # ������null
    if (pre[a] == '#'){  return 0;}

    // �ݹ齨��������
    preOrderLoc++;
    node * left  = buildPreOrder(preOrderLoc);
    // �ݹ齨��������
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

  /*����������������
    * ���룺�ȸ����� �� �и�����
    * ���أ� ���ڵ��ָ��
    */
node * buildBinaryTreeFromPreAndInOrder(){


}
// *****�����������ĺ���*****
// *****�ݹ��������*****
void preOrderRec(node *root){
    if(root == 0 ) return;
    cout<<(*root).data<<" ";
    preOrderRec((*root).left);
    preOrderRec((*root).right);
}

// ***** ��α������������*****
void levelOrderPrint(node * root){

}

int main(){
    preOrderRec(buildBinaryTreeFromPreOrder());


}
