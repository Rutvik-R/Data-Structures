#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int val;
	int h;
	node * left , *right;
	
	node(int d){
		val = d;
		left = NULL;
		right = NULL;
		h = 1;
	}
	
	int hight(node * N){
		int l = 0,r = 0;
		if(N->left) l = N->left->h;
		if(N->right) r = N->right->h;
		return max(l,r)+1;
	}
	
	node* leftR(node * N){
		node* L = N->left;
		N->left = L->right;
		L->right = N;
		
		N->h = hight(N);
		
		return L;
	}
	
	node* rightR(node * N){
		node* R = N->right;
		N->right = R->left;
		R->left = N;
		
		N->h = hight(N);
		
		return R;
	}
	
	node* insert(node* N , int d){
		node * n = N;
		if(val == d) return N;
		if(val > d) {
			if(!left) left = new node(d);
			left = left->insert(N->left , d);
		}
		if(val < d){
			if(!right) right = new node(d);
			right = right->insert(N->right , d);
		}
		int h_l = 0 , h_r = 0;
		if(left) h_l = left->h;
		if(right) h_r = right->h;
		
		if(abs(h_l - h_r) > 1){
			
			if(h_l > h_r){
				
				int hh_l = 0, hh_r = 0;
				
				if(left->left) hh_l = left->left->h;
				if(left->right) hh_r = left->right->h;
				
				if(hh_l < hh_r) left = rightR(left);
				
				n = leftR(N);
				
			}
			else{
				
				int hh_l = 0 , hh_r = 0;
				
				if(right->left) hh_l = right->left->h;
				if(right->right) hh_r = right->right->h;
				
				if(hh_l > hh_r) right = leftR(right);
				
				n = rightR(N);
			}
		}
		
		h_l = (left)?left->h:0;
		h_r = (right)?right->h:0;
		
		h = max(h_l , h_r) + 1;
		
		return n;
	}
	
	void print(){
		cout<<val<<" ";
		if(left) left->print();
		if(right) right->print();
	}
	
};


int main(){
	
	node * head = new node(1);
	
	head = head->insert(head,2);
	head = head->insert(head,3);
	head = head->insert(head,4);
	head = head->insert(head,5);
	head = head->insert(head,6);
	head = head->insert(head,7);
	head = head->insert(head,8);
	head = head->insert(head,9);
	head = head->insert(head,10);
	head = head->insert(head,11);
	
	head->print();
	
	return 0;
}