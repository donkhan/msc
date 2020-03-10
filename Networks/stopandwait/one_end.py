import socket
import random


def create_socket():
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.settimeout(10)
    return sock

def send_data(sock,packet_size):
    try:
        message = str(packet_size)
        print('sending ', message, 'packets')
        sent = sock.sendto(message.encode(), ('localhost', 11000))
        print('waiting to receive')
        data, server = sock.recvfrom(4096)
        print('received ', data.decode())
    except :
        print("Not Received Acknowledgement")
        send_data(sock, packet_size)


def simulate(sock,times):
    i = 0
    try:
        while i < times:
            no_of_packets = random.randint(1,5)
            send_data(sock,no_of_packets)
            i = i  + 1
    finally:
        print('closing socket')
        sock.close()


def main():
    sock = create_socket()
    simulate(sock,100)

main()