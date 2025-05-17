package newwww.packkage;

import java.util.Comparator;

public class HFCComparator implements Comparator<HFC>{

	@Override
	public int compare(HFC o1, HFC o2) {
		// TODO Auto-generated method stub
		return o1.freq-o2.freq;
	}

}
