//check if a bst is correct. return incorrect node.

#include <iostream>

using namespace std;

struct node {
	int val;
	node *left;
	node *right;

	node(int val){
		this->val = val;
		left = NULL;
		right = NULL;
	}
};

//keep track of min/max values in left/right subtree and compare with self.
//complex solution

bool isBST(node *n, int* max, int* min){

	int rmin,rmax,lmin,lmax;

	if(!n)
		return true;

	if(!n->left)
		*min = n->val;
	else{
		if(!isBST(n->left, &lmax, &lmin)){
			*min = lmax;
			return false;
		}
		if(lmax > n->val){
			*min = lmax;
			return false;
		}
		else
			*min = lmax;
	}	
	if(!n->right)
		*max = n->val;
	else{
		if(!isBST(n->right, &rmax, &rmin)){
			*max = rmin;
			return false;
		}
		if(rmin < n->val){
			*max = rmin;
			return false;
		}
		else
			*max = rmin;
	}	
	
	return true;
}
		
//do inorder traversal and compare values
bool isBST2(node *n, node** prev){

	if(!n)
		return true;

	if(!isBST2(n->left, prev))
		return false;

	if(*prev && (*prev)->val > n->val)
		return false;
	*prev = n;

	if(!isBST2(n->right, prev))
		return false;

	return true;
}
		
	
	

int main(){

	node *root = new node(20);
	root->left = new node(10);
	root->left->left = new node(16);
	root->left->right = new node(15);
	root->right = new node(30);
	root->right->left = new node(21);
	root->right->right = new node(35);

	int max, min;
	// printing below line will print garbage min max since params to a function are evaluated in any order. 
	//cout << isBST(root, &max, &min) << " "  << max << " " << min  << endl;
	cout << isBST(root, &max, &min) << endl;
	cout  << max << " " << min  << endl;

	node *prev=NULL;
	cout << isBST2(root, &prev) << endl;
	cout << "incorrect node is " << prev->val << endl;
}
