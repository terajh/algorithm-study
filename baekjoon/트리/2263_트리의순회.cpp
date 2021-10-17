#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int inorder[100001];
int postorder[100001];
int index[100001];

void getPreorder(int in_l, int in_r, int po_l, int po_r) {
	
	if(in_l > in_r || po_l > po_r) return;
	int rootIndex = index[postorder[po_r]];
	int leftSize = rootIndex - in_l;
	int rightSize = in_r - rootIndex;
	cout << inorder[rootIndex] << ' ';
	
	// left
	getPreorder(in_l, rootIndex - 1, po_l, po_l + leftSize - 1);
	// right
	getPreorder(rootIndex + 1, in_r, po_l + leftSize, po_r - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	
	// inorder
	for(int i=1 ; i<=n ; i++) {
		cin >> inorder[i];
		index[inorder[i]] = i;
	}
	// postorder
	for(int i=1 ; i<=n ; i++) {
		cin >> postorder[i];
	}
	getPreorder(1, n, 1, n);

}