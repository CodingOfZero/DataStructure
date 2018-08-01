/*
*KMP
*2018��8��1�� 17:08:34
*/
#include<iostream>
//�����㷨��ֻ�轫P��T�г���Ϊm��n-m+1���Ӵ���һ�ȶԣ�����ȷ�����ܵ�ƥ��λ��
int match(char *P,char *T) {
	int n = strlen(T), i = 0;	//�ı�������
	int m = strlen(P), j = 0;	//ģʽ������
	while (j < m&&i < n) 
	{
		if (P[j] == T[i])
		{
			i++;
			j++;
		}
		else
		{
			i -= j - 1;	//�ı������ˣ�ģʽ����λ
			j = 0;
		}
	}
	if (j >= m)	//����ƥ��ɹ��ĵ�һ���ַ����±�
		return i - j;
	else
		return -1;//ģʽƥ�䲻�ɹ�
}
int match_2(char *P, char *T) {
	int n = strlen(T), i = 0;	//�ı�������
	int m = strlen(P), j ;	//ģʽ������
	for (i = 0; i < n - m + 1; i++) {
		for (j = 0; j < m; j++)
			if (T[i + j] != P[j])
				break;
		if (j >= m)	break;
	}
	if (j >= m)	//����ƥ��ɹ��ĵ�һ���ַ����±�
		return i;
	else
		return -1;//ģʽƥ�䲻�ɹ�
}
//KMP��O(n+m)
/*
*N(P,j)={0<=t<j | P(0,t)==P(j-t,j)��P[j] != P[t]}
*��ǰ׺�����׺��ͬ����󳤶�,����Խ���ƶ�ԽСԽ��ȫ
*/
int *buildNext(char *P) {	
	int m = strlen(P), j = 0;//��������ָ��
	int *N = new int[m];
	int t = N[0] = -1;//ģʽ��ָ��
	while (j < m - 1)
	{
		if (0 > t || P[j] == P[t])
		{
			j++; t++;
			N[j] = (P[j] != P[t] ? t : N[t]);
		}
		else
			t = N[t];
	}
	return N;
}
int KMP_match(char *P, char *T) {
	int *next = buildNext(P);	//����next��
	int n = strlen(T), i = 0;
	int m = strlen(P), j = 0;
	while (j < m&&i < n)
	{
		if (0 > j || T[i] == P[j])//�����ڱ�ʹ�����������ϱ���Ϊƥ��ɹ�
		{
			i++;
			j++;
		}
		else
			j = next[j];//ģʽ������
	}
	delete[]next;
	if (j >= m)	//����ƥ��ɹ��ĵ�һ���ַ����±�
		return i - j;
	else
		return -1;//ģʽƥ�䲻�ɹ�
}
int main() {
//	char t[] = { 'a','b','c','a','r' };//����'\0'strlen���������
	char t[] = "abcarfdfdf";
	char p[] = "r";
	std::cout << match(p, t);
	std::cout << KMP_match(p, t)<<std::endl;
}
