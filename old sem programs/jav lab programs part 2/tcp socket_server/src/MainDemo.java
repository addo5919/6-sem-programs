import java.net.*;
import java.io.*;   //server program
import java.util.Scanner;

public class MainDemo {
	static ServerSocket servsock;

	public static void main(String args[]) {
		try
		{
		 servsock=new ServerSocket(1234);
		 System.out.println("Port opened");
		}
	    catch(IOException e)
		{
	     System.out.println("failed to open port");
	     System.exit(1);
		}
		
		do
		{
		 handleClient();
		}while(true);

	}
    
    static void handleClient()
    {
     Socket link=null;
     try
     {
      link=servsock.accept();
      Scanner input=new Scanner(link.getInputStream());
      PrintWriter output=new PrintWriter(link.getOutputStream(),true);
      
      String message=input.nextLine();
      int no_of_mes=0;
      while(!message.equals("****CLOSE****"))
      {
       no_of_mes++;
       System.out.println("Message recieved");
       output.println("Message "+no_of_mes+": "+message ); //echoes back client messages
       message=input.nextLine();
      }
      output.println("No of messages recieved: "+no_of_mes);
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
       System.out.println("Failed to close connection");
       System.exit(1);
      }
     }
    }
}
