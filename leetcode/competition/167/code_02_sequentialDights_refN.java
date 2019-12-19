class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
		int sum=0;
    	List<Integer> list=new ArrayList<>();
		//ħ�Եĵط����� ���ֱ����ҵ���һ����ʼ���ֺͽ������ֵķ���
    	for(int k=1;k<=9;k++) {
    		sum=0;
	    	for(int i=k;i<=9;i++){
	    		sum=sum*10+i;
	    		if(sum>=low && sum<=high && !list.contains(sum)) {
	    			list.add(sum);
	    			int tmp=sum;
					//��ʵ�����󳤶�Ϊ�̶�len ��ʼֵλ��sum��ĩβ�������Ϊ9����һ������
					//�������ɹ̶����ȵ�˳���� ��1234 2345 3456 4567 6789���һ������Ϊ9��ʾ������ȵ����ֽ���
			    	while(tmp<=high && tmp%10+1<10) {
			    		int x=work(tmp,tmp%10+1);
			    		if(x<=high) list.add(x);
			    		tmp=x;
			    		if(tmp%10==9) break;
			    	}
	    		}
	    	}
    	}
    	Collections.sort(list);
    	return list;
    } 
    
	//�������ɹ̶����ȵ�˳���� ��x=1234 ��y= 5 ���շ���2345 
    private int work(int x,int y) {
    	int xx=0;
    	while(x>10) {
    		xx=xx*10+x%10;
    		x/=10;
    	}
    	//xx=xx*10+y;
    	int yy=0;
    	while(xx>0) {
    		yy=yy*10+xx%10;
    		xx/=10;
    	}
    	yy=yy*10+y;
    	return yy;
    }
}