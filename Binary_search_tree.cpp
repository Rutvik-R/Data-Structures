#include <iostream>
#include <queue>
using namespace std;


class TreeNode {
public:

	int value ;
	TreeNode* left ;
	TreeNode* right ;

	TreeNode(int val) {
		value = val ;
		left = NULL ;
		right = NULL ;
	}
	TreeNode(void) {
		left = NULL ;
		right = NULL;
	}


};

class  BinarySearchTree {
	TreeNode* root ;

public:
	BinarySearchTree(void) {
		root = NULL ;
	}
	BinarySearchTree(TreeNode* node) {
		root = node ;
	}


	bool isEmpty();
	void insertNode(TreeNode* new_node);
	TreeNode* isExist(int v);
	int heightOfTree(void);

	void printPreOrder(void);
	void printInOrder(void);
	void printPostOrder(void);

	void printLevelOrder(void);

	void deletNode(int d);


	void preOrderFunction(TreeNode * ptr) {
		cout << ptr->value << " ";
		if (ptr->left != NULL) preOrderFunction(ptr->left);
		if (ptr->right != NULL) preOrderFunction(ptr->right);
	}
	void inOrderFunction(TreeNode * ptr) {
		if (ptr->left != NULL) inOrderFunction(ptr->left);
		cout << ptr->value << " ";
		if (ptr->right != NULL) inOrderFunction(ptr->right);
	}
	void postOrderFunction(TreeNode* ptr) {
		if (ptr->left != NULL) inOrderFunction(ptr->left);
		if (ptr->right != NULL) inOrderFunction(ptr->right);
		cout << ptr->value << " ";
	}
	int height(TreeNode * ptr) {
		if (ptr == NULL) return -1 ;
		int hLeft = height(ptr->left);
		int hRight = height(ptr->right);
		return ((hLeft > hRight) ? hLeft : hRight ) + 1;
	}
};




int main() {

	BinarySearchTree a ;
	int t ;
	do
	{
		cout << "\n\n1. isEmpty \n2. insertNode \n3. heightOfTree  \n4. isExist\n5. printLevelOrde \n6. printPreOrder \n7. printPostOrder \n8. printInOrder \n9. print2D  \n0. Exit\n\n";
		cin >> t ;

		TreeNode* n = new TreeNode();
		int v ;
		switch (t) {
		case 1:
			cout << ((a.isEmpty()) ? "Yes" : "No");
			break;
		case 2 :
			cout << "Enter value of Node :  ";
			cin >> v ;
			n->value = v ;
			a.insertNode(n);
			break;

		case 3:
			cout << a.heightOfTree() << endl;
			break ;
		case  4:
			cout << "Enter a No :  ";
			cin >> v ;
			cout << ((a.isExist(v) != NULL) ? "Yes" : "No");
			break;
		case 5:
			a.printLevelOrder() ;
			break;
		case 6 :
			a.printPreOrder() ;
			break ;
		case 7 :
			a.printPostOrder() ;
			break ;

		case 8 :
			a.printInOrder();
			break;


		}

	} while (t != 0);

	return 0 ;
}





bool BinarySearchTree:: isEmpty() {
	if (root == NULL) return true ;
	return false ;
}

void BinarySearchTree :: insertNode(TreeNode* new_node) {

	if (isEmpty()) {root = new_node ; cout << "insertNode successful" << endl; return ;}

	bool inserted = false ;

	TreeNode* ptr = root ;

	while (!inserted) {
		if (ptr->value < new_node->value) {
			if (ptr->right == NULL) {ptr->right = new_node ; inserted = true ;}
			else ptr =  ptr->right ;
		}
		else if (ptr->value > new_node->value) {
			if (ptr->left == NULL) {ptr->left = new_node ; inserted = true ;}
			else ptr =  ptr->left ;
		}
		else break ;
	}

	if (inserted) cout << "insertNode successful" << endl;
	else cout << "insertNode unsuccessful" << endl;
}

void BinarySearchTree:: printLevelOrder() {
	if (isEmpty()) { cout << "Tree is Empty" << endl; return;}

	TreeNode* ptr = root ;
	queue<TreeNode*> q , level ;
	q.push(root);

	int size = 1 , t = 0;
	while (size) {
		t = 0;
		cout << endl;
		for (int i = 0; i < size ; ++i)
		{
			ptr = q.front() ;
			q.pop() ;
			cout << ptr->value << " ";
			if (ptr->left != NULL) { q.push(ptr->left); t++; }
			if (ptr->right != NULL) { q.push(ptr->right); t++;}
		}
		size = t ;
	}
}

TreeNode* BinarySearchTree::isExist(int v) {
	if (isEmpty()) { return NULL;}

	TreeNode* ptr = root ;

	while (ptr != NULL) {
		if (ptr->value < v) {
			ptr =  ptr->right ;
		}
		else if (ptr->value > v) {
			ptr =  ptr->left ;
		}
		else return ptr ;
	}

	return NULL ;
}

void BinarySearchTree:: printPreOrder(void) {
	preOrderFunction(root);
}

void BinarySearchTree:: printInOrder(void) {
	inOrderFunction(root);
}

void BinarySearchTree:: printPostOrder(void) {
	postOrderFunction(root);
}

int BinarySearchTree:: heightOfTree(void) {
	return height(root) ;
}

void BinarySearchTree:: deletNode(int d) {

}