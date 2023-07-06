#include <iostream>

using namespace std;

//노드 struct 구현 (data값과 nextNode가 존재)
struct node {
	int data;
	node* nextNode;
};

//링크드 리스트 클래스 생성
class CircleLinkedList {
	private:
		node* head;
		node* tail;
		
	public:
		CircleLinkedList() {
			//head 와 tail의 포인터를 초기화;
			head = NULL;
			tail = NULL;
		}
		//첫번째의 node 추가
		void insertFirstNode(int n);
		//마지막의 node 추가
		void insertLastNode(int n);

		//node 삽입
		void insertNode(node* beforeNode, int n);
		//node 삭제
		void deleteNode(node* beforeNode);

		//첫번째 노드 가져오기
		node* getHead() {
			return head;
		}
		//CircleLinkedList 출력
		void display(node* head);
};

//첫번째의 node 추가
void CircleLinkedList::insertFirstNode(int n) {
	node* temp = new node;
	//temp의 데이터는 n
	temp->data = n;

	//CircleLinkedList가 비어있으면
	if (head == NULL) {
		//첫 node는 temp
		head = temp;
		//마지막 node는 temp
		tail = temp;
	}
	//CircleLinkedList에 데이터가 있으면
	else {
		//temp의 nextNode는 head
		temp->nextNode = head;
		//head는 temp
		head = temp;
		//tail의 다음 node는 head
		tail->nextNode = head;
	}
}

//마지막의 node 추가
void CircleLinkedList::insertLastNode(int n) {
	node* temp = new node;

	//temp의 데이터는 n
	temp->data = n;
	//temp의 nextNode = NULL값
	temp->nextNode = NULL;

	//CircleLinkedList가 비어있으면
	if (head == NULL) {
		//첫 node는 temp
		head = temp;
		//마지막 node는 temp
		tail = temp;
	}
	//CircleLinkedList에 데이터가 있으면
	else {
		//현재 마지막 node의 nextNode는 temp
		tail->nextNode = temp;
		//마지막 node는 temp
		tail = temp;
		//tail의 다음 node는 head
		tail->nextNode = head;
	}
}

//node 삽입
void CircleLinkedList::insertNode(node* beforeNode,int n) {
	node* temp = new node;
	//temp의 데이터는 n
	temp->data = n;

	//temp의 nextNode 저장
	//(삽입 할 앞 node의 nextNode를 temp의 nextNode에 저장)
	temp->nextNode = beforeNode->nextNode;

	//temp 삽입
	//temp앞의 node의 nextNode를 temp로 저장
	beforeNode->nextNode = temp;

	//tail의 다음 node는 head
	tail->nextNode = head;
}

//node 삭제
void CircleLinkedList::deleteNode(node* beforeNode) {

	//삭제할 node를 temp에 저장
	//(삭제할 node의 1단계 전 node의 nextNode) 
	node* temp = beforeNode->nextNode;

	//삭제할 node를 제외
	//(삭제할 node의 nextNode를 1단계 전 node의 nextNode에 저장)
	beforeNode->nextNode = temp->nextNode;

	//temp 삭제
	delete temp;

	//tail의 다음 node는 head
	tail->nextNode = head;
}

//LinkedList 출력
void CircleLinkedList::display(node* head) {
	if (head == NULL) {
		cout << "\n";
	}
	else {
		cout << head->data << " ";

		//순환으로인한 무한 재귀 막기 위해 tail 이면 출력 멈춤
		if (head != tail) {
			display(head->nextNode);
		}
		else if (head == tail) {
			cout << " ";
		}
		
	}
	cout << endl;
}



//메인 함수
int main() {
	CircleLinkedList a;
	//1추가
	a.insertLastNode(1);
	//2추가
	a.insertLastNode(2);
	//3추가
	a.insertLastNode(3);

	//display
	cout << "1,2,3을 CircleLinkedList에 추가\n";
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

	cout << a.getHead()->data;
	cout << endl;
	cout << a.getHead()->nextNode->data;
	cout << endl;
	cout << a.getHead()->nextNode->nextNode->data;
	cout << endl;
	cout << a.getHead()->nextNode->nextNode->nextNode->data;
	cout << endl;
	cout << a.getHead()->nextNode->nextNode->nextNode->nextNode->data;
	cout << endl;
	cout << a.getHead()->nextNode->nextNode->nextNode->nextNode->nextNode->data;
	cout << endl;

}