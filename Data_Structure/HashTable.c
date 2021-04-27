#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>

#define BUCKET_SIZE 23
char* keys[BUCKET_SIZE];
int values[BUCKET_SIZE];

// 매우 간략화한 해시함수 
int hash_function(const char* str)
{
	int code = 0;
	const char* c = str;
	while (*c != '\0') {
		// 역참조해서 문자열의 아스키 코드를 정수로 전환한다음 더함
		code += *c++;
	}
	return code;
}

// 주의 : 해시충돌 고려안함
void hash_add(char* key, int value) {
	int idx = hash_function(key) % BUCKET_SIZE;
	keys[idx] = key;
	values[idx] = value;
}

// 주의 : 해시충돌 고려안함
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