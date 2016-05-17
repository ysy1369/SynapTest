#include <iostream>
using namespace std;

#define DATA_MAX 18

/* qsort() �޼��带 ����ϱ� ����  Compare �޼��� */
inline int myCompare(const void* _a, const void* _b) { 
	int a = (*(char*)_a) -'0';
	int b = (*(char*)_b) -'0';

	if(a<b)
		return -1;
	if(a==b)
		return 0;
	return 1;
}

/* ���� ���� �Էµ� char �迭�� ���� int�� ��ȯ */
inline int myAtoI(char* arr, int arrSize) {
	
	int num = 0;

	for(int i=0; i<arrSize;i++) {
		num += arr[i]-'0';
		num *= 10;
	}
	num /= 10;

	return num;
}