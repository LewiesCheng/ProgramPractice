/** lanqiaoOJ ALGO-79 */
//ɾ��������Ԫ�� 
 
//�Ӽ��̶���n���������������У���д����CompactIntegers��ɾ������������ֵΪ0��Ԫ�أ����Ԫ���������׶��ƶ���ע�⣬CompactIntegers������Ҫ�������鼰��Ԫ�ظ�����Ϊ��������������ֵӦΪɾ������ִ�к��������Ԫ�ظ��������ɾ����������Ԫ�صĸ����������������Ԫ�ء�
//��������: �������ʽ˵����5Ϊ�������ݵĸ�����3 4 0 0 2 ���Կո������5��������
//5 
//3 4 0 0 2
//�������:�������ʽ˵����3Ϊ�������ݵĸ�����3 4 2 ���Կո������3������������
//3
//3 4 2
//��������: 
//7
//0 0 7 0 0 9 0
//�������:
//2
//7 9
//��������: 
//3
//0 0 0
//�������:
//0


#include<iostream>

using namespace std;

int CompactIntegers (int * num, int n){
	int count = 0;
	for(int i = 0; i < n; i++){
		if(num[i] == 0){
			continue;
		}
		else{
			num[count] = num[i];
			++count;
		}
	}
	return count;
}

int main(){
	int n;
	cin >> n;
	int * num = new int[n];
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	int Count = CompactIntegers(num, n);
	cout << Count << endl;
	for(int i = 0; i < Count; i++){
		cout << num[i] << " ";
	}
	return 0;
}
