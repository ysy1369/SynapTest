#include "Classes.h"

int main()
{
	int inputCnt =0;		//�Է��� ������ ������ �����ϴ� ����
	int result =0;			//���� ��� ���� �����ϴ� ����
	bool canMakeSum =false;	//�� ���� ���� �������� ���θ� �����ϴ� ����

	IOHandler ioh = IOHandler();		//������� ����ϴ� ��ü ����
	Calculator calc = Calculator();		//���� �������� ����ϴ� ��ü ����

	/* �Է��� ������ ������ �Է� */
	inputCnt = ioh.inputCountAtCmd();
	calc.setInputCnt(inputCnt);

	/* ������ ������ŭ�� ���ڵ��� �Է� */
	canMakeSum = ioh.inputNumbersAtCmd(calc.getInputDataArr(), calc.getInputCnt());
	if(!canMakeSum)
		return 0;

	/* ��� �۾� */
	result = calc.calcProcess();

	/* ��� ��� */
	ioh.viewResultAtCmd(result);

	return 0;
}


