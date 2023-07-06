#include <iostream>
#include <list>

using namespace std;


bool predicate(int n){
	return n <= 2;

}

int main(){
	
	// List 생성
	list<int> list_int {1, 2, 3, 4, 5};
	cout << "List 생성 \n";
	for(const auto& i: list_int) cout << i << " ";
	cout << endl;
	// result : 1 2 3 4 5

	// push, pop
	list<int> a_list {1, 2, 3, 4, 5};

	cout << endl;
	cout << "push_front()\n";

	a_list.push_front(0);
	for(const auto& i: a_list) cout << i << " ";

	cout << endl;


	cout << endl;
	cout << "push_back()\n";

	a_list.push_back(6);
	for(const auto& i: a_list) cout << i << " ";

	cout << endl;

	cout << endl;
	cout << "pop_front()\n";

	a_list.pop_front();
	for(const auto& i: a_list) cout << i << " ";

	cout << endl;

	cout << endl;
	cout << "pop_back()\n";

	a_list.pop_back();
	for(const auto& i: a_list) cout << i << " ";

	cout << endl;

	// insert, erase, remove, remove_if

	cout << endl;
	cout << "insert()\n";

	a_list.insert(++a_list.begin(), 0);
	for(const auto& i: a_list) cout << i << " ";

	cout << endl;

	cout << endl;
	cout << "erase()\n";

	a_list.erase(++a_list.begin());
	for(const auto& i: a_list) cout << i << " ";

	cout << endl;

	list<int> b_list {1, 2, 3, 4, 5, 1, 1, 1, 1, 1};

	cout << endl;
	cout << "remove()\n";

	b_list.remove(1);
	for(const auto& i: b_list) cout << i << " ";

	cout << endl;	

	cout << endl;
	cout << "remove_if()\n";


	b_list.remove_if(predicate);
	for(const auto& i: b_list) cout << i << " ";

	cout << endl;	

	list<int> c_list {3, 4, 2, 8, 9, 10, 2, 1};

	cout << endl;
	cout << "sort()\n";

	for(const auto& i: c_list) cout << i << " ";
	cout << endl;	

	c_list.sort();
	for(const auto& i: c_list) cout << i << " ";

	cout << endl;	

	cout << endl;
	cout << "reverse()\n";

	for(const auto& i: c_list) cout << i << " ";
	cout << endl;	

	c_list.reverse();
	for(const auto& i: c_list) cout << i << " ";

	cout << endl;	

	cout << endl;
	cout << "size()\n";

	cout << c_list.size();

	cout << endl;	

}