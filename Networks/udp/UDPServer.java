package udp;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.util.Date;

public class UDPServer {

    public static void main(String args[]) {
        new UDPServer().startServer();
    }

    private void handlePacket(DatagramSocket socket,DatagramPacket packet){
        System.out.println("Received from "+ packet.getAddress().getHostName());
        System.out.println(" PayLoad : "+ new String(packet.getData()));
        System.out.println("------------------------------------------------------");
        Date date = new Date();
        byte data[] = ("Hi " +  packet.getAddress() +" Server Time is "+ date.toString()).getBytes();
        try{
            System.out.println("Sending back " + new String(data));
            packet = new DatagramPacket(data, data.length, packet.getAddress(), packet.getPort());
            socket.send(packet);
        }catch(SocketException se){
            se.printStackTrace();
        }catch(IOException ioe){
            ioe.printStackTrace();
        }
    }

    private void startServer(){
        byte buffer[] = new byte[1024];
        try {
            DatagramSocket socket = new DatagramSocket(2000);
            DatagramPacket packet = new DatagramPacket(buffer,buffer.length);
            System.out.println("Server Started....");
            while(true) {
                socket.receive(packet);
                handlePacket(socket,packet);
            }
        }catch(SocketException se){
            se.printStackTrace();
        }catch(IOException ioe){
            ioe.printStackTrace();
        }
    }

}
