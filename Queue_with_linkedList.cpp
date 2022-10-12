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

class queue {
	node* last = NULL;
	node* first = NULL;
public:

	queue() {
		first->next = last ;
	}

	queue(node* n) {
		first->next = last ;
		last = n ;

	}
	bool isEmpty();
	void pushBack(node* n);
	void pushStart(node* n);
	void popBsck();
	void popStart();
	void display();

};


bool queue:: isEmpty() {
	if (first == NULL && last == NULL) return true ;
	return false ;
}


void queue:: pushBack(node* n) {
	if (lst == NULL) last = n ;
	else {
		last->next = n;
		last =  n ;
	}

}

void queue:: pushStart(node* n) {
	if (first == NULL) first = n ;
	first->next = n ;
	first = n ;
}

void queue:: display() {
	node* ptr = last ;
	while (ptr != first) {
		cout << ptr->data << " ";
	}
	cout << ptr->data << endl;
}

int main() {

	node n1(1), n2(2), n3(3) , n4(4);

	queue q(&n1);
	q.display();
	q.pushBack(&n2);
	q.pushStart(&n3);

	q.display();

	return 0;
}