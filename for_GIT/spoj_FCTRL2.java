
import java.util.*;
import java.math.*;
import java.io.*;
class example{	
	public static void main(String[] args)throws IOException{
		int m,t,j,i=1;
		String s;
		InputStreamReader isr=new InputStreamReader(System.in);
		BufferedReader br=new BufferedReader(isr);
		s=br.readLine();
		t=Integer.parseInt(s);
		while(true){
			if(i>t)
				break;
			s=br.readLine();
			j=Integer.parseInt(s);
			BigInteger fac= new BigInteger("1");
			for(m=2;m<=j;m++)
				fac=fac.multiply(BigInteger.valueOf(m));
			System.out.println(fac);
			i++;
		}
	}
}

