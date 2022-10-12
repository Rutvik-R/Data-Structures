#include <iostream>
using namespace std;


/*
Following are the standard Linked List Operations -
1. Traversing a linked list.
2. Append a new node (to the end) of a list
3. Prepend a new node (to the beginning) of the list
4. Inserting a new node to a specific position on the list
5. Deleting a node from the list
*/

class node {
public :
	int key;
	int data;
	node* next;
	node* priv;

	node(int k , int vel) {
		data = vel ;
		key = k;
		next = NULL;
		priv = NULL;
	}
};

class doublyLinkList {
private:
public:
	node* head ;

	doublyLinkList(node* n) {
		head = n ;
		cout << "doublyLinkList created successfully" << endl;
	}

	doublyLinkList() {
		head = NULL;
		cout << "doublyLinkList created successfully" << endl;
	}

	node* nodeExist(int k);
	void appendNode(node* n);
	void preendNode(node* n);
	void insertNodeNextTo(int k , node* n);
	void deletNode(int k);
	void display();


};


node* doublyLinkList:: nodeExist(int k) {
	node* ptr = head ;
	while (ptr != NULL) {
		if (ptr->key == k) {
			break;
		}
		ptr = ptr->next ;
	}
	return ptr ;
}


void doublyLinkList:: appendNode(node* n) {
	if (nodeExist(n->key) != NULL ) 	cout << "appendNode Unsuccessfully" << endl;
	else if (head == NULL) {
		head = n;
		cout << "appendNode successfully" << endl;
	}
	else {
		node* ptr = head ;
		while (ptr->next != NULL)ptr = ptr->next ;
		n->priv = ptr ;
		ptr->next = n ;
		cout << "appendNode successfully" << endl;

	}
	display();
}


void doublyLinkList:: preendNode(node* n) {
	if (nodeExist(n->key) != NULL) 	cout << "preendNode Unsuccessfully" << endl;
	else if (head == NULL) {
		head = n ;
		cout << "preendNode successfully" << endl;
	}
	else {
		// node* dumi;
		head->priv = n ;
		n->next = head ;
		head = n ;
		cout << "preendNode successfully" << endl;
	}
	display();
}

void doublyLinkList:: display() {
	node* ptr;
	ptr = head ;
	while (ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}


void doublyLinkList:: insertNodeNextTo(int k , node* n) {
	if (nodeExist(k) == NULL || nodeExist(n->key) != NULL) cout << "insertNodeNextTo Unsuccessfully" << endl;

	else {
		node* ptr = head ;
		while (ptr->key != k ) ptr = ptr->next ;
		n->next = ptr ;
		n->priv = ptr->priv ;
		ptr->priv->next = n ;
		ptr->priv = n ;
		cout << "insertNodeNextTo successfully" << endl;

	}
	display();
}


void doublyLinkList:: deletNode(int k) {
	if (nodeExist(k) == NULL) 	cout << "deletNode Unsuccessfully" << endl;
	else {
		node* ptr = nodeExist(k);
		if (ptr->next != NULL) {
			ptr->next->priv = ptr->priv ;
		}

		if (ptr->priv != NULL) {
			ptr->priv->next = ptr->next ;
		}
		else {
			head = ptr->next;
		}
		cout << "deletNode successfully" << endl;
	}
	display();
}








int main() {

	doublyLinkList d ;
	for (int i = 0; i < 10; ++i)
	{
		node* n1 = new node(i + 1 , i + 1) ;
		d.appendNode(n1);
	}
	cout << d.head->next->next->data;
	return 0;
}