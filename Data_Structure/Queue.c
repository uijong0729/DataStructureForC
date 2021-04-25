#include <stdio.h>
#include <stddef.h>
#include <assert.h>

// �ڷᱸ�� ����
/*
	ťqueue
		���ð� ���������� �ڷ��ǻ��԰� ������ ���� ��Ģ�� �ִ� �ڷᱸ��
		������� ���Ե� �����Ͱ� ���� ó���� ������
		���Լ���

*/
enum { MAX_NUMS = 8 };
enum {TRUE = 1, FALSE = 0};
enum { INVALID_INDEX = -1 };
int s_nums[MAX_NUMS];

// �� (���Ե� �����Ͱ� �ִ� �ڸ�)
size_t s_front = 0;
// �� (�� �ڸ�)
size_t s_back = 0;

// �迭�� ��Ұ� �� �� �� �ִ��� Ȯ���ϴ� ����
size_t s_num_count3 = 0;

int is_empty2(void) 
{
	return (s_num_count3 == 0);
}

// ������ �׻� �ڿ��� �̷�����Ƿ� s_back�� �ٷ�� �Լ��� �ȴ�.
// �ð� ���⵵ O(1)
// "����"���� ����̹Ƿ� back���� �߰��ȴ� �����Ͽ� �ۼ�
void enqueue(int n) 
{
	assert(s_num_count3 < MAX_NUMS);

	s_nums[s_back] = n;
	
	// ������ ������ ���� �����͸� �����ϴ�
	// �ε����� �Ѿ������ �ٽ� �տ������� ä�쵵�� 
	s_back = (s_back + 1) % MAX_NUMS;
	
	++s_num_count3;
}

//ť�� ����
// ����"����"����̹Ƿ� front�� �������� ������� ������ �����Ͽ� �ۼ�
int dequeue(void) 
{
	// ���� �տ� �ִ� �����͸� ������ ����
	int ret;

	// s_num_count3 : �迭�� ���� ��ġ(���� �ֱٵ�����)
	// ������ ���� ������ ����
	assert(is_empty2() == FALSE);

	// ����� s_front�� 0���� �ʱ�ȭ �Ǿ����� 
	ret = s_nums[s_front];

	// ���� ����Ǿ��ִ� �������� ���� �ٿ���
	--s_num_count3;

	// ������������ ��� (�������������� ����ϸ� �� �� �ε����� ������ �� ó�� �ε�����)
	s_front = (s_front + 1) % MAX_NUMS;

	return ret;
}

//ť�� �˻�
// ��� ��Ҹ� �� �����ߴٰ� �ٽ� ���󺹱�
// �ð� ���⵵ : O(n)
// ť�� �뵵 : ����� / ������ ���Լӵ��� �Ҹ� �ӵ����� ������� 
// ���ʿ� �˻��� ���ο� �� ������ ������ �ƴϹǷ� ������ ���� 

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


