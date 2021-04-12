#include <iostream>
// 이진트리
using namespace std;

int number = 15;
// 사용자 정의 타입
typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChlid;
};

void preorder(treePointer str) {
	if (str) {
		cout << str->data << ' ';
		preorder(str->leftChild);
		preorder(str->rightChlid);
	}
}

void inorder(treePointer str) {
	if (str) {
		inorder(str->leftChild);
		cout << str->data << ' ';
		inorder(str->rightChlid);
	}
}

void postorder(treePointer str) {
	if (str) {
		postorder(str->leftChild);
		postorder(str->rightChlid);
		cout << str->data << ' ';
	}
}

int main(void) {
	node nodes[16];
	for (int i = 1; i <= number; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChlid = NULL;
	}
	for (int i = 1; i <= number; i++) {
		if (i % 2 == 0) {
			nodes[i / 2].leftChild = &nodes[i];
		}
		else {
			nodes[i / 2].rightChlid = &nodes[i];
		}
	}

	preorder(&nodes[1]);
	cout << endl;
	inorder(&nodes[1]);
	cout << endl;
	postorder(&nodes[1]);
	cout << endl;

	return 0;
}