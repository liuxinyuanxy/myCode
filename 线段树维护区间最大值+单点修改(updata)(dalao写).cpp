#include <stdio.h>
#include <math.h>
const int MAXNODE = 2097152;
const int MAX = 1000003;
struct NODE{
    int value;        // 结点对应区间的权值
    int left,right;   // 区间 [left,right]
}node[MAXNODE];
int father[MAX];     // 每个点(当区间长度为0时，对应一个点)对应的结构体数组下标
void BuildTree(int i,int left,int right){ // 为区间[left,right]建立一个以i为祖先的线段树，i为数组下标，我称作结点序号
    node[i].left = left;    // 写入第i个结点中的 左区间
    node[i].right = right;    // 写入第i个结点中的 右区间
    node[i].value = 0;         // 每个区间初始化为 0
    if (left == right){    // 当区间长度为 0 时，结束递归
        father[left] = i; // 能知道某个点对应的序号，为了更新的时候从下往上一直到顶
        return;
    }
    // 该结点往 左孩子的方向 继续建立线段树，线段的划分是二分思想，如果写过二分查找的话这里很容易接受
    // 这里将 区间[left,right] 一分为二了
    BuildTree(i<<1, left, (int)floor( (right+left) / 2.0));
    // 该结点往 右孩子的方向 继续建立线段树
    BuildTree((i<<1) + 1, (int)floor( (right+left) / 2.0) + 1, right);
}
void UpdataTree(int ri){ // 从下往上更新（注：这个点本身已经在函数外更新过了）

    if (ri == 1)return;    // 向上已经找到了祖先（整个线段树的祖先结点 对应的下标为1）
    int fi = ri / 2;         // ri 的父结点
    int a = node[fi<<1].value; // 该父结点的两个孩子结点（左）
    int b = node[(fi<<1)+1].value; // 右
    node[fi].value = (a > b)?(a):(b);    // 更新这个父结点（从两个孩子结点中挑个大的）
    UpdataTree(ri/2);        // 递归更新，由父结点往上找
}
int Max = -1<<20;
void Query(int i,int l,int r){ // i为区间的序号（对应的区间是最大范围的那个区间，也是第一个图最顶端的区间，一般初始是 1 啦）
    if (node[i].left == l && node[i].right == r){ // 找到了一个完全重合的区间
        Max = (Max < node[i].value)?node[i].value:(Max);
        return ;
    }
    i = i << 1; // get the left child of the tree node
    if (l <= node[i].right){ // 左区间有涉及
        if (r <= node[i].right) // 全包含于左区间，则查询区间形态不变
            Query(i, l, r);
        else // 半包含于左区间，则查询区间拆分，左端点不变，右端点变为左孩子的右区间端点
            Query(i, l, node[i].right);
    }
    i += 1; // right child of the tree
    if (r >= node[i].left){ // 右区间有涉及
        if (l >= node[i].left) // 全包含于右区间，则查询区间形态不变
            Query(i, l, r);
        else // 半包含于左区间，则查询区间拆分，与上同理
            Query(i, node[i].left, r);
    }
}
