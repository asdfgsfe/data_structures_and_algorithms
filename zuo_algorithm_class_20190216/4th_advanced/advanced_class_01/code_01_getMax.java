
//解法1：用位运算来替代条件运算符；令a-b=c，通过位运算判断c的符号scA，
//正为1，负为0,scB为scA取反；则较大的数为a*scA+b*scB

//解法2：在1的基础上考虑溢出的问题，只有符号不同相减时可能产生溢出；
//因此判断a较大的情况为 a b符号不同，a为正数或者a b符号相同 a-b=c c的符号为正。

public class GetMax {
	//取反0-1,1-0
	public static int flip(int n) {
		//n其实只有1位 就是最低位 到这个地方
		//但是要考虑符号位 异或后符号位不变
		return (n^1);
	}
	
	//判断正负，正0，负1
	public static int sign(int n) {
		return flip((n>>31)&1);
	}
	
	public static int getMax1(int a,int b) {
		int c=a-b;
		int scA=sign(c);
		int scB=flip(scA);
		return a*scA+b*scB;//谁小scX就位0 另一个为1
	}
	 
	//防止a,b符号不同时相减溢出
	public static int getMax2(int a,int b) {
		int c=a-b;
		int sa=sign(a);
		int sb=sign(b);
		int sc=sign(c);
		int difSab=sa^sb; // ab符号是否不同 相同为0 不同为1
		int sameSab=flip(difSab); //ab符号是否相同 相同为1 不同为0
		int returnA=(difSab&sa)+(sameSab&sc);//a大的情况：ab符号不同时，a为正数；a b符号相同时不会溢出，c符号为正
		int returnB=flip(returnA); //取反
		return a*returnA+b*returnB;
 
	}
	
	public static void main(String[] args) {
		System.out.println(getMax2(2,1));
	}
}