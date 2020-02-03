import socket

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# Bind the socket to the port
server_address = ('localhost', 10000)
print('server starting up... ')
sock.bind(server_address)
map = {}

f = open("dns_map.txt")
for line in f:
    line = line.replace("\n","")
    tokens = line.split("=")
    map[tokens[0]] = tokens[1]


while True:
    print('\nwaiting to receive message')
    data, address = sock.recvfrom(4096)
    print("Length of Data = ", len(data)," Data = ",data.decode(), "From = ", address)

    response = map.get(data.decode())
    if response is None:
        response = " Host name not found for " + data.decode()
    sent = sock.sendto(response.encode(), address)
    print('Sent ',sent,' bytes back to ' ,address)
