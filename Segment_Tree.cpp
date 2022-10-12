#include <iostream>
#include <vector>
using namespace std;

int n;

vector<int> segment_tree((int)(1e5));

int build(int start , int end  , int index , vector<int> arr) {
	// cout << start << " " << end << " " << index << endl;

	if (start == end) return  segment_tree[index] = arr[start];

	int i = (end + start) / 2 ;

	return segment_tree[index] = build(start , i , index * 2 + 1 , arr) ^ build(i + 1 , end , index * 2 + 2 , arr);


}

int quary(int start  , int end , int f = 0 , int l = n-1 , int index=0) {

	if (f == start && end == l) return segment_tree[index];
	if (start > (f + l) / 2 ) return quary(start , end , (f + l) / 2 + 1 , l , index * 2 + 2);

	if (end <= (f + l) / 2 )return quary(start , end , f , (l + f) / 2 , index * 2 + 1);

	return quary(start , (f + l) / 2 , f , (f + l) / 2 , index * 2 + 1 ) + quary( (f + l) / 2 + 1  , end , (f + l) / 2 + 1 , l , index * 2 + 2 );

}

int change (int index , int now , int i, int priv , int start , int end) {
	if (start == index && end == index ) {segment_tree[i] = now ; return 1;}

	segment_tree[i] ^= (now ^ priv) ;

	if (index <= (start + end) / 2 ) return change(index , now , i * 2 + 1 , priv , start , (start + end) / 2);

	return change(index , now , i * 2 + 2 , priv , (start + end) / 2 + 1 , end );

}


int main() {

	vector<int> arr = {10, 2, 0, 4, 20, 32, 3, 32};
	n = arr.size();

	build(0 , arr.size() - 1 , 0 , arr);


	cout << quary(1 , 4 ) << endl;

	change(1 , 5 , 0 , 2  , 0 , n - 1 );

	cout << quary(1 , 4 ) << endl;



	return 0;
}