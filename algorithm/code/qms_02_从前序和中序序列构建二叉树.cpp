#include<iostream>
#include<string>
#include<cmath>
using namespace std;

string in, pre;
struct Node {
	char c = 0;
	Node* left = nullptr, * right = nullptr;
};

//���������ҵ�ǰ��������������λ��
int findLeftTree(int ib, int ie) {
	int pos = -1;
	for (int i = ib; i <= ie; ++i) pos = max(pos, (int)pre.find(in.at(i)));
	return pos;
}

//����һ����������Ӧ��ǰ���뷶Χ [pb, pe], �����뷶Χ[ib, ie]
Node* buildTree(int pb, int pe, int ib, int ie) {
	if (pb > pe || ib > ie)return nullptr;
	Node* node = new Node;
	node->c = pre.at(pb);//��ǰ���ҵ������ĸ�
	if (pb == pe || ib == ie) return node;//���ֻ��һ������ֱ�ӷ���
	int im = in.find(pre.at(pb));//�������ҵ������ĸ�
	if (im == ib) node->right = buildTree(pb + 1, pe, ib + 1, ie);//��������
	else if (im == ie)node->left = buildTree(pb + 1, pe, ib, ie - 1);//��������
	else {//��������Ҳ��������
		int leftTree = findLeftTree(ib, im - 1);
		node->left = buildTree(pb + 1, leftTree, ib, im - 1);
		node->right = buildTree(leftTree + 1, pe, im + 1, ie);
	}
	return node;
}

void postOrder(Node* n) {
	if (!n)return;
	postOrder(n->left);
	postOrder(n->right);
	cout << n->c;
}

int main() {
	pre = "ABDEGHCFIJ";
	in = "DBGEHACIFJ";
	Node* root = buildTree(0, pre.size() - 1, 0, in.size() - 1);
	postOrder(root);
	return 0;
}