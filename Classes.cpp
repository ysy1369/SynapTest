#include "Classes.h"

///////////////////////////////////////// IO_HANDLER - PUBLIC METHODS ////////////////////////////////////////////////
int IOHandler::inputCountAtCmd() {
	int inputCnt=0;

	while(1) {
		cout<<"몇 개의 숫자를 입력하시겠습니까?"<<endl;
		cout<<"입력: ";
		
		cin.clear();
		fflush(stdin);
		cin>>inputCnt;
		cin.ignore(1,'\n');

		if(2<=inputCnt && inputCnt<=18) {
			return inputCnt;
		}
		else {
			cout<<" [경고!] 숫자의 개수의 범위는 2 이상 18 이하의 자연수입니다. 다시 입력해주십시오."<<endl<<endl;
			system("pause");
			system("cls");
		}
	}
}

bool IOHandler::inputNumbersAtCmd(char* inputDataArr, int inputCnt) {

	int notZeroCnt = 0;	//0이 아닌 숫자의 개수

	cout<< inputCnt <<"개의 숫자를 입력해주십시오."<<endl;
	cout<<"입력: ";

	cin.clear();
	fflush(stdin);

	for(int i=0; i<inputCnt ;i++) {

		
		cin>> inputDataArr[i];

		if('0'<=inputDataArr[i] && inputDataArr[i]<='9') {
			if(inputDataArr[i] != '0')
				notZeroCnt++;
		}
		else {
			cout<<" [경고!] 0~9 사이의 정수를 입력해주세요."<<endl;
			system("pause");
			system("cls");


			inputDataArr[i] = '\0';
			i--;
			
			cout<<" 현재까지 입력된 값: " << inputDataArr <<endl;
			cout<<"입력: ";

			cin.clear();
			fflush(stdin);
		}
	}

	if(notZeroCnt <2) { //두 수의 합을 구할 수 없는 상태이면, false 반환
		cout << -1 <<endl;
		return false;
	}
	qsort(inputDataArr, inputCnt, sizeof(char), myCompare);

	return true;
}

void IOHandler::viewResultAtCmd(int result) {
	cout <<endl <<"결과 값: "<< result <<endl<<endl;
}

///////////////////////////////////////// CALCULATOR - PUBLIC METHODS ////////////////////////////////////////////////

Calculator::Calculator() {
	
		//멤버 필드 초기화 작업

		inputCnt=0;
		idxOfNum01=0;
		idxOfNum02=0;

		memset(num01, 0x00, sizeof(char)*9);
		memset(num02, 0x00, sizeof(char)*9);
}

int Calculator::calcProcess() {

	bool numKind = true; //true: num01, false: num02

	/* 두 수 */
	int number01 =0;
	int number02 =0;


	/* 첫번째 숫자는 0이 올 수 없기 때문에 먼저 따로 작업 */
	for(int i=0; i<inputCnt ;i++) {
		if(inputDataArr[i]!=0) {
			if(num01[0] == 0) {
				num01[0]=inputDataArr[i];	//0이 아닌 숫자를 num01 배열의 첫째 자리의 요소에 대입
				inputDataArr[i] = -1;		//사용한 inputDataArr 배열 요소는 -1 대입
			} else if(num02[0] == 0) {
				num02[0]=inputDataArr[i];	//0이 아닌 숫자를 num02 배열의 첫째 자리의 요소에 대입
				inputDataArr[i] = -1;		//사용한 inputDataArr 배열 요소는 -1 대입
				break;
			}
		}
	}
	
	/* 첫번째 숫자를 제외한 나머지 숫자 작업 */
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

	/* 두 수를 저장하고 있는 각각의 char 배열을 int로 변환 */
	number01 = myAtoI(num01, idxOfNum01+1);
	number02 = myAtoI(num02, idxOfNum02+1);


	return number01+number02;
}