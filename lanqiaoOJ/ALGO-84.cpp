/** lanqiaoOJ ALGO-84 */

/** ��Сдת�� */

//��������
//������дһ����������һ���ַ��������Ȳ�����20����Ȼ�������ַ����ڵ�ÿһ���ַ����д�Сд�任��������д��ĸ���Сд��Сд��ĸ��ɴ�д��Ȼ�������µ��ַ��������
//���������ʽ������һ���ַ�������������ַ�������ֻ����Ӣ����ĸ���������������͵��ַ���Ҳû�пո�
//���������ʽ���������ת������ַ�����
//�����������
//��������
//AeDb
//�������
//aEdB

#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

int main(){
	char str[25];
	gets(str);
	for(int i = 0; i < strlen(str); i++){
		if(isupper(str[i])){
			str[i] = tolower(str[i]);
		}
		else{
			str[i] = toupper(str[i]);
		}
	}
	puts(str);
	return 0;
}
