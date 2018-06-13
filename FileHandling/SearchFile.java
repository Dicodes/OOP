import java.io.*;
class SearchFile
{
	static void search(String fileName,String wrd)
	{
		try(FileReader fr=new FileReader(fileName); BufferedReader br=new BufferedReader(fr))
		{
			int line=0;
			String str;
			while((str=br.readLine())!=null)
			{
				line+=1;
				if(str.contains(wrd))
				{
					System.out.println(line+":"+str);
				}

			}
		}
		catch(IOException e)
		{
			System.out.println(e);
		}
	}
	public static void main(String args[])
	{
		if(args.length!=2)
			System.out.println("Cannot perform operation");
		else
		{
			search(args[0], args[1]);
		}
	}
}