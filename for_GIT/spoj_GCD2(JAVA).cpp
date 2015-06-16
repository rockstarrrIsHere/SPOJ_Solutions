/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		    int t;
		    /*InputStreamReader isr=new InputStreamReader(System.in);
		    BufferedReader br=new BufferedReader(isr);*/
		    Scanner sc=new Scanner(System.in);
		    int i;
		    t=sc.nextInt();
		    for(i=1;i<=t;i++){
				BigInteger b1,b2,c,m,lol;
				lol=BigInteger.valueOf(0);
		    	b1=sc.nextBigInteger();
		    	b2=sc.nextBigInteger();
		    	while(true){
		    		if(b2.equals(lol)){
		    			c=b1;
		    			break;
		    		}
		    		m=b2;
		    		b2=b1.mod(b2);
		    		b1=m;
		    	}

		    	System.out.println(c);

		    }

	}
}
