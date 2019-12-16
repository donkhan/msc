package udp;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.util.Date;

public class UDPClient {
    public static void main(String args[]) {
        new UDPClient().sayHi();
    }

    private void sayHi(){
        Date date = new Date();
        byte data[] = ("Hi Server My Time is "+ date.toString()).getBytes();
        try {
            DatagramPacket packet = new DatagramPacket(data,data.length,InetAddress.getLocalHost(),2000);
            DatagramSocket socket = new DatagramSocket();
            System.out.println("Sending Data to server. Data is " + new String(data));
            socket.send(packet);
            DatagramPacket rPacket = new DatagramPacket(new byte[2048],2048);
            socket.receive(rPacket);
            System.out.println("Received from "+ packet.getAddress() );
            System.out.println("Payload is  "+ new String(rPacket.getData()));
        }catch(SocketException se){
            se.printStackTrace();
        }catch(IOException ioe){
            ioe.printStackTrace();
        }


    }
}
