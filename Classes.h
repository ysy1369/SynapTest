#include "common.h"

class IOHandler;	// ������� ����ϴ� Ŭ����
class Calculator;	// ���� �������� ����ϴ� Ŭ����


class IOHandler {
private:
public:
	/* CONSTRUCTOR & DESTRUCTOR */
	IOHandler(){}
	~IOHandler(){}

	int inputCountAtCmd();	// �Է��� ������ ������ CMDâ���� �Է�
							//RETURN: �Է��� ������ ����
	bool inputNumbersAtCmd(char* inputArr, int arrSize);// ������ ������ŭ CMDâ���� ���� �Է�
														//PARAMETER: �迭������, �迭ũ��
														//RETURN:�� ���� �� ���� ����

	void viewResultAtCmd(int result);	// ��� �� ���
};

class Calculator {
private:

	int inputCnt;					//�ԷµǴ� ������ ����
	char inputDataArr[DATA_MAX];	//�Էµ� ��ü ���� �����ϴ� �迭

	/* �� ���� ����ϴ� �迭 */
	char num01[9];
	char num02[9];

	/* �� ���� ����ϴ� �迭�� ��Ʈ���ϴ� Index �� */
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
	int calcProcess();	//���� ����� ����ϴ�, �� ���α׷��� �ֿ� �޼���
};