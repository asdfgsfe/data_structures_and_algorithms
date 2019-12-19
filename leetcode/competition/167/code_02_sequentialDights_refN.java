class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
		int sum=0;
    	List<Integer> list=new ArrayList<>();
		//魔性的地方在于 这种遍历找到第一个开始数字和结束数字的方法
    	for(int k=1;k<=9;k++) {
    		sum=0;
	    	for(int i=k;i<=9;i++){
	    		sum=sum*10+i;
	    		if(sum>=low && sum<=high && !list.contains(sum)) {
	    			list.add(sum);
	    			int tmp=sum;
					//其实就是求长度为固定len 起始值位置sum到末尾数字最大为9的这一段数字
					//用于生成固定长度的顺序数 如1234 2345 3456 4567 6789最后一个数字为9表示这个长度的数字结束
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
    
	//用于生成固定长度的顺序数 如x=1234 则y= 5 最终返回2345 
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