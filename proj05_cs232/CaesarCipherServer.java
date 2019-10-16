/**
* application for a server for a caesar cipher
* Bryce Allen
* project 5 cs 232 Calvin College, may 2019
*/
import java.util.Scanner;
import java.net.*;
import java.io.*;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.text.DateFormat;

/* class that spawns a new thread every time there is a connection
*/
public class CaesarCipherServer
{
    /* Constructor to create the server object
    * @param int, represents the port number to be used
    */
    public CaesarCipherServer(int number)
    { execute(number); }

    /* creates a new ServerThread and runs its run() method.
    * @param int, representing the port.
    */
    public void execute(int num)
    {
        try{
            ServerSocket currSocket = new ServerSocket(num);
            while(true)
            {
                CaesarCipherServerThread thread = new CaesarCipherServerThread(currSocket.accept());//.start();
                thread.start();
            }
        }catch(Exception e){ System.out.println(e); }
    }
    
    /* main method that generates a new CaesarCipherServer object with args[0]
    * representing the port number (from command line).
    */
    public static void main(String[] args)
    {
        CaesarCipherServer curr = new CaesarCipherServer(Integer.parseInt(args[0]));
    }
}

/* class that represents a new CaesarCipherServer thread
*/
class CaesarCipherServerThread extends Thread
{
    Socket clientSocket;
    String ipAddress;
    int rotateValue;
    /* Constructor made for the class, initializes all the above instance variables and prints
    * connection message.
    * @param Socket, a socket that represents the port to be used.
    */
    public CaesarCipherServerThread(Socket sock)
    {
        this.clientSocket = sock;
        ipAddress = this.clientSocket.getRemoteSocketAddress().toString();
        DateFormat df = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss");
        Date date = new Date();
        System.out.println("Connected to " + ipAddress + " on " + df.format(date));
    }
    /* creates new in and out streams for communicating with the client
    *recieves a number for the cipher and then echos it back to client
    * then echos back all encrypted phrases using an infinite loop.
    */
    public void run()
    {
        try{
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            
            rotateValue = Integer.parseInt(in.readLine());
            out.println(rotateValue);

            String str = in.readLine();
            while(true)
            {
                if(str.equals("quit"))
                    break;
                else
                {
                    out.println(cipher(str));
                    str = in.readLine();
                }
            }
            System.out.println("Closing connection to " + ipAddress);
            out.close();
            in.close();
            clientSocket.close();
        }catch(Exception e)
        {
            System.out.println(e);
        }
    }

    /* encrypts the input phrase
    * @param string, the string to be ciphered.
    * @return string, the ciphered string.
    */
    private String cipher(String s)
    {
        char[] alphabet = "abcdefghijklmnopqrstuvwxyz".toCharArray();
        char[] input = s.toCharArray();
        
        int pos = 0;
        String finalString = "";
        for( int i = 0; i < input.length; i++ )
        {
            if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
            {
                for( int j = 0; j < alphabet.length; j++ )
                {
                    if( alphabet[j] == input[i] )
                    {
                        pos = j;
                        break;
                    }
                }
                finalString += alphabet[(rotateValue+pos)%26];
            }
            else{ finalString += input[i]; }
        }
        return finalString;
    }
}
