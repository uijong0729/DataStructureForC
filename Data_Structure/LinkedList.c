#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


// �ڷᱸ�� ����
/*
	���� ����Ʈ

*/
// ����ü ���漱�� 
typedef struct node node_t;

// ��� : ���� �����Ϳ� ���� ����� �ּ� 
typedef struct node {
	int value;
	node_t* next;
} node_t;

// ���Ḯ��Ʈ ��� 
void print_node(const node_t* head)
{
	node_t* p = head;
	
	// NULL�� NULL������
	while (p != NULL) {
		// ���⼭ ��� 
		printf("%d / ", p->value);

		// "->" �� ���� ��� ���� ������ (����ü�� ��������� �����ϴ� ��ȣ)
		p = p->next;
	}
}

// ��� �޸� ���� 
void destroy(node_t* head) {
	node_t* p = head;

	while (p != NULL) {
		// �����ϱ� ���� �ϴ� ���� ��带 ������ 
		node_t* next = p->next;

		// ����
		free(p);
		
		// ������ ���� ��带 p�� ���� �� 
		p = next;
	}
}

// ���� ���� ���簡 �ƴ� ������ ���� ������ �߿� ���� 
// @Param node_t** phead	: head�� �ּ� (phead�� head�� ����Ű�� ������������ �� ����Ű�� head�� �������̹Ƿ� ����������)
// @Param int n				: (������ġ�� �� ��) n�� ����
// ���� �߰��Ǵ� ��尡 ������ ��忡 ���ٰ� ����
void insert_front(node_t** phead, int n) 
{
	// void* malloc(size_t) : size_t��ŭ�� ����Ʈ�� ��û�ϰ� �����͸� �� �����ּҿ� ��������
	// ����ü node_t�� ������ ��ŭ�� ũ���� ����Ʈ�� ��û�ϰ� �����͸� �� �����ּҿ� ��������
	node_t* new_node = malloc(sizeof(node_t)); // �ڹٷ�ġ�� node_t new_node = new node_t();
	
	// ����ü new_node�� value�� ���� ���� 
	new_node->value = n;
	// ����ü new_node�� next�� �� ��(head) �ּҸ� ����
	new_node->next = *phead;

	// �� �տ� ���ο� �����Ͱ� ���ԵǾ� head�� �ٲ���� 
	*phead = new_node;
}

// ����� �ڷ� �߰�
void insert_back(node_t** phead, int n) 
{
	node_t* new_node;
	node_t** pp = phead;

	new_node = malloc(sizeof(node_t));
	new_node->next = NULL;
	new_node->value = n;

	// ��尡 0���� ��
	if (*pp == NULL) {
		*pp = new_node;
	}
	else {
		while (*pp != NULL) {
			// next�� NULL�� ���� ������ ��� 
			if ((*pp)->next == NULL) {
				(*pp)->next = new_node;
				break;
			}
			pp = &(*pp)->next;
		}
	}
}

// ���������� �����ϸ鼭 �����ϴ� �Լ�
void insert_sorted(node_t** phead, int n)
{
	// ���� �����͸� ���ư��� ���°� �ƴ϶�, ���� ����� ���� �̸� �����ϱ����� ���������� ���
	node_t** pp = phead;
	node_t* new_node;

	// ���ο� ��带 �����ϰ� ���� ����
	new_node = malloc(sizeof(node_t));
	new_node->value = n;

	// head�� ���� �ִٴ� �� �����Ͱ� 1�� �̻��̶�� ��
	// �����Ͱ� 1�� �̻��϶� ������ ����
	while (*pp != NULL) {
		// n���� ����Ʈ�� �� ��带 ���ؼ�
		// �������� �տ� ���Եǵ��� 
		if ((*pp)->value >= n) {
			break;
		}
		else {
			// ���� ��� 
			pp = &(*pp)->next;
		}
	}

	// ���ο� ����� ������带 ����Ű�� �����Ϳ� *pp�� ���� (�����������̹Ƿ� �ѹ� �������ؼ� �̱������ͷ�)
	new_node->next = *pp;
	
	// ��ġ�� ������ ���ο� ��带 ����
	*pp = new_node;
}

//��� ����
void remove_node(node_t** phead, int n) 
{
	node_t** pp = phead;

	while (*pp != NULL) {
		// ������� �ϴ� ������ Ȯ�� 
		if ((*pp)->value == n) {
			node_t* tmp = *pp;
			*pp = (*pp)->next;
			
			// �ش� ��� ���� 
			free(tmp);
			break;
		}

		// ���� ��� 
		pp = &(*pp)->next;
	}

}

int solution4(void) {
	
	node_t* head = NULL;

	// ��Ծ����� ����
	// ���ּ� ������ &				: �ش� ������ ��ġ�� �޸� �ּҸ� ����ϴ� ������
	// ���������� ����				: int* pointer = &score;
	// ���������� �� ���(������)	: *pointer
	// ���������� �ּ� ���			: pointer
	insert_front(&head, 3);
	insert_front(&head, 2);
	insert_front(&head, 5);
	print_node(head);
	destroy(head);
	head = NULL;

	printf("\n");

	/////////////////////////////
	insert_sorted(&head, 8);
	insert_sorted(&head, 3);
	insert_sorted(&head, 2);
	insert_sorted(&head, 5);
	print_node(head);
	destroy(head);
	head = NULL;

	printf("\n");

	/////////////////////////////
	insert_back(&head, 8);
	insert_back(&head, 3);
	insert_back(&head, 2);
	insert_back(&head, 5);
	print_node(head);
	destroy(head);
	head = NULL;

	return 0;
}


