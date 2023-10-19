#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

typedef struct BSTNode {
	int data;
	struct BSTNode* left, * right;
} BSTNode;

// ���ο� ��带 �����ϰ� �ʱ�ȭ�մϴ�.
BSTNode* CreateNode(int data) {
	BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
	if (newNode == NULL) {
		printf("�޸� ����");
		exit(1);
	}
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	return newNode;
}

// ���ο� ��带 �����ϰ� �ʱ�ȭ�մϴ�.
BSTNode* newNode(int item) {
	BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
	if (newNode == NULL) {
		printf("�޸� ����");
		exit(1);
	}
	newNode->data = item;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BSTNode* insert_node(BSTNode* root, int key) {
	//Ʈ���� �����̸� ���ο� ��� �����ϰ� ��ȯ�Ѵ�.
	if (root == NULL) return newNode(key);

	/*
	if (root->data == key) { // �����Ͱ� �ߺ��� ���
		printf("�ߺ��� �������Դϴ�.\n");
		return root;
	}
	*/

	// �׷��� ������ ��ȯ������ Ʈ���� ��������
	if (key < root->data) root->left = insert_node(root->left, key);
	else if (key > root->data) root->right = insert_node(root->right, key);

	// ��ȯ�� ��Ʈ �����͸� ��ȯ
	return root;
}

BSTNode* FindMin(BSTNode* node) {
	while (node->left != NULL)
		node = node->left;
	return node;
}

//���� Ž�� Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����ϰ�
// ���ο� ��Ʈ ��带 ��ȯ�Ѵ�.
BSTNode* Delete_Node(BSTNode* root, int data)
{
	BSTNode* temp;
	//data�� ��ġ �˻�
	if (root == NULL)
		printf("Element not there in tree\n");
	else if (data < root->data)
		root->left = Delete_Node(root->left, data);
	else if (data > root->data)
		root->right = Delete_Node(root->right, data);
	//data�� ã�� ���
	else { // case3
		//�ڽ��� 2���� ��� ���� ����Ʈ���� �ִ밪�� ��ü�Ѵ�.
		if (root->left && root->right) {
			//printf("Case3\n");
			temp = FindMin(root->right); //���ӳ�� 
			root->data = temp->data;
			root->right = Delete_Node(root->right, root->data);
		}
		else { //�ڽ��� �ϳ� �Ǵ� ���� ���, case1,2
			if (root->left == NULL && root->right == NULL) {
				//printf("Case1\n");
			}
			else {
				//printf("Case2\n");
			}
			temp = root;
			if (root->left == NULL)
				root = root->right;
			else if (root->right == NULL)
				root = root->left;
			free(temp);
		}
	}
	return root;
}

BSTNode* randomTree_BST(int num) {
	BSTNode* root = NULL;

	for (int i = 0; i < num; i++) {
		int r = rand() % 100000; // ������ ���� ����
		root = insert_node(root, r);
	}

	return root;
}

#define MAX_QUEUE_SIZE 100
typedef BSTNode* element;
typedef struct {
	int front, rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
}

void init_queue(QueueType* Q) {
	Q->front = Q->rear = 0;
}

int is_empty(QueueType* Q) {
	return (Q->front == Q->rear);
}

int is_full(QueueType* Q) {
	return (Q->rear % MAX_QUEUE_SIZE == Q->front);
}

void enqueue(QueueType* Q, element node) {
	Q->rear = (Q->rear + 1) % MAX_QUEUE_SIZE;
	Q->data[Q->rear] = node;
}

element dequeue(QueueType* Q) {
	Q->front = (Q->front + 1) % MAX_QUEUE_SIZE;
	return Q->data[Q->front];
}


void level_order(BSTNode* ptr) {
	QueueType q;
	init_queue(&q);

	if (ptr == NULL) return;

	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf("[%d] ", ptr->data);
		if (ptr->left) enqueue(&q, ptr->left);
		if (ptr->right) enqueue(&q, ptr->right);
	}
}

void inorder_traversal(BSTNode* node) {
	if (node == NULL) return;

	inorder_traversal(node->left);
	printf("[%d] ", node->data);
	inorder_traversal(node->right);
}

BSTNode* Delete(BSTNode* q) {
	BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
	node->data = FindMin(q)->data;
	Delete_Node(q, node->data);
	printf("\n�켱������ ���� ������ node: %d\n", node->data);
	return node;
}

void Sort(int arr[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// �� ���Ҹ� ��ȯ
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main(void) {

	srand((unsigned int)time(NULL)); //seed������ ����ð� �ο�

	// �������� �迭
	int q[1000] = {};
	for (int i = 0; i < 1000; i++) {
		int r = rand() % 100000; // ������ ���� ����
		q[i] = r;
		// printf("[%d], ", q[i]);
	}
	int min = 100000, pos = 0;
	// �ּڰ� ã��
	for (int i = 0; i < 1000; i++) {
		if (min > q[i]) {
			min = q[i];
			pos = i;
		}
	}
	printf("�켱������ ���� ������ ��: [%d], ��ġ: %d", min, pos);
	q[pos] = NULL;
	for (int i = pos + 1; i < 1000; i++) {
		q[i - 1] = q[i];
	}
	printf("\nPriority Queue Delete�۾� �� �ٽ� ����\n");

	// �����ִ� �迭
	int q2[1000] = {};
	for (int i = 0; i < 1000; i++) {
		int r = rand() % 100000; // ������ ���� ����
		q2[i] = r;
		//printf("[%d], ", q2[i]);
	}
	Sort(q2, 1000);
	printf("\n\n����(���� �ִ� �迭)\n");
	for (int i = 0; i < 1000; i++) {
		//printf("[%d], ", q2[i]);
	}
	printf("�켱������ ���� ������ ��: [%d] ", q2[0]);
	q2[0] = NULL;
	for (int i = 1; i < 1000; i++) {
		q2[i - 1] = q2[i];
	}
	printf("\nPriority Queue Delete�۾� �� �ٽ� ����\n");

	// BST
	printf("\nPriority Queue (BST)");
	BSTNode* root_randBST = NULL;

	root_randBST = randomTree_BST(1000);
	//printf("\ninorder\n");
	//inorder_traversal(root_randBST);
	//printf("\nlevel order\n");
	//level_order(root_randBST);

	Delete(root_randBST);

	//printf("\ninorder\n");
	//inorder_traversal(root_randBST);
	//printf("\nlevel order\n");
	//level_order(root_randBST);

	return 0;
}