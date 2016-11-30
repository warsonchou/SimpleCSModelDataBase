/*************************************************************************
 > File Name: bTree.h
 > Desc: 实现基本的数据库的b-tree
 > Author: guocheng
 > Mail: 1129134022@qq.com
 > Created Time: 2016-10-29
 from http://blog.csdn.net/hguisu/article/details/7786014
 ***********************************************************************/

#ifndef _BTREE_H_
#define _BTREE_H_

typedef int KeyType ;  
#define m 5                 /*B 树的阶，暂设为5*/  
typedef struct Node {  
    int keynum;             /* 结点中关键码的个数，即结点的大小*/  
    struct Node *parent;    /*指向双亲结点*/   
    KeyType key[m+1];       /*关键码向量，0 号单元未用*/   
    struct Node *ptr[m+1];  /*子树指针向量*/   
    // Record *recptr[m+1];    /*记录指针向量*/  
} NodeType;                  /*B 树结点类型*/  
  
typedef struct {  
    NodeType *pt;           /*指向找到的结点*/  
    int i;                  /*在结点中的关键码序号，结点序号区间[1…m]*/  
    int tag;                /* 1:查找成功，0:查找失败*/  
} Result; 

namespace BTREE_DATABASE {
	class bTree {
	public:
		/*
		 * @desc, 实例化bTree
		 *
		 * @param rank 为bTree的阶
		*/
		bTree(int rank);

		/*
		 * @desc , 查询某个数是否在数据库中
		 *
		 * @param target 为要查找的数字
		 *
		 * @return 存在的时候返回true，否则返回false
		*/
		bool search(int target);

		/*
		 * @desc , 将某个数插入数据库中
		 *
		 * @param target 为要插入的数字
		 *
		 * @return void
		*/
		void insert(int target);

		/*
		 * @desc , 查询数据库中第seq大的数
		 *
		 * @param seq 为第seq大的数
		 *
		 * @return 返回第seq大的数字，如果数字的个数小于seq个，那么照样返回最大的数；
		 * 如果存在多对数字相等，那么就返回排好序后的数字在序列当中第seq个数字
		*/
		int getSeqBigger(int seq);

		/*
		 * @desc , 删除数据库中某个数
		 *
		 * @param target 为要删除的数字
		 *
		 * @return 删除成功的时候返回true，否则返回false，如果存在相等的数，那么全部删除掉，
		*/
		bool bDelete(int target);

	private:
		NodeType root;
		int rank;
	};
}
#endif