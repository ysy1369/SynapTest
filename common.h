#include <iostream>
using namespace std;

#define DATA_MAX 18

/* qsort() 메서드를 사용하기 위한  Compare 메서드 */
inline int myCompare(const void* _a, const void* _b) { 
	int a = (*(char*)_a) -'0';
	int b = (*(char*)_b) -'0';

	if(a<b)
		return -1;
	if(a==b)
		return 0;
	return 1;
}

/* 숫자 값이 입력된 char 배열을 단일 int로 변환 */
inline int myAtoI(char* arr, int arrSize) {
	
	int num = 0;

	for(int i=0; i<arrSize;i++) {
		num += arr[i]-'0';
		num *= 10;
	}
	num /= 10;

	return num;
}