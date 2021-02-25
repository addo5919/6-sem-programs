import java.io.*;
import java.util.Scanner;

public class MainDemo {  //3 fields: account no(dt-long)-8 bytes , name(dt-String) -15x2 bytes , initials(dt-String) -3x2 bytes , balance(dt-float) -4 bytes
	static int record_size=48;
	static int name_chars=15;
	static int ini_chars=3;
	
	static long acno=0;
	static String name;
	static String ini;
	static float balance;
	static Scanner sc=new Scanner(System.in);
	
	static void writeString(RandomAccessFile file,String str,int fixed_char) throws IOException
	{
	 if(str.length()<=fixed_char)
	 {
	  file.writeChars(str);
	  for(int i=str.length();i<fixed_char;i++)
		 file.writeChar(' ');
	 }
	 else
	 {
	  file.writeChars(str.substring(0,fixed_char));
	 }
	}
	
	static String readString(RandomAccessFile file,int fixed_char) throws IOException
	{
	 String str="";
	 for(int i=0;i<fixed_char;i++)
	   str=str+file.readChar();
     return str;
	}

	public static void main(String args[]) throws IOException {
	
		RandomAccessFile file=new RandomAccessFile("file1.txt","rw");
		boolean f=true;
		int ch;
		
		while(f)
		{
		 System.out.println("MENU");
		 System.out.println("1.insert a record\n2.display all records\n3.exit");
		 System.out.println("Enter your choice:");
		 ch=sc.nextInt();
		 System.out.print("\n");
		 
		 if(ch==1)
		 {
		  acno++;
		  System.out.println("Enter the name:");
		  name=sc.next();
		  System.out.println("Enter the initials:");
		  ini=sc.next();
		  System.out.println("Enter the balance:");
		  balance=sc.nextFloat();
		  
		  long pos;
		  pos=(acno-1)*record_size;
		  file.seek(pos);
		  file.writeLong(acno);
		  writeString(file,name,name_chars);
		  writeString(file,ini,ini_chars);
		  file.writeFloat(balance);
		  
		 }
		 
		 if(ch==2)
		 {
		  file.seek(0);
		  int no_of_rec=(int)file.length()/record_size;
		  for(int i=0;i<no_of_rec;i++)
		  {
		   Long acctno=file.readLong();
		   name=readString(file,name_chars);
		   ini=readString(file,ini_chars);
		   balance=file.readFloat();
		   
		   System.out.println("Account no: "+acctno+"\nName: "+name+"\nInitial: "+ini+"\nBalance: "+balance);
		   System.out.print("\n");
		  }
		 }
		 
		 if(ch==3)
		 {
		  f=false;
		  file.close();
		 }

	}
	}
}


