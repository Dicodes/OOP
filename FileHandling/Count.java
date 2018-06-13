import java.io.*;
import java.util.*;
class Count
{
	static void counting(String fileName)
	{
		try(FileReader fr=new FileReader(fileName); BufferedReader br=new BufferedReader(fr))
		{
			String str,num="";
			int numctr=0,chctr=0,wdctr=0,linectr=0;
			while((str=br.readLine())!=null)
			{
				linectr+=1;
				for(int i=0;i<str.length();i++)
				{
					char ch=str.charAt(i);
					chctr+=1;
					if(Character.isDigit(ch))
					{
						while(Character.isDigit(ch))
						{
							num=num+ch;
							i+=1;
							ch=str.charAt(i);
							chctr+=1;
						}
						i-=1;
						chctr-=1;
						numctr+=1;
					}
					else if(ch==' ')
						wdctr+=1;

				}

			}
			wdctr+=linectr;
			System.out.println("Lines: "+linectr);
			System.out.println("Numbers: "+numctr);
			System.out.println("Characters: "+chctr);
			System.out.println("Words: "+wdctr);

		}
		catch(IOException e)
		{
			System.out.println(e);
		}
	}
	public static void main(String args[])
	{
		if(args.length==0)
			System.out.println("No filename specified");
		else
			counting(args[0]);
	}
}