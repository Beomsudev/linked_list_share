#include <iostream>

using namespace std;

//��� struct ���� (data���� nextNode�� ����)
struct node {
	int data;
	node* nextNode;
};

//��ũ�� ����Ʈ Ŭ���� ����
class SingleLinkedList {
	private:
		node* head;
		node* tail;
		
	public:
		SingleLinkedList() {
			//head �� tail�� �����͸� �ʱ�ȭ;
			head = NULL;
			tail = NULL;
		}
		//ù��°�� node �߰�
		void insertFirstNode(int n);
		//�������� node �߰�
		void insertLastNode(int n);

		//node ����
		void insertNode(node* beforeNode, int n);
		//node ����
		void deleteNode(node* beforeNode);

		//ù��° ��� ��������
		node* getHead() {
			return head;
		}
		//SingleLinkedList ���
		void display(node* head);
};

//ù��°�� node �߰�
void SingleLinkedList::insertFirstNode(int n) {
	node* temp = new node;
	//temp�� �����ʹ� n
	temp->data = n;

	//SingleLinkedList�� ���������
	if (head == NULL) {
		//ù node�� temp
		head = temp;
		//������ node�� temp
		tail = temp;
	}
	//SingleLinkedList�� �����Ͱ� ������
	else {
		//temp�� nextNode�� head
		temp->nextNode = head;
		//head�� temp
		head = temp;
	}
}

//�������� node �߰�
void SingleLinkedList::insertLastNode(int n) {
	node* temp = new node;

	//temp�� �����ʹ� n
	temp->data = n;
	//temp�� nextNode = NULL��
	temp->nextNode = NULL;

	//SingleLinkedList�� ���������
	if (head == NULL) {
		//ù node�� temp
		head = temp;
		//������ node�� temp
		tail = temp;
	}
	//SingleLinkedList�� �����Ͱ� ������
	else {
		//���� ������ node�� nextNode�� temp
		tail->nextNode = temp;
		//������ node�� temp
		tail = temp;
	}
}

//node ����
void SingleLinkedList::insertNode(node* beforeNode,int n) {
	node* temp = new node;
	//temp�� �����ʹ� n
	temp->data = n;

	//temp�� nextNode ����
	//(���� �� �� node�� nextNode�� temp�� nextNode�� ����)
	temp->nextNode = beforeNode->nextNode;

	//temp ����
	//temp���� node�� nextNode�� temp�� ����
	beforeNode->nextNode = temp;
}

//node ����
void SingleLinkedList::deleteNode(node* beforeNode) {

	//������ node�� temp�� ����
	//(������ node�� 1�ܰ� �� node�� nextNode) 
	node* temp = beforeNode->nextNode;

	//������ node�� ����
	//(������ node�� nextNode�� 1�ܰ� �� node�� nextNode�� ����)
	beforeNode->nextNode = temp->nextNode;

	//temp ����
	delete temp;
}

//LinkedList ���
void SingleLinkedList::display(node* head) {
	if (head == NULL) {
		cout << "\n";
	}
	else {
		cout << head->data << " ";
		display(head->nextNode);
	}
	cout << endl;
}



//���� �Լ�
int main() {
	SingleLinkedList a;
	//1�߰�
	a.insertLastNode(1);
	//2�߰�
	a.insertLastNode(2);
	//3�߰�
	a.insertLastNode(3);

	//display
	cout << "1,2,3�� SingleLinkedList�� �߰�\n";
	a.display(a.getHead());

	//0�� ���� �տ� �߰�
	a.insertFirstNode(0);

	//1�� �׹�°�� �߰�
	a.insertNode(a.getHead()->nextNode, 21);
	cout << "0�� ù��°�� �߰�, 1�� �׹�°�� �߰�\n";
	a.display(a.getHead());

	//����° ��� ����
	a.deleteNode(a.getHead()->nextNode);

	//display
	cout << "����° ��带 ����\n"; 
	a.display(a.getHead());
}