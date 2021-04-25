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

	destroy(head);
	head = NULL;
	return 0;
}


