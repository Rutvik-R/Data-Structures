#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *next ;

	node(int val)
	{
		this->data = val;
		this->next = NULL;
	}
	node()
	{
		this->data = 0;
		this->next = NULL;
	}
};

class circularLinkList
{
private:
	node *head;

public:
	circularLinkList(node *n)
	{
		head = n;
		head->next = head;
	}
	circularLinkList()
	{
		head = NULL;
	}

	void insert(int val);
	void show();
	bool isEmpty();
	void appendNodeNextTo(int check, int val);
};

int main()
{
	circularLinkList L;
	
	int ans , check , val;
	do
	{
		cout<<"\n\n1. insert() \n2. show()\n3. isEmpty() \n4. appendNextTo()\n0. Exit\n\nEnter your ans :      ";
		cin>>ans;
		switch (ans)
		{
		case 1:
			cout<<"Enter val :   ";
			cin>>val;
			L.insert(val);
			break;
		
		case 2:
			L.show();
			break;

		case 3:
			cout<<((L.isEmpty())?"True":"False");
			cout<<endl;
			break;	
		
		case 4:
			cout<<"Enter check  and val :   ";
			cin>>check>>val;
			L.appendNodeNextTo(check , val); 
			break;

		default:
			break;
		}

	} while (ans);
	

	return 0;
}

void circularLinkList ::insert(int val)
{
	node *dumi = new node(val);
	if(isEmpty()){
		head = dumi;
		head->next = dumi ;
		cout << "Insert Successful" << endl;
		return;
	}

	node *ptr = head;
	while (ptr->next != head)
		ptr = ptr->next;

	dumi->next = ptr->next;
	ptr->next = dumi;

	cout << "Insert Successful" << endl;
}

void circularLinkList :: show(){
	if(isEmpty()){
		cout<<"List is Empty "<<endl;
		return;
	}
	node * ptr = head ;
	do {
		cout<<ptr->data<<" ";
		ptr= ptr->next ;
	}while (ptr != head);
	
	cout<<endl;
}

bool circularLinkList:: isEmpty(){
	if(head == NULL) return 1;
	return 0;
}

void circularLinkList:: appendNodeNextTo(int check , int val){
	node * ptr = head ;

	while(ptr->next != head && ptr->data != check) ptr = ptr->next ;

	if(ptr->data != check) {
		cout << "appendNodeNext to "<< check<<" Unsuccessful" << endl;
		return ;
	}

	node * dumi = new node(val);

	dumi->next = ptr->next; 
	ptr->next = dumi;
	
	cout << "appendNodeNextTo "<<check<<" Successful" << endl;

}