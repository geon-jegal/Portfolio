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

// �θ� ���� �¿� �ڽ� ��带 �����մϴ�.
void MakeTree(BSTNode* parent, BSTNode* lson, BSTNode* rson)
{
	parent->left = lson;
	parent->right = rson;
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

BSTNode* min_value_node(BSTNode* node) {
	BSTNode* current = node;

	//�� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL) current = current->left;

	return current;
}

BSTNode* FindMin(BSTNode* node) {
	while (node->left != NULL)
		node = node->left;
	return node;
}

BSTNode* FindMax(BSTNode* node) {
	while (node->right != NULL)
		node = node->right;
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


//��ȯ���� Ž�� �Լ�
BSTNode* search(BSTNode* node, int key) {
	if (node == NULL) {
		printf("�����͸� �˻����� �� �Ͽ����ϴ�.\n");
		return NULL;
	}
	if (key == node->data) {
		printf("%d", node->data);
		return node; // (1)
	}
	else if (key < node->data)
		return search(node->left, key); // (2)
	else
		return search(node->right, key); // (3)
}

int search_count_recursive(BSTNode* node, int key, int count) {
	if (node == NULL) {
		return count; // �����͸� ã�� ���� ��� ��������� Ž�� Ƚ�� ��ȯ
	}

	count++;

	if (key == node->data) {
		return count;
	}
	else if (key < node->data) {
		return search_count_recursive(node->left, key, count);
	}
	else {
		return search_count_recursive(node->right, key, count);
	}
}

// �ݺ����� Ž�� �Լ�
BSTNode* search_Iter(BSTNode* node, int key) {
	int level = 0;
	while (node != NULL) {
		if (key == node->data) {
			level++;
			printf("\nƮ���� �˻� Ƚ��(iter) : %d\n", level);
			return node;
		}
		else if (key < node->data) {
			node = node->left;
			level++;
		}
		else {
			node = node->right;
			level++;
		}
	}
	printf("�����͸� �˻����� �� �Ͽ����ϴ�.\n");
	printf("Ʈ���� �˻� Ƚ��(iter) : %d\n", level);
	return NULL; // Ž���� �������� ��� NULL ��ȯ
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

void preorder_traversal(BSTNode* node) {
	if (node == NULL) return;

	printf("%d ", node->data);
	preorder_traversal(node->left);
	preorder_traversal(node->right);
}

// ����� ���� ���� �Լ�
int count_nodes(BSTNode* node) {
	if (node == NULL) return 0;
	return 1 + count_nodes(node->left) + count_nodes(node->right);
}

// Ʈ�� ���� ��� �Լ�
int tree_depth(BSTNode* node) {
	if (node == NULL) return -1; // �� Ʈ���� -1�� ��ȯ
	int left_depth = 0;
	left_depth = tree_depth(node->left);
	int right_depth = 0;
	right_depth = tree_depth(node->right);
	return 1 + (left_depth > right_depth ? left_depth : right_depth);
}


void print_node(BSTNode* node) {
	if (node == NULL) return;

	printf("%d ", node->data);

	if (node->left != NULL || node->right != NULL) {
		printf("(");
		if (node->left != NULL) print_node(node->left);
		else printf("NULL");

		printf(", ");

		if (node->right != NULL) print_node(node->right);
		else printf("NULL");

		printf(")");
	}
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
		printf("[%d], ", q[i]);
	}
	int min = 100000;
	for (int i = 0; i < 1000; i++) {
		if (min > q[i]) min = q[i];
	}
	for (int i = 0; i < 1000; i++) {
		if (min == q[i]) q[i] = NULL;
	}
	printf("\n\n�켱������ ���� ������ ��: [%d] ", min);


	// �����ִ� �迭
	int q2[1000] = {};
	for (int i = 0; i < 1000; i++) {
		int r = rand() % 100000; // ������ ���� ����
		q2[i] = r;
		//printf("[%d], ", q2[i]);
	}
	Sort(q2, 1000);
	printf("\n����\n");
	for (int i = 0; i < 1000; i++) {
		printf("[%d], ", q2[i]);
	}
	printf("\n\n�켱������ ���� ������ ��: [%d] ", q2[0]);
	q2[0] = NULL;

	// BST
	BSTNode* root_randBST = NULL;

	root_randBST = randomTree_BST(10);
	printf("\ninorder\n");
	inorder_traversal(root_randBST);
	printf("\nlevel order\n");
	level_order(root_randBST);

	Delete(root_randBST);

	printf("\ninorder\n");
	inorder_traversal(root_randBST);
	printf("\nlevel order\n");
	level_order(root_randBST);

	return 0;
}