#include <iostream>
using namespace std ;



class node {
public:
	int data;
	node* next = NULL ;

	node(int v) {
		data = v ;
	}
	node(void) {
		data = -1 ;
	}
};



class maxPriorityQueue {
	node  *head ;

public:
	maxPriorityQueue(node *ptr) {
		head = ptr ;
	}
	maxPriorityQueue(void) {
		head = NULL;
	}

	bool empty();
	int size();
	int top();
	void pop();
	void push(int d);

};



int main() {

	int ans ;

	maxPriorityQueue mpq ;

	do
	{
		cout << "\n\n1. empty \n2. size \n3.top \n4. pop \n5.push\n\n";
		cin >> ans;

		int v ;

		switch (ans) {
		case 1 :
			cout << mpq.empty();
			break;
		case 2 :
			cout << mpq.size();
			break;
		case 3 :
			cout << mpq.top();
			break;
		case 4 :
			mpq.pop();
			break;
		case 5 :
			cin >> v ;
			mpq.push(v);

		}





	} while (ans != 0);






	return 0;
}



bool maxPriorityQueue :: empty() {
	if (head == NULL) return true;
	return false;

}



int maxPriorityQueue:: size() {
	node * ptr ;
	ptr = head ;

	int size = 0;

	while (ptr != NULL) {ptr = ptr->next; size++;}

	return size;
}



int maxPriorityQueue :: top() {if (empty())return -1; return head->data;}



void maxPriorityQueue :: pop() {if (head == NULL); else head = head->next; }



void maxPriorityQueue :: push(int d) {


	node* ptr = head ;

	node* p;
	p->data = d ;
	while (1) {
		if (ptr->next != NULL && ptr->next->data > p->data)ptr = ptr->next ;
		else break;
	}

	if (ptr->next != NULL)p->next = ptr->next ;
	ptr->next = p;
}