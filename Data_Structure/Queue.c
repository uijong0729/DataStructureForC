#include <stdio.h>
#include <stddef.h>
#include <assert.h>

// 자료구조 기초
/*
	큐queue
		스택과 마찬가지로 자료의삽입과 삭제에 대한 규칙이 있는 자료구조
		가장먼저 삽입된 데이터가 제일 처음에 삭제됨
		선입선출

*/
enum { MAX_NUMS = 8 };
enum {TRUE = 1, FALSE = 0};
enum { INVALID_INDEX = -1 };
int s_nums[MAX_NUMS];

// 앞 (선입된 데이터가 있는 자리)
size_t s_front = 0;
// 뒤 (빈 자리)
size_t s_back = 0;

// 배열에 요소가 몇 개 들어가 있는지 확인하는 변수
size_t s_num_count3 = 0;

int is_empty2(void) 
{
	return (s_num_count3 == 0);
}

// 삽입은 항상 뒤에서 이루어지므로 s_back만 다루는 함수가 된다.
// 시간 복잡도 O(1)
// "선입"선출 방식이므로 back에서 추가된다 가정하여 작성
void enqueue(int n) 
{
	assert(s_num_count3 < MAX_NUMS);

	s_nums[s_back] = n;
	
	// 나머지 연산을 통해 데이터를 삽입하다
	// 인덱스를 넘어버리면 다시 앞에서부터 채우도록 
	s_back = (s_back + 1) % MAX_NUMS;
	
	++s_num_count3;
}

//큐의 삭제
// 선입"선출"방식이므로 front를 기준으로 순서대로 빠진다 가정하여 작성
int dequeue(void) 
{
	// 제일 앞에 있는 데이터를 저장할 변수
	int ret;

	// s_num_count3 : 배열의 현재 위치(가장 최근데이터)
	// 삭제할 것이 없으면 에러
	assert(is_empty2() == FALSE);

	// 참고로 s_front는 0으로 초기화 되어있음 
	ret = s_nums[s_front];

	// 실제 저장되어있는 데이터의 수를 줄여줌
	--s_num_count3;

	// 원형데이터인 경우 (나머지연산으로 계산하면 맨 끝 인덱스의 다음은 맨 처음 인덱스임)
	s_front = (s_front + 1) % MAX_NUMS;

	return ret;
}

//큐의 검색
// 모든 요소를 다 제거했다가 다시 원상복구
// 시간 복잡도 : O(n)
// 큐의 용도 : 대기줄 / 데이터 유입속도가 소모 속도보다 빠른경우 
// 애초에 검색을 염두에 둔 데이터 구조가 아니므로 구현은 지양 

int solution3(void)
{
	enqueue(33);
	printf("%d", s_nums[0]);

	enqueue(11);
	printf("%d", s_nums[1]);
	
	dequeue();
	//printf("%d", s_nums[1]);

	return 0;
}


