/*
*Hanoi塔
*2018年7月8日 11:21:36 
*/ 
void hanoi(int n,Stack<Disk> &sx,Stack<Disk> &sy,Stack<Disk> &sz){
	if(n>0)
	{
		hanoi(n-1,sx,sz,sy);//递归：将sx上的n-1只盘子，借助sz中转，移到sy上 
		move(sx,sz);		//直接：将sx上最后一只盘子，移到sz上 
		hanoi(n-1,sy,sx,sz); //递归：将sy上的n-1只盘子，借助sx，移到sz上 
	}
}//O(2^n)
