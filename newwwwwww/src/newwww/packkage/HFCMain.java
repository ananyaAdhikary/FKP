package newwww.packkage;

import java.util.PriorityQueue;

public class HFCMain {

	public static int count=0;
	
	public static void printcode(HFC root,String s)
	{
		
		if(root.left==null && root.right==null && Character.isLetter(root.c))
		{
			System.out.println(root.c + ":" +s);
			count=count+(s.length()*root.freq);
			return;
		}
		printcode(root.left,s+"0");
		printcode(root.right,s+"1");
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int n=6;
		int[] freq= {100,53,133,60,44,8};
		char[] letter= {'A','C','E','M','U','Z'};
		int totalfreq=0;
		
	
		PriorityQueue<HFC> q=new PriorityQueue<HFC>(n,new HFCComparator());	
		
		for(int i=0;i<n;i++)
		{
			HFC i1=new HFC();
			i1.c=letter[i];
			i1.freq=freq[i];
			i1.left=null;
			i1.right=null;
			q.add(i1);
			totalfreq+=freq[i]*8;

		}
		HFC root=null;
		while(q.size()>1)
		{
			HFC x=q.peek();
			q.poll();
			
			HFC y=q.peek();
			q.poll();
			
			HFC hn=new HFC();
			hn.c='_';
			hn.freq=x.freq+y.freq;
			hn.left=x;
			hn.right=y;
			root=hn;
			q.add(hn);
			
		}
		System.out.println("the huffman code are:");
		
		printcode(root," ");
		
		System.out.println("the compression length:"+count);
		System.out.println("Huffman code length:"+totalfreq);
		System.out.println("Compression percentage="+((totalfreq-count)*100/totalfreq)+"%");
		
	}

}
