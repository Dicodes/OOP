import java.io.*;
import java.util.*;
class List
{
	static void rlist(File file)
	{
		if(file.isDirectory())
		{
			//if(file.getName().charAt(0)=='L')
				System.out.println(file.getName());
			File paths[]=file.listFiles();
			for(File f:paths)
				rlist(f);
		}
		if(file.isFile())//&& file.getName().charAt(0)=='L')
			System.out.println(file.getName());
		if(file.getName().compareTo("File.txt")==0)
		{
			FileReader fr=null;
			FileWriter fw=null;
			try
			{
				fr=new FileReader("File.txt");
				if(fr==null)
					System.out.println("NOT OPEN!");
				BufferedReader br=new BufferedReader(fr);
				String str="",t;
				while((t=br.readLine())!=null)
				{
					str=str+" ";
					//System.out.print(t);
					t = t.replaceAll("Help","Make");
					//System.out.println(t);
					str=str+t+" ";
					
				}
				System.out.println(str);
				fw=new FileWriter("File.txt");
				BufferedWriter bw=new BufferedWriter(fw);
				bw.write(str);
				br.close();
				bw.close();
			}
			catch(IOException e)
			{
				System.out.println(e);
			}
		}
	}
	public static void main(String[] args) 
	{

		Scanner scr=new Scanner(System.in);
		File f=new File("/home/divya/Desktop/FileHandling");
		rlist(f);
			
	}
}