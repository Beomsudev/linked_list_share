#include <iostream>

using namespace std;

//노드 struct 구현 (data, nextNode, prevNode)
struct node {
	int data;
	node* nextNode;
	node* prevNode;
};

//링크드 리스트 클래스 생성
class DoubleLinkedList {
	private:
		node* head;
		node* tail;
		
	public:
		DoubleLinkedList() {
			//head 와 tail의 포인터를 초기화;
			head = NULL;
			tail = NULL;
		}
		//첫번째의 node 삽입
		void insertFirstNode(int n);
		
		//마지막의 node 삽입
		void insertLastNode(int n);

		//중간의   node 삽입
		void insertNode(node* beforeNode, int n);
		
		//node 삭제
		void deleteNode(node* beforeNode);

		//첫번째 노드 가져오기
		node* getHead() {
			return head;
		}
		//LinkedList 출력
		void display(node* head);
};

//첫번째의 node 추가
void DoubleLinkedList::insertFirstNode(int n) {
	node* temp = new node;
	//temp의 데이터는 n
	temp->data = n;

	//temp의 prevNode = NULL값 (첫번째 값 이므로)
	temp->prevNode = NULL;

	//LinkedList가 비어있으면
	if (head == NULL) {
		//첫 node는 temp
		head = temp;
		//마지막 node는 temp
		tail = temp;

		//값이 1개만 있으므로
		temp->nextNode = NULL;
	}
	//LinkedList에 데이터가 있으면
	else {
		//temp의 nextNode는 이전 head
		temp->nextNode = head;

		//이전 head의 prevNode는 temp
		head->prevNode = temp;

		//head는 temp
		head = temp;
	}
}

//마지막의 node 추가
void DoubleLinkedList::insertLastNode(int n) {
	node* temp = new node;

	//temp의 데이터는 n
	temp->data = n;

	//temp의 nextNode = NULL값 (마지막 값 이므로)
	temp->nextNode = NULL;
	
	//LinkedList가 비어있으면
	if (head == NULL) {
		//첫 node는 temp
		head = temp;
		//마지막 node는 temp
		tail = temp;

		//값이 1개만 있으므로
		temp->prevNode = NULL;
	}
	//LinkedList에 데이터가 있으면
	else {
		//temp의 이전 node = tail
		temp->prevNode = tail;

		//현재 마지막 node의 nextNode는 temp
		tail->nextNode = temp;

		//tail는 temp
		tail = temp;
	}
}

//node 삽입
void DoubleLinkedList::insertNode(node* beforeNode, int n) {
	node* temp = new node;
	//temp의 데이터는 n
	temp->data = n;

	//temp의 nextNode 는 이전 Node의 다음 Node
	temp->nextNode = beforeNode->nextNode;

	//beforeNode 뒤에 삽입 하므로
	temp->prevNode = beforeNode;

	//temp와 이전 이후 node 연결
	beforeNode->nextNode = temp;
}

//node 삭제
void DoubleLinkedList::deleteNode(node* beforeNode) {

	//삭제할 node를 temp에 저장
	//(삭제할 node의 1단계 전 node의 nextNode) 
	node* temp = beforeNode->nextNode;

	//삭제할 node를 제외
	//(삭제할 node의 nextNode를 1단계 전 node의 nextNode에 저장)
	beforeNode->nextNode = temp->nextNode;
	temp->nextNode = beforeNode;

	//temp 삭제
	delete temp;
}

//LinkedList 출력
void DoubleLinkedList::display(node* head) {
	if (head == NULL) {
		cout << "\n";
	}
	else {
		cout << head->data << " ";
		display(head->nextNode);
	}
	cout << endl;
}

//메인 함수
int main() {
	DoubleLinkedList a;
	//1추가
	a.insertLastNode(1);
	//2추가
	a.insertLastNode(2);
	//3추가
	a.insertLastNode(3);

	//display
	cout << "1,2,3을 DoubleLinkedList에 추가\n";
	a.display(a.getHead());




	//0을 제일 앞에 추가
	a.insertFirstNode(0);

	//1을 네번째에 추가
	a.insertNode(a.getHead()->nextNode, 21);
	cout << "0을 첫번째에 추가, 1을 네번째에 추가\n";
	a.display(a.getHead());




	//세번째 노드 삭제
	a.deleteNode(a.getHead()->nextNode);

	//display
	cout << "세번째 노드를 삭제\n"; 
	a.display(a.getHead());


	cout << endl;
	cout << "*****";
	cout << endl;

	cout << "data : " << a.getHead()->data;
	cout << endl;
	cout << "prevnode : " << a.getHead()->prevNode;
	cout << endl;
	cout << "my  node : " << a.getHead();
	cout << endl;
	cout << "nextnode : " << a.getHead()->nextNode;

	cout << endl;
	cout << "*****";
	cout << endl;

	cout << endl;
	cout << "*****";
	cout << endl;
	
	cout << "data : " << a.getHead()->nextNode->data;
	cout << endl;
	cout << "prevnode : " << a.getHead()->nextNode->prevNode;
	cout << endl;
	cout << "my  node : " << a.getHead()->nextNode;
	cout << endl;
	cout << "nextnode : " << a.getHead()->nextNode->nextNode;
	
	cout << endl;
	cout << "*****";
	cout << endl;

	cout << endl;
	cout << "*****";
	cout << endl;
	
	cout << "data : " << a.getHead()->nextNode->nextNode->data;
	cout << endl;
	cout << "prevnode : " << a.getHead()->nextNode->nextNode->prevNode;
	cout << endl;
	cout << "my  node : " << a.getHead()->nextNode->nextNode;
	cout << endl;
	cout << "nextnode : " << a.getHead()->nextNode->nextNode->nextNode;

	cout << endl;
	cout << "*****";
	cout << endl;

	cout << endl;
	cout << "*****";
	cout << endl;
	
	cout << "data : " << a.getHead()->nextNode->nextNode->nextNode->data;
	cout << endl;
	cout << "prevnode : " << a.getHead()->nextNode->nextNode->nextNode->prevNode;
	cout << endl;
	cout << "my  node : " << a.getHead()->nextNode->nextNode->nextNode;
	cout << endl;
	cout << "nextnode : " << a.getHead()->nextNode->nextNode->nextNode->nextNode;

	cout << endl;
	cout << "*****";
	cout << endl;

	cout << endl;
	cout << "*****";
	cout << endl;
	
	cout << "1 : " << a.getHead();
	cout << endl;
	cout << "2 : " << a.getHead()->nextNode;
	cout << endl;
	cout << "3 : " << a.getHead()->nextNode->nextNode;
	cout << endl;
	cout << "4 : " << a.getHead()->nextNode->nextNode->nextNode;

	cout << endl;
	cout << "*****";
	cout << endl;

}