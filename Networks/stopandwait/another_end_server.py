import socket
import random

def process(sock):
    while True:
        print('\nwaiting to receive message')
        data, address = sock.recvfrom(4096)
        print("Length of Data = ", len(data)," Data = ",data.decode(), "From = ", address)
        r = random.randint(0,5)
        print(r)
        if r == 1:
            print("Not Sending Acknowledgement")
            continue
        if data:
            print("Sending...")
            sent = sock.sendto(data, address)
            print('Sent ',sent,' bytes back to ' ,address)

def create_socket():
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_address = ('localhost', 11000)
    print('server starting up... ')
    sock.bind(server_address)
    return sock

sock = create_socket()
process(sock)