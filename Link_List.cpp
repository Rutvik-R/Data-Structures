#include <iostream>
using namespace std;


class node {

public :
	int key;
	int data;
	node* next ;

	node() {
		this->key = 0;
		this->data = 0;
		next = NULL ;
	}

	node(int k , int d ) {
		key = k;
		data = d ;
		next = NULL;
	}
};


class singlyLinkedList {

public :
	node *head;
	singlyLinkedList() {
		head = NULL;
		cout << "singlyLinkedList created Successfully" << endl;
	}
	singlyLinkedList(node *n) {
		head = n;
		cout << "singlyLinkedList created Successfully" << endl;
	}

	node* nodeExists(int k) ;
	void appendNode(node* n) ;
	void appendNodeStart(node* n );
	void insetNodeNextTo(int k , node* n);
	void deletNode(int key);
	void deletNode(node* n);
	void updateNode(int k , int up);
	void display();
	void reverce();


};

node* singlyLinkedList:: nodeExists(int k) {
	node* ptr = head ;
	node* exist = NULL ;

	while (ptr != NULL) {
		if (ptr->key == k) {
			exist = ptr ;
			break ;
		}
		ptr = ptr->next ;
	}

	return exist ;
}

void singlyLinkedList:: appendNode(node* n) {

	if (head == NULL) {
		head = n ;
		cout << "appendNode Successful" << endl;
	}
	else if (nodeExists(n->key) != NULL) cout << "appendNode Unsuccessful " << endl;
	else {
		node* ptr = head ;
		while (ptr->next != NULL) {
			ptr = ptr->next ;
		}
		ptr-> next = n ;
		cout << "appendNode Successful" << endl;

	}
}

void singlyLinkedList:: display() {
	node* ptr =  head ;
	if (head == NULL) cout << "NULL";
	while (ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next ;
	}
	cout << endl;
}

void singlyLinkedList:: appendNodeStart(node* n) {
	if (head == NULL) { head = n ; cout << "appendNodeStart Successful" << endl;}
	else if (nodeExists(n->key) != NULL) cout << "appendNode Unsuccessful " << endl;
	else {
		node* dumi = head ;
		head = n ;
		n->next = dumi;
		cout << "appendNodeStart Successful" << endl;
	}
}

void singlyLinkedList:: deletNode(int k) {
	if (nodeExists(k) == NULL) cout << "this key node dosen't exist" << endl;
	else {
		node* dumi1 = NULL ;
		node* ptr = head ;
		while (ptr->key != k) {
			dumi1 = ptr ;
			ptr = ptr->next;
		}
		node* dumi = ptr->next ;
		dumi1->next = dumi ;
		cout << "deletNode successful" << endl;
	}
}


void singlyLinkedList:: insetNodeNextTo(int k , node* n) {
	if (nodeExists(k) == NULL) cout << "insetNodeNextTo Unsuccessful" << endl;
	else if (nodeExists(n->key) != NULL) cout << "appendNode Unsuccessful " << endl;
	else {
		node* ptr = head;
		node* dumi;
		while (ptr->key != k && ptr->next != NULL) {
			ptr = ptr->next ;
		}
		dumi = ptr->next ;
		ptr->next = n ;
		n->next = dumi ;
		cout << "insetNodeNextTo successful" << endl;
	}
}

void singlyLinkedList:: updateNode(int k , int up) {
	if (nodeExists(k) == NULL) cout << "updateNode Unsuccessful" << endl;
	else {
		node* ptr = head ;
		while (ptr->key != k) ptr = ptr->next ;
		ptr->data = up;
		cout << "updateNode successful" << endl;
	}
}

void singlyLinkedList:: reverce() {
	node* priv = NULL ;
	node* curr = head ;
	node* dumi ;

	while (curr != NULL) {
		dumi = curr->next ;
		curr->next = priv ;
		priv = curr ;
		curr = dumi ;

	}
	head = priv ;
	cout << "singlyLinkedList reverce successful" << endl;
}




int main() {
	singlyLinkedList h;
	int ans ;
	do
	{
		cout << endl << endl;
		cout << "0 Exit \n1 appendNode node \n2 appendNodeStart \n3 insetNodeNextTo \n4 deletNode \n5 updateNode \n6 reverce \n7 display\n\nEnter your ans :  ";

		cin >> ans;
		node* n = new node();
		int k , d ;
		switch (ans)
		{
		case 0:
			cout << "I hope you enjoy it!" << endl;
			break;
		case 1:
			cout << "Enter Unique key  : ";
			cin >> k;
			cout << "Enter data  : ";
			cin >> d;
			n->key = k;
			n->data = d ;
			h.appendNode(n);
			break;
		case 2:
			cout << "Enter Unique key  : ";
			cin >> k;
			cout << "Enter data  : ";
			cin >> d;
			n->key = k;
			n->data = d ;
			h.appendNodeStart(n);
			break;
		case 3:
			cout << "Enter Unique key  : ";
			cin >> k;
			cout << "Enter data  : ";
			cin >> d;
			n->key = k;
			n->data = d ;
			int k1;
			cout << "Enter key of node where you inset a node :  ";
			cin >> k1;
			h.insetNodeNextTo(k1 , n);
			break;
		case 4:
			cout << "Enter key of that node : ";
			cin >> k;
			h.deletNode(k);
			break;
		case 5:

			cout << "Enter key of that node : ";
			cin >> k;
			cout << "Enter new data : ";
			cin >> d;
			h.updateNode(k , d);
			break;
		case 6:
			h.reverce();
			break;
		case 7:
			h.display();
			break;

		default:
			cout << "Enter valid Ans\n";
			break;
		}


	} while (ans != 0);

	return 0;
}