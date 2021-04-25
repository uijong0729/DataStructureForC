#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


// 자료구조 기초
/*
	연결 리스트

*/



// 구조체 전방선언 
typedef struct node node_t;

// 노드 : 실제 데이터와 다음 노드의 주소 
typedef struct node {
	int value;
	node_t* next;
} node_t;

// 연결리스트 출력 
void print_node(const node_t* head)
{
	node_t* p = head;
	
	// NULL은 NULL포인터
	while (p != NULL) {
		// 여기서 출력 
		

		// "->" 는 간접 멤버 참조 연산자 (구조체의 멤버변수를 참조하는 기호)
		p = p->next;
	}
}

// 노드 메모리 해제 
void destroy(node_t* head) {
	node_t* p = head;

	while (p != NULL) {
		// 해제하기 전에 일단 다음 노드를 가져옴 
		node_t* next = p->next;

		// 해제
		free(p);
		
		// 해제후 다음 노드를 p에 대입 함 
		p = next;
	}
}

// 값에 의한 복사가 아닌 참조에 의한 전달이 중요 개념 
// @Param node_t** phead	: head의 주소 (phead는 head를 가리키는 포인터이지만 그 가리키는 head도 포인터이므로 이중포인터)
// @Param int n				: (삽입위치는 맨 앞) n을 삽입
// 새로 추가되는 노드가 언제나 헤드에 들어간다고 가정
void insert_front(node_t** phead, int n) 
{
	// void* malloc(size_t) : size_t만큼의 바이트를 요청하고 포인터를 그 시작주소에 포인팅함
	// 구조체 node_t의 사이즈 만큼의 크기의 바이트를 요청하고 포인터를 그 시작주소에 포인팅함
	node_t* new_node = malloc(sizeof(node_t)); // 자바로치면 node_t new_node = new node_t();
	
	// 구조체 new_node의 value에 값을 대입 
	new_node->value = n;
	// 구조체 new_node의 next에 맨 앞(head) 주소를 대입
	new_node->next = *phead;

	// 맨 앞에 새로운 데이터가 삽입되어 head가 바뀌었다 
	*phead = new_node;
}

int solution4(void) {
	
	node_t* head = NULL;

	// 까먹었으니 복습
	// ◆주소 연산자 &				: 해당 변수가 위치한 메모리 주소를 취득하는 연산자
	// ◆포인터의 선언				: int* pointer = &score;
	// ◆포인터의 값 취득(역참조)	: *pointer
	// ◆포인터의 주소 취득			: pointer
	insert_front(&head, 3);
	insert_front(&head, 2);
	insert_front(&head, 5);

	destroy(head);
	head = NULL;
	return 0;
}


