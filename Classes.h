#include "common.h"

class IOHandler;	// 입출력을 담당하는 클래스
class Calculator;	// 실제 계산과정을 담당하는 클래스


class IOHandler {
private:
public:
	/* CONSTRUCTOR & DESTRUCTOR */
	IOHandler(){}
	~IOHandler(){}

	int inputCountAtCmd();	// 입력할 숫자의 개수를 CMD창에서 입력
							//RETURN: 입력할 숫자의 개수
	bool inputNumbersAtCmd(char* inputArr, int arrSize);// 정해진 개수만큼 CMD창에서 숫자 입력
														//PARAMETER: 배열포인터, 배열크기
														//RETURN:두 수의 합 가능 여부

	void viewResultAtCmd(int result);	// 결과 값 출력
};

class Calculator {
private:

	int inputCnt;					//입력되는 숫자의 개수
	char inputDataArr[DATA_MAX];	//입력된 전체 값을 저장하는 배열

	/* 두 수를 담당하는 배열 */
	char num01[9];
	char num02[9];

	/* 두 수를 담당하는 배열을 컨트롤하는 Index 값 */
	int idxOfNum01;	
	int idxOfNum02;

public:
	/* CONSTRUCTOR & DESTRUCTOR */
	Calculator();
	~Calculator(){}

	/* SETTER & GETTER */
	void setInputCnt(int cnt) {
		inputCnt = cnt;
	}
	int getInputCnt() {
		return inputCnt;
	}
	char* getInputDataArr() {
		return inputDataArr;
	}

	/* OTHER METHODS */
	int calcProcess();	//실제 계산을 담당하는, 이 프로그램의 주요 메서드
};