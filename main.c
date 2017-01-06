#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
void testconvert(char * str) {
	wchar_t * p = (wchar_t *) malloc(sizeof(wchar_t) * 100);
	memset(p, L'\0', sizeof(wchar_t) * 100);
	mbstowcs(p, str, sizeof(wchar_t) * 100);
	char * tmp = (char *) malloc(sizeof(char) * 20);
	char * tmp1;
	printf("testcc:%ls\n", p);
	while (*p != L'\0') {
		sprintf(tmp, "%x", *p);
		//将16进制字符串转为10进制的整型
		int n = (int) strtol(tmp, &tmp1, 16);
		printf("%s=%d\n", tmp, n);
		p++;
	}
}
int main() {
	setlocale(LC_ALL, "");
	//char *str = "http中国人民hello";
	char test[][100] = { "http中国人民hello" };
	testconvert(test[0]);
	return 1;
}
