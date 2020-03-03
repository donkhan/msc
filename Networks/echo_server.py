import socket

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# Bind the socket to the port
server_address = ('localhost', 10000)
print('server starting up... ')
sock.bind(server_address)

while True:
    print('\nwaiting to receive message')
    data, address = sock.recvfrom(4096)
    print("Length of Data = ", len(data)," Data = ",data.decode(), "From = ", address)
    if data:
        sent = sock.sendto(data, address)
        print('Sent ',sent,' bytes back to ' ,address)
