#include <stdio.h>
#include <stddef.h>
#include <assert.h>

// �ڷᱸ�� ����
/*
	����(Stack)
		���� ���� ����(PUSH)�� �����Ͱ� ���� �������� ����(POP)��

*/
enum { MAX_NUMS = 8, TRUE = 1, FALSE = 0 };
enum { INVALID_INDEX = -1 };
int s_nums[MAX_NUMS];
size_t s_num_count2 = 0;

//������ ����
// �ð����⵵ O(1)
void push(int n) 
{
	assert(s_num_count2 < MAX_NUMS);
	s_nums[s_num_count2++] = n;
}

int is_empty(void)
{
	return (s_num_count2 == 0);
}

//������ ���� 
// POP : ���ÿ��� �̾Ƴ��ٰ��ؼ� ���̶�� ��
// �ð� ���⵵ O(1)
int pop(void) 
{	
	assert(is_empty() == FALSE);

	return s_nums[--s_num_count2];
}

//������ �˻�
// ���� �������� ���� �˻�
// �ð� ���⵵ O(n)
// ���� push�� pop�� ����ϹǷ� ������ ��ҿ� ������ ����� ����
// ��Ģ������ ��� ��Ҹ� �� �����ߴٰ� �ٽ� ���󺹱��ϴ� ������� �˻��ؾ� ��
// �̶� ���󺹱��� ���������ϸ� LIFO�� ��Ģ�� ���� ������ �� ����
// ���� �ð� ���⵵ O(2n)������ -> �ð� ���⵵�� �˰��� ������ ��� ������ ��Ÿ���Ƿ� -> O(n) ��� ǥ��

//������ �뵵
// 1.�ڷ���� ������ ����� ����� �� ������
// 2.���� ǥ������� �� ���ڿ� ������ �������� Ȱ�밡��(�� ��Ʈ ����)
// 3.����Լ��� �����ϴµ� ����
int solution2(void)
{
	push(33);
	printf("%d", s_nums[0]);

	pop();
	printf("%d", s_nums[0]);
	return 0;
}


