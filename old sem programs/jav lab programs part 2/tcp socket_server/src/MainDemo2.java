import java.net.*; 
import java.io.*;  //client program
import java.util.Scanner;

public class MainDemo2 {
	static InetAddress address;

	public static void main(String args[]) {
		
		try
		{
		 address=InetAddress.getLocalHost();
		 System.out.println("IP address of local host obtained");
		}catch(UnknownHostException e)
		{
		 System.out.println("Couldnt identify local host name");
		 System.exit(1);
		}
		
		connect_to_server();
	}

	static void connect_to_server()
	{
	 Socket link=null;
	 try
	 {
	  link=new Socket(address,1234);
	  Scanner input=new Scanner(link.getInputStream());
	  PrintWriter output=new PrintWriter(link.getOutputStream(),true);
	  Scanner sc=new Scanner(System.in);
	  String message,response;
	  do
	  {
	   System.out.println("Enter the message:");
	   message=sc.nextLine();
	   output.println(message);
	   response=input.nextLine();
	   System.out.println("SERvER--> "+response);
	  }while(!message.equals("****CLOSE****"));
	 
	 }catch(IOException e)
	 {
	  System.out.println("Exception!");
	  System.exit(1);
	 }
	 finally
	 {
	  try
	  {
	   link.close();
	   System.out.println("Connection closed");
	  }catch(IOException e)
	  {
	   System.out.println("Couldnt close the connection");
	   System.exit(1);
	  }
	 }
	}
}
