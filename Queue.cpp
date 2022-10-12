#include <iostream>
using namespace std;

/*
Circuler
Following are the standard operations of Queue DS -
1. EnqueueUp
2. EnqueueDown
3. DequeueUp
4. DequeueDown
5. isFull
6. isEmpty
7. count
8. display

*/



class queue {
private :
	int top ;
	int down ;
	int size = 10 ;
	int arr[10];

public :
	queue() {
		top = -1 ;
		down = -1 ;
	}

	bool isFull() {
		if (top - down == size - 1) return true ;
		return false ;
	}

	bool isEmpty() {
		if ((down == -1 && top == -1)) return true ;
		return false ;
	}

	int count() {
		if ( isEmpty() ) return 0 ;
		return (top - down + 1) ;
	}

	void EnqueueUp(int vel) {
		if (isFull()) {
			cout << "Queue is Full" << endl;
		}
		else if (down == -1 && top == -1) {
			top++;
			down++;
			arr[top] = vel;
		}
		else {
			top++;
			arr[top % size] = vel;
		}
	}

	void EnqueueDown(int vel) {
		if (isFull()) {
			cout << "Queue is Full" << endl;
		}
		else if (down == -1 && top == -1) {
			top++;
			down++;
			arr[top] = vel;
		}
		else {
			down--;
			if (down >= 0)arr[down] = vel;
			else {
				arr[size + down % size] = vel;
			}
		}
	}
	void dequeueUp() {
		if (isEmpty()) cout << "queue is alrady empty" << endl;
		else {
			top--;
			if (top < down) {
				top = -1;
				down = -1 ;
			}
		}
	}

	void dequeueDown() {
		if (isEmpty()) {
			cout << "queue is Empty" << endl;
		}
		else {
			down++;
			if (down > top) {
				top = -1;
				down = -1 ;
			}
		}
	}

	void display() {
		if (isEmpty()) {
			cout << "queue is Empty" << endl;
		}
		else {
			for (int i = down ; i < top + 1; ++i)
			{
				if (i >= 0)cout << arr[i % size] << " ";
				else cout << arr[size + i % size] << " ";
			}
			cout << endl;
		}
	}

};



int main() {

	queue a ;
	int ans , vel;
	do
	{
		cout << "1 EnqueueUp" << endl << "2. EnqueueDown" << endl << "3. DequeueUp" << endl << "4. Dequeuedown" << endl << "5. isFull" << endl << "6. isEmpty" << endl << "7. count" << endl << "8. display" << endl  << endl;
		cin >> ans;
		switch (ans) {
		case 1:
			cout << "Enter velue :  ";
			cin >> vel;
			a.EnqueueUp(vel);
			break;
		case 2 :
			a.dequeueUp();
			break ;
		case 3 :
			a.dequeueDown();
			break;
		case 4:
			cout << a.isFull() << endl;
			break;
		case 5:
			cout << a.isEmpty() << endl;
			break;
		case 6:
			cout << a.count() << endl;
			break;
		case 7:
			a.display();
			break;
		case 8 :
			cout << "Enter velue :  ";
			cin >> vel;
			a.EnqueueDown(vel);
			break;
		}
		cout << endl << endl;
	} while (ans != 0);

	int dumi;
	cin >> dumi;


	return 0 ;
}
