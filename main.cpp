#include "Classes.h"

int main()
{
	int inputCnt =0;		//입력할 숫자의 개수를 저장하는 변수
	int result =0;			//최종 결과 값을 저장하는 변수
	bool canMakeSum =false;	//두 수의 합이 가능한지 여부를 저장하는 변수

	IOHandler ioh = IOHandler();		//입출력을 담당하는 객체 생성
	Calculator calc = Calculator();		//실제 계산과정을 담당하는 객체 생성

	/* 입력할 숫자의 개수를 입력 */
	inputCnt = ioh.inputCountAtCmd();
	calc.setInputCnt(inputCnt);

	/* 정해진 개수만큼의 숫자들을 입력 */
	canMakeSum = ioh.inputNumbersAtCmd(calc.getInputDataArr(), calc.getInputCnt());
	if(!canMakeSum)
		return 0;

	/* 계산 작업 */
	result = calc.calcProcess();

	/* 결과 출력 */
	ioh.viewResultAtCmd(result);

	return 0;
}


