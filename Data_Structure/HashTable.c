#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>

#define BUCKET_SIZE 23
char* keys[BUCKET_SIZE];
int values[BUCKET_SIZE];

// �ſ� ����ȭ�� �ؽ��Լ� 
int hash_function(const char* str)
{
	int code = 0;
	const char* c = str;
	while (*c != '\0') {
		// �������ؼ� ���ڿ��� �ƽ�Ű �ڵ带 ������ ��ȯ�Ѵ��� ����
		code += *c++;
	}
	return code;
}

// ���� : �ؽ��浹 �������
void hash_add(char* key, int value) {
	int idx = hash_function(key) % BUCKET_SIZE;
	keys[idx] = key;
	values[idx] = value;
}

// ���� : �ؽ��浹 �������
int hash_get(char* key) {
	int idx = hash_function(key) % BUCKET_SIZE;
	if (keys[idx] == 0) {
		return 0;
	}
	return values[idx];
}

int solution5(void) {
	hash_add("score", 90);
	hash_add("myage", 30);

	printf("%d\n", hash_get("score"));
	printf("%d\n", hash_get("myage"));
	printf("%d\n", hash_get("asdfef"));
}