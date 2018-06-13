import java.io.*;
class display
{
	public static void main(String args[])
	{
		FileReader fr=null;
		try
		{
			fr=new FileReader("File.txt");
			BufferedReader br=new BufferedReader(fr);
			String str;
			int i=0;
			while((str=br.readLine())!=null)
			{
				System.out.println(str);
				i+=1;

			}
			System.out.println("No. of lines="+i);
			br.close();
			
		}
		catch(IOException e)
		{
			System.out.println(e);
		}
		try
		{
			if(fr!=null)
				fr.close();
		}
		catch(IOException e)
		{
			System.out.println(e);
		}
	}
}