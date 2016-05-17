#include "Classes.h"

///////////////////////////////////////// IO_HANDLER - PUBLIC METHODS ////////////////////////////////////////////////
int IOHandler::inputCountAtCmd() {
	int inputCnt=0;

	while(1) {
		cout<<"�� ���� ���ڸ� �Է��Ͻðڽ��ϱ�?"<<endl;
		cout<<"�Է�: ";
		
		cin.clear();
		fflush(stdin);
		cin>>inputCnt;
		cin.ignore(1,'\n');

		if(2<=inputCnt && inputCnt<=18) {
			return inputCnt;
		}
		else {
			cout<<" [���!] ������ ������ ������ 2 �̻� 18 ������ �ڿ����Դϴ�. �ٽ� �Է����ֽʽÿ�."<<endl<<endl;
			system("pause");
			system("cls");
		}
	}
}

bool IOHandler::inputNumbersAtCmd(char* inputDataArr, int inputCnt) {

	int notZeroCnt = 0;	//0�� �ƴ� ������ ����

	cout<< inputCnt <<"���� ���ڸ� �Է����ֽʽÿ�."<<endl;
	cout<<"�Է�: ";

	cin.clear();
	fflush(stdin);

	for(int i=0; i<inputCnt ;i++) {

		
		cin>> inputDataArr[i];

		if('0'<=inputDataArr[i] && inputDataArr[i]<='9') {
			if(inputDataArr[i] != '0')
				notZeroCnt++;
		}
		else {
			cout<<" [���!] 0~9 ������ ������ �Է����ּ���."<<endl;
			system("pause");
			system("cls");


			inputDataArr[i] = '\0';
			i--;
			
			cout<<" ������� �Էµ� ��: " << inputDataArr <<endl;
			cout<<"�Է�: ";

			cin.clear();
			fflush(stdin);
		}
	}

	if(notZeroCnt <2) { //�� ���� ���� ���� �� ���� �����̸�, false ��ȯ
		cout << -1 <<endl;
		return false;
	}
	qsort(inputDataArr, inputCnt, sizeof(char), myCompare);

	return true;
}

void IOHandler::viewResultAtCmd(int result) {
	cout <<endl <<"��� ��: "<< result <<endl<<endl;
}

///////////////////////////////////////// CALCULATOR - PUBLIC METHODS ////////////////////////////////////////////////

Calculator::Calculator() {
	
		//��� �ʵ� �ʱ�ȭ �۾�

		inputCnt=0;
		idxOfNum01=0;
		idxOfNum02=0;

		memset(num01, 0x00, sizeof(char)*9);
		memset(num02, 0x00, sizeof(char)*9);
}

int Calculator::calcProcess() {

	bool numKind = true; //true: num01, false: num02

	/* �� �� */
	int number01 =0;
	int number02 =0;


	/* ù��° ���ڴ� 0�� �� �� ���� ������ ���� ���� �۾� */
	for(int i=0; i<inputCnt ;i++) {
		if(inputDataArr[i]!=0) {
			if(num01[0] == 0) {
				num01[0]=inputDataArr[i];	//0�� �ƴ� ���ڸ� num01 �迭�� ù° �ڸ��� ��ҿ� ����
				inputDataArr[i] = -1;		//����� inputDataArr �迭 ��Ҵ� -1 ����
			} else if(num02[0] == 0) {
				num02[0]=inputDataArr[i];	//0�� �ƴ� ���ڸ� num02 �迭�� ù° �ڸ��� ��ҿ� ����
				inputDataArr[i] = -1;		//����� inputDataArr �迭 ��Ҵ� -1 ����
				break;
			}
		}
	}
	
	/* ù��° ���ڸ� ������ ������ ���� �۾� */
	for(int i=0;i<inputCnt;i++) {
		if(inputDataArr[i]== -1)
			continue;

		if(numKind) {	//True: num01
			num01[++idxOfNum01] = inputDataArr[i];
			numKind=false;
		}
		else {			//False: num02
			num02[++idxOfNum02] = inputDataArr[i];
			numKind=true;
		}
	}

	/* �� ���� �����ϰ� �ִ� ������ char �迭�� int�� ��ȯ */
	number01 = myAtoI(num01, idxOfNum01+1);
	number02 = myAtoI(num02, idxOfNum02+1);


	return number01+number02;
}