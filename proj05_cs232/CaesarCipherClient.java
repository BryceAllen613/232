/**
* application for a client for a caesar cipher
* Bryce Allen
* project 5 cs 232 Calvin College, may 2019
*/
import java.util.Scanner;
import java.net.*;
import java.io.*;

public class CaesarCipherClient
{
  String serverName;
  int portNumber;
  Scanner keyboard;

  Socket mySocket;
  PrintWriter out;
  BufferedReader in;
  BufferedReader stdIn;

  /*
  * Constructor for the CaesarCipherClient class
  * @param String, the name of the machine the server is on
  * @param int, the port number for the server.
  */
  public CaesarCipherClient(String machineName, int num)
  {
    serverName = machineName;
    portNumber = num; 
    keyboard = new Scanner(System.in);

    try{
      mySocket = new Socket(machineName, portNumber);
      out = new PrintWriter(mySocket.getOutputStream(), true);
      in = new BufferedReader(new InputStreamReader(mySocket.getInputStream()));
      stdIn = new BufferedReader(new InputStreamReader(System.in));
    }
    catch (Exception e) 
    {
      System.out.println(e);
    }

  }

  /*
  * method that runs the echo behavior of the application
  */
  public void run()
  {
    String n = "";
    while(true)
    {
      System.out.println("enter a number 1-25: ");
      n = keyboard.next();
      try{
        if(Integer.parseInt(n) >= 1 && Integer.parseInt(n) <= 25)
        {
          out.println(Integer.parseInt(n));
          System.out.println("echo: " + in.readLine());
          break;
        }
        else
          System.out.println(n + " not echoed."); 
      }
      catch(Exception e)
      {
        System.out.println(e);
      }
    }

    while(!(n.equals("quit")))
    {
      System.out.println("enter a phrase to encrypt: ");
      n = keyboard.next();

      try{
        out.println(n);
        //System.out.println("here");
        System.out.println("echo: " + in.readLine());
      }catch(Exception e)
      {}
    }
  }

  /*
  * creates a CaesarCipherClient object and calls its run() method.
  * @param String[], holds the arguments passed in from the command line.
  */
  public static void main(String[] args)
  {
    System.out.println("Welcome to the Caesar Cipher!\n");
    CaesarCipherClient client = new CaesarCipherClient(args[0], Integer.parseInt(args[1]));
    client.run();
  }
}
