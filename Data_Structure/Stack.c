#include <stdio.h>
#include <stddef.h>
#include <assert.h>

// 자료구조 기초
/*
	스택(Stack)
		가장 먼저 삽입(PUSH)된 데이터가 제일 마지막에 삭제(POP)됨

*/
enum { MAX_NUMS = 8, TRUE = 1, FALSE = 0 };
enum { INVALID_INDEX = -1 };
int s_nums[MAX_NUMS];
size_t s_num_count2 = 0;

//스택의 삽입
// 시간복잡도 O(1)
void push(int n) 
{
	assert(s_num_count2 < MAX_NUMS);
	s_nums[s_num_count2++] = n;
}

int is_empty(void)
{
	return (s_num_count2 == 0);
}

//스택의 제거 
// POP : 스택에서 뽑아낸다고해서 팝이라고 함
// 시간 폭잡도 O(1)
int pop(void) 
{	
	assert(is_empty() == FALSE);

	return s_nums[--s_num_count2];
}

//스택의 검색
// 제일 위에부터 순차 검색
// 시간 복잡도 O(n)
// 보통 push와 pop만 허용하므로 임의의 요소에 접근할 방법이 없음
// 원칙적으로 모든 요소를 다 제거했다가 다시 원상복구하는 방식으로 검색해야 함
// 이때 원상복구도 스택으로하면 LIFO의 원칙을 쉽게 구현할 수 있음
// 논리상 시간 복잡도 O(2n)이지만 -> 시간 복잡도는 알고리즘 연산의 비례 수준을 나타내므로 -> O(n) 라고 표기

//스택의 용도
// 1.자료들의 순서를 뒤집어서 사용할 때 유용함
// 2.후위 표기법으로 된 문자열 계산식은 스택으로 활용가능(원 노트 참고)
// 3.재귀함수를 제거하는데 유용
int solution2(void)
{
	push(33);
	printf("%d", s_nums[0]);

	pop();
	printf("%d", s_nums[0]);
	return 0;
}


