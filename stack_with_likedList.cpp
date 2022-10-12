#include <iostream>
using namespace std;


class node {

public:
	int data ;
	node* next ;

	node() {
		data = 0;
		next = NULL;
	}

	node(int d) {
		data = d ;
		next = NULL ;
	}

};

class stack {
public:
	node* head ;


	stack() {
		head = NULL ;
		cout << "stack created successfully" << endl;
	}
	stack(node* n) {
		head = n ;
		cout << "stack created successfully" << endl;
	}

	void push(node* n);
	void pop();
	bool isEmpty();
	void display();
	int peek();
	int count();

};

bool stack:: isEmpty() {
	if (head == NULL) return true ;

	return false ;
}


void stack:: push(node* n) {

	n->next = head ;
	head = n ;


	cout << "push successful" << endl;
}

void stack:: pop() {
	if (isEmpty()) cout << "stack is Empty" << endl;
	else {
		head = head->next ;
		cout << "pop successful" << endl;
	}
}

void stack::display() {
	node * ptr = head ;
	while (ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next ;
	}
	cout << endl;
}

int stack:: peek() {
	return head->data ;
}

int stack:: count() {
	int c = 0 ;
	node* ptr = head ;
	while (head != NULL) {c++; head = head->next;}
	return c ;
}


int main() {
	node n1(1);
	node n2(2) , n3(3) , n4(4) ;

	stack s(&n1);
	s.push(&n4);
	s.push(&n2);
	s.push(&n3);

	s.display();

	s.pop();


	s.display();

	cout << s.peek() << endl << s.count();

	return 0;
}