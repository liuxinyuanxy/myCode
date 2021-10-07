#include <stdio.h>
#include <math.h>
const int MAXNODE = 2097152;
const int MAX = 1000003;
struct NODE{
    int value;        // ����Ӧ�����Ȩֵ
    int left,right;   // ���� [left,right]
}node[MAXNODE];
int father[MAX];     // ÿ����(�����䳤��Ϊ0ʱ����Ӧһ����)��Ӧ�Ľṹ�������±�
void BuildTree(int i,int left,int right){ // Ϊ����[left,right]����һ����iΪ���ȵ��߶�����iΪ�����±꣬�ҳ���������
    node[i].left = left;    // д���i������е� ������
    node[i].right = right;    // д���i������е� ������
    node[i].value = 0;         // ÿ�������ʼ��Ϊ 0
    if (left == right){    // �����䳤��Ϊ 0 ʱ�������ݹ�
        father[left] = i; // ��֪��ĳ�����Ӧ����ţ�Ϊ�˸��µ�ʱ���������һֱ����
        return;
    }
    // �ý���� ���ӵķ��� ���������߶������߶εĻ����Ƕ���˼�룬���д�����ֲ��ҵĻ���������׽���
    // ���ｫ ����[left,right] һ��Ϊ����
    BuildTree(i<<1, left, (int)floor( (right+left) / 2.0));
    // �ý���� �Һ��ӵķ��� ���������߶���
    BuildTree((i<<1) + 1, (int)floor( (right+left) / 2.0) + 1, right);
}
void UpdataTree(int ri){ // �������ϸ��£�ע������㱾���Ѿ��ں�������¹��ˣ�

    if (ri == 1)return;    // �����Ѿ��ҵ������ȣ������߶��������Ƚ�� ��Ӧ���±�Ϊ1��
    int fi = ri / 2;         // ri �ĸ����
    int a = node[fi<<1].value; // �ø������������ӽ�㣨��
    int b = node[(fi<<1)+1].value; // ��
    node[fi].value = (a > b)?(a):(b);    // �����������㣨���������ӽ����������ģ�
    UpdataTree(ri/2);        // �ݹ���£��ɸ����������
}
int Max = -1<<20;
void Query(int i,int l,int r){ // iΪ�������ţ���Ӧ�����������Χ���Ǹ����䣬Ҳ�ǵ�һ��ͼ��˵����䣬һ���ʼ�� 1 ����
    if (node[i].left == l && node[i].right == r){ // �ҵ���һ����ȫ�غϵ�����
        Max = (Max < node[i].value)?node[i].value:(Max);
        return ;
    }
    i = i << 1; // get the left child of the tree node
    if (l <= node[i].right){ // ���������漰
        if (r <= node[i].right) // ȫ�����������䣬���ѯ������̬����
            Query(i, l, r);
        else // ������������䣬���ѯ�����֣���˵㲻�䣬�Ҷ˵��Ϊ���ӵ�������˵�
            Query(i, l, node[i].right);
    }
    i += 1; // right child of the tree
    if (r >= node[i].left){ // ���������漰
        if (l >= node[i].left) // ȫ�����������䣬���ѯ������̬����
            Query(i, l, r);
        else // ������������䣬���ѯ�����֣�����ͬ��
            Query(i, node[i].left, r);
    }
}
