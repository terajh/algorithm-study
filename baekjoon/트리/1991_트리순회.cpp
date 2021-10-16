#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;


struct Node {
	int val;
	char left, right;
};
Node tree[100];

void preorder(char i) {
	if(i == '.') return;
	printf("%c", i);
	preorder(tree[i].left);
	preorder(tree[i].right);
}
void inorder(char i) {
	if(i == '.') return;
	inorder(tree[i].left);
	printf("%c", i);
	inorder(tree[i].right);
}
void postorder(char i) {
	if(i == '.') return;
	postorder(tree[i].left);
	postorder(tree[i].right);
	printf("%c", i);
}

int main() {
	int n;
	cin >> n;
	for(int i=0 ; i<n ; i++) {
		tree[i].val = i;
	}
	char a, b, c;
	for(int i=0 ; i<n ; i++) {
		cin >> a >> b >> c;
		tree[a].left = b;
		tree[a].right = c;
	}
	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');
	
}