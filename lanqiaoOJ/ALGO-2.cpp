/**  lanqiaoOJ ALGO-2 */
// the  maximum  of  minimum common multiple

//��������
//��֪һ��������N���ʴ�1~N����ѡ�������������ǵ���С������������Ϊ���١�
//
//�����ʽ
//����һ��������N��
//
//�����ʽ
//���һ����������ʾ���ҵ�����С��������
//��������
//9
//�������
//504
//���ݹ�ģ��Լ��
//1 <= N <= 106��


#include <cstdio> 

int main(){
	double N;
	scanf("%lf",&N);
	int n = N;
	if(n % 2){
		printf("%.0f",N * (N-1) * (N-2));
	}
	else{
		if(n % 3){
			printf("%.0f",N * (N-1) * (N-3));
		}
		else{
			printf("%.0f",(N-1) * (N-2) * (N-3));
		}
			
	}
	return 0;
}
