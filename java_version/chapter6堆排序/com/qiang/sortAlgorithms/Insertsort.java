package com.qiang.sortAlgorithms;

// 插入排序就像 打扑克，你获取一张牌以后，要把新的牌插入到你手中已经排好序的牌中
public class Insertsort {
	
	public static  void insertsort(int []list){
		
		int size = list.length;
		int temp,j,temptar;
		for( int i=1;i<size;i++){
			temp = list[i];
			j = i;
			while(j>=1 && list[j-1] < list [j]){
				temptar = list[j];
				list[j] = list[j-1];
				list[j-1] = temptar;
				j--;
			}
			list[j] = temp;
		}
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a[] = {23,34,112,1111,4455,89,0,121};
		Insertsort.insertsort(a);
		for(int i = 0 ; i<a.length;i++)
		System.out.println(a[i]);
	}

}
