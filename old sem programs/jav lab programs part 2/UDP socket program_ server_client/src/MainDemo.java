import java.io.*;  
import java.net.*;             
import java.util.Scanner;

public class MainDemo {        //server program
	static DatagramSocket ds;
	static DatagramPacket inp,outp; //p- packet
	static byte buffer[];

	public static void main(String args[]) {
		try
		{
		 ds=new DatagramSocket(1234);
		 System.out.println("port opened");
		}catch(SocketException e)
		{
	     System.out.println("Couldnt open port");
	     System.exit(1);
		}
       
		handleClient();
	}
	
	static void handleClient()
	{
	 try
	 {
	  int no_of_mes=0;
	  do
	  {
	  buffer=new byte[256];
	  inp=new DatagramPacket(buffer,buffer.length);
	  ds.receive(inp);
	  System.out.println("\nMessage Recieved");
	  String message=new String(inp.getData(),0,inp.getLength());
	  
	 
	  no_of_mes++;
	  String message2="Message "+no_of_mes+": "+message;
	  byte b[]=new byte[256];
	  b=message2.getBytes();
	  outp=new DatagramPacket(b,b.length,inp.getAddress(),inp.getPort());
	  ds.send(outp);
	 }while(true);
	}catch(IOException e)
	 {
	 System.out.println("Exception!");
	 }
    finally
    {
     ds.close();
     System.out.println("port closed");
    }
}
}
