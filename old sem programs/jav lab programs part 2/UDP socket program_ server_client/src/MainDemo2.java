import java.net.*;
import java.io.*;
import java.util.Scanner;

public class MainDemo2 {   //client program
	static DatagramSocket ds;
	static DatagramPacket inp,outp; //p- packet
	static byte buffer[];
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
		
		accessServer();
	}
	
	static void accessServer()
	{
		try
		{
		 Scanner sc=new Scanner(System.in);
		 ds=new DatagramSocket();
		 String message;
		 buffer=new byte[256];
		 do
		 {
		  System.out.println("Enter a message:");
		  message=sc.nextLine();
		  buffer=message.getBytes();
		  outp=new DatagramPacket(buffer,buffer.length,address,1234);
		  ds.send(outp);
		  
		  byte b[]=new byte[256];
		  inp=new DatagramPacket(b,b.length);
		  ds.receive(inp);
		  String response=new String(inp.getData(),0,inp.getLength());
		  System.out.println("SERVER--> "+response);
		  
		 }while(!message.equals("****CLOSE****"));
		 
		}catch(IOException e)
		{
		 System.out.println("Exception!");
		}
		finally
		{
		 ds.close();
		 System.out.println("Port closed");
		}
		
	}


	}


