import socket
import sys

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect the socket to the port where the server is listening
server_address = ('localhost', 10000)
print('connecting to port ',server_address)
sock.connect(server_address)
file_name = "C:\\Users\\1MSC11.CSCCUTN.000\\PycharmProjects\\networks\\"
file_name = file_name + input("Enter File Name ")
print("Transfer the file ",file_name)
f = open(file_name, "r")

try:
    for line in f:
        sock.sendall(line.encode())
finally:
    sock.close()
