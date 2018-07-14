/*
*Hanoi��
*2018��7��8�� 11:21:36 
*/ 
void hanoi(int n,Stack<Disk> &sx,Stack<Disk> &sy,Stack<Disk> &sz){
	if(n>0)
	{
		hanoi(n-1,sx,sz,sy);//�ݹ飺��sx�ϵ�n-1ֻ���ӣ�����sz��ת���Ƶ�sy�� 
		move(sx,sz);		//ֱ�ӣ���sx�����һֻ���ӣ��Ƶ�sz�� 
		hanoi(n-1,sy,sx,sz); //�ݹ飺��sy�ϵ�n-1ֻ���ӣ�����sx���Ƶ�sz�� 
	}
}//O(2^n)
