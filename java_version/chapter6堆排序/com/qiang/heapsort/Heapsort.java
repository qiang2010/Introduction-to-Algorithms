package com.qiang.heapsort;

/*
 *  ������Ҫ��ʵ�ֶ�����
 *  ���ݴ����һ��һλ�����С�
 *  code by qiangji 
 */


public class Heapsort {

	private int maxsize;
	private int heapsize;
	private int []heap;	
	public Heapsort(int size,int[]inputs){
		maxsize = heapsize = size;
		heap = inputs;
	}
	
	private int getMaxnum(){
		if(heapsize != 0) return heap[0];
		return -1;
	}
	// ��ȡ���ڵ㡢����ӡ����Ҷ��ӵ�����
	private int getParent(int i){
		if (i==0) return -1;
		return (i+1)/2 -1;
	}
	private int getLeft(int i){
		return (i+1)*2-1;
	}
	private int getRight(int i){
		return (i+1)*2;
	}
	private int getLastInner(){
		if (heapsize==0) return -1;
		return heapsize/2 -1;
	}
	private void exchange(int i,int j){
		int temp = heap[i];
		heap[i] = heap[j];
		heap[j] = temp;
//		return true;
	}
	// �����ѣ��ݹ�
	private int modifyRecursion( int i){
		if(i<0 || i >= heapsize ) return -1;
		int left = getLeft(i);
		int right = getRight(i);
		int maxpos = i;
		if(left < heapsize && heap[left] > heap[maxpos] ) maxpos = left;
		if(right< heapsize && heap[right] > heap[maxpos]) maxpos = right;
		if(maxpos == i) return 0;
		exchange(i, maxpos);
		modifyRecursion(maxpos);
		return 0;
	}
	// �ǵݹ����
	private int modify(int i){
		int pos = i;
		int left , right ;
		do{
		  left = getLeft(pos);
		  right = getRight(pos);
		  int maxpos = pos;
		   if(left < heapsize && heap[left] > heap[maxpos] ) maxpos = left;
		  if(right< heapsize && heap[right] > heap[maxpos]) maxpos = right;
		  if(maxpos == pos) return 0;
		  exchange(pos, maxpos);
	 	  pos = maxpos;
		}while(true);
	}
	private void buildHeap(){
		int lastIn = getLastInner();
		for(int i = lastIn; i>=0; i--){
//			modifyRecursion(i);	// �ݹ������ʽ
			modify(i);  		// �ǵݹ�
		}
	}
	public int heapsort(){
		buildHeap();
		for(int i=1;i<maxsize;i++){
			exchange(0, heapsize-1);
			heapsize--;
			modifyRecursion(0);
		}
		return 0;
	}
	public int printHeap(){
		for(int j = 0 ; j <maxsize; j++){
			System.out.println(heap[j]+"  ");
		}
		return 0;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a[]={1,2,34,56,78,122};
		Heapsort sort = new Heapsort(a.length,a);
		sort.heapsort();
		sort.printHeap();
	}

	
	

}
