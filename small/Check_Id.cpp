//from lanqiao-4-7

//  д�Ľ�Ϊ���������Ľ������������ 
//
//���⣺����Ʊ��
//    ĳ���ܵ�λ�·���ĳ��Ʊ�ݣ���Ҫ������ȫ���ջء�
//    ÿ��Ʊ����Ψһ��ID�š�ȫ������Ʊ�ݵ�ID���������ģ���ID�Ŀ�ʼ���������ѡ���ġ�
//    ��Ϊ������Ա�������¼��ID�ŵ�ʱ������һ�����������ĳ��ID�Ϻţ�����һ��ID�غš�
//    ���������ͨ����̣��ҳ��Ϻŵ�ID���غŵ�ID��
//    ����ϺŲ����ܷ�����������С�š�
//
//Ҫ�������������һ������N(N<100)��ʾ��������������
//���Ŷ���N�����ݡ�
//ÿ�����ݳ��Ȳ��ȣ����ÿո�ֿ������ɸ���������100������������������100000��
//ÿ����������һ��ID�š�
//
//Ҫ��������1�У�����������m n���ÿո�ָ���
//���У�m��ʾ�Ϻ�ID��n��ʾ�غ�ID

#include<iostream>

using namespace std;

int ID[100][100] = { 0 };

int main( ) {
	int N;
	cin >> N;
	
	int min_id = 1000000;
	for(int i = 0; i < N; i++) {
		for(int j = 0; ; j++) {
			cin >> ID[i][j];
			if(cin.get() == '\n'){
				break;
			}
			if( ID[i][j] < min_id ) {
				min_id = ID[i][j];
			}
		}
	}
	
	int break_id = 0, repeat_id = 0;
	bool temp_b = 0, temp_r = 0;
	
	for(int i = min_id + 1; ; i++) {
		temp_b = 0;
		if( !repeat_id ) {
			temp_r = 0;
		}
		for(int j = 0; j < N; j++) {
			for(int k = 0; ID[j][k] != 0; k++) {
				if( i == ID[j][k] ) {
					temp_b = 1;
					if( !repeat_id && !temp_r ) {
						temp_r = 1;
					}
					else if( temp_r ){
						repeat_id = i;
						break;
					}
					else break;
				}
			}
			if( temp_b && repeat_id ) break;
		}
		if( !temp_b ) {
			break_id = i;
		}
		if( break_id && repeat_id ) {
			break;
		}
	}
	
	cout << break_id << ' ' << repeat_id << endl;
	return 0;
}
