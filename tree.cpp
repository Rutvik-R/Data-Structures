#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node {
public:
	int data ;
	// node* parant = NULL ;
	node* left = NULL ;
	node* right = NULL;
	node(int d) {
		data = d ;
		left = NULL ;
		right = NULL;
	}
};


void print_LRr(node* a) {
	if (a->left != NULL)print_LRr(a->left);
	if (a->right != NULL)print_LRr(a->right);

	cout << a->data << " " ;

}


void print_LrR(node* a) {
	if (a->left != NULL)print_LrR(a->left);
	cout << a->data << " " ;
	if (a->right != NULL)print_LrR(a->right);


}

void printvvi(vector<vector<int>> pl) {
	for (int i = 0; i < pl.size(); ++i)
	{
		for (int j = 0; j < pl[i].size(); ++j)
		{
			cout << pl[i][j] << " ";
		}
		cout << endl;
	}
}



void levelVisePrint(node* a) {
	vector<vector<int>> lv ;
	queue< node* > q ;

	q.push(a);

	while (!q.empty()) {
		int size = q.size() ;
		vector<int> level ;

		for (int i = 0; i < size; ++i)
		{
			node* d = q.front() ;
			q.pop() ;

			if (d->left != NULL) q.push(d->left) ;
			if (d->right != NULL) q.push(d->right) ;

			level.push_back(d->data);
		}

		lv.push_back(level) ;
	}


	printvvi(lv);

}




int main() {
	node root(1) ;

	root.left = new node(5) ;
	root.right = new node(6) ;
	// cout << root.left->data ;

	root.left->left = new node(7) ;
	root.left->right = new node(8) ;

	root.right->left = new node(9) ;
	root.right->right = new node(10);

	(root.left)->left->left = new node(11) ;
	(root.left)->left->right = new node(12) ;

	(root.left)->right->left = new node(13);
	(root.left)->right->right = new node(14);

	// print_LRr(&root);
	// cout << "\n";
	// print_LrR(&root);
	levelVisePrint(&root);

	return 0 ;
}