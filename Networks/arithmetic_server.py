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
    tokens = data.decode().split(",")
    a = int(tokens[0])
    b = int(tokens[1])
    div = " Divide By Zero Not supported"
    if b != 0:
        div = str(a/b)
    response = "Add = " + str(a + b) + ", Sub = " + str(a-b) + " , Mul = " + str(a*b) + " , Div  = " + div
    if data:
        sent = sock.sendto(response.encode(), address)
        print('Sent ',sent,' bytes back to ' ,address)
