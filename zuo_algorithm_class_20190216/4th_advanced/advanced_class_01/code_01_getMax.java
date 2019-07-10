
//�ⷨ1����λ����������������������a-b=c��ͨ��λ�����ж�c�ķ���scA��
//��Ϊ1����Ϊ0,scBΪscAȡ������ϴ����Ϊa*scA+b*scB

//�ⷨ2����1�Ļ����Ͽ�����������⣬ֻ�з��Ų�ͬ���ʱ���ܲ��������
//����ж�a�ϴ�����Ϊ a b���Ų�ͬ��aΪ��������a b������ͬ a-b=c c�ķ���Ϊ����

public class GetMax {
	//ȡ��0-1,1-0
	public static int flip(int n) {
		//n��ʵֻ��1λ �������λ ������ط�
		//����Ҫ���Ƿ���λ �������λ����
		return (n^1);
	}
	
	//�ж���������0����1
	public static int sign(int n) {
		return flip((n>>31)&1);
	}
	
	public static int getMax1(int a,int b) {
		int c=a-b;
		int scA=sign(c);
		int scB=flip(scA);
		return a*scA+b*scB;//˭СscX��λ0 ��һ��Ϊ1
	}
	 
	//��ֹa,b���Ų�ͬʱ������
	public static int getMax2(int a,int b) {
		int c=a-b;
		int sa=sign(a);
		int sb=sign(b);
		int sc=sign(c);
		int difSab=sa^sb; // ab�����Ƿ�ͬ ��ͬΪ0 ��ͬΪ1
		int sameSab=flip(difSab); //ab�����Ƿ���ͬ ��ͬΪ1 ��ͬΪ0
		int returnA=(difSab&sa)+(sameSab&sc);//a��������ab���Ų�ͬʱ��aΪ������a b������ͬʱ���������c����Ϊ��
		int returnB=flip(returnA); //ȡ��
		return a*returnA+b*returnB;
 
	}
	
	public static void main(String[] args) {
		System.out.println(getMax2(2,1));
	}
}