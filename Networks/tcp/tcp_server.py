import socket
import sys

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to the port
server_address = ('localhost', 10000)
print ('starting up ',server_address)
sock.bind(server_address)

sock.listen(1)

while True:
    print('waiting for a connection')
    connection, client_address = sock.accept()
    try:
        print('connection from', client_address)
        f = open("R.txt", "w")
        # Receive the data in small chunks
        while True:
            data = connection.recv(200)
            if data:
                f.write(data.decode())
            else:
                break
        f.close()
    finally:
        # Clean up the connection
        connection.close()

