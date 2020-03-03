import socket
import sys

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = ('localhost', 10000)
ip = input("Enter IP ")

try:
    # Send data
    print('sending ', ip)
    sent = sock.sendto(ip.encode(), server_address)

    # Receive response
    print('waiting to receive')
    data, server = sock.recvfrom(4096)
    print( 'received ' , data.decode())

finally:
    print('closing socket')
    sock.close()