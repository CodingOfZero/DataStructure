/*
*KMP
*2018年8月1日 17:08:34
*/
#include<iostream>
//蛮力算法：只需将P与T中长度为m的n-m+1个子串逐一比对，即可确定可能的匹配位置
int match(char *P,char *T) {
	int n = strlen(T), i = 0;	//文本串长度
	int m = strlen(P), j = 0;	//模式串长度
	while (j < m&&i < n) 
	{
		if (P[j] == T[i])
		{
			i++;
			j++;
		}
		else
		{
			i -= j - 1;	//文本串回退，模式串复位
			j = 0;
		}
	}
	if (j >= m)	//返回匹配成功的第一个字符的下标
		return i - j;
	else
		return -1;//模式匹配不成功
}
int match_2(char *P, char *T) {
	int n = strlen(T), i = 0;	//文本串长度
	int m = strlen(P), j ;	//模式串长度
	for (i = 0; i < n - m + 1; i++) {
		for (j = 0; j < m; j++)
			if (T[i + j] != P[j])
				break;
		if (j >= m)	break;
	}
	if (j >= m)	//返回匹配成功的第一个字符的下标
		return i;
	else
		return -1;//模式匹配不成功
}
//KMP：O(n+m)
/*
*N(P,j)={0<=t<j | P(0,t)==P(j-t,j)且P[j] != P[t]}
*真前缀和真后缀相同的最大长度,长度越大，移动越小越安全
*/
int *buildNext(char *P) {	
	int m = strlen(P), j = 0;//“主”串指针
	int *N = new int[m];
	int t = N[0] = -1;//模式串指针
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
	int *next = buildNext(P);	//构造next表
	int n = strlen(T), i = 0;
	int m = strlen(P), j = 0;
	while (j < m&&i < n)
	{
		if (0 > j || T[i] == P[j])//引入哨兵使得整体语义上表现为匹配成功
		{
			i++;
			j++;
		}
		else
			j = next[j];//模式串右移
	}
	delete[]next;
	if (j >= m)	//返回匹配成功的第一个字符的下标
		return i - j;
	else
		return -1;//模式匹配不成功
}
int main() {
//	char t[] = { 'a','b','c','a','r' };//不加'\0'strlen函数会出错
	char t[] = "abcarfdfdf";
	char p[] = "r";
	std::cout << match(p, t);
	std::cout << KMP_match(p, t)<<std::endl;
}
