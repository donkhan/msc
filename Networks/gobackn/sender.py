import logging
import threading
import time
import socket

N = 5
acks = []
pointers = [0,0]

def sender_thread(name,data):
    logging.info("Thread %s: starting", name)
    logging.info("Data %s",data)
    pointer = pointers[0]
    ack_pointer = pointers[1]

    while pointer < len(data):
        while pointer - ack_pointer >= N:
            time.sleep(2)
        logging.info("sending packet %s ", data[pointer])
        sent = sock.sendto(data[pointer].encode(),  ('localhost', 10000))
        pointer = pointer + 1
    logging.info("Thread %s: finishing", name)

def receiver_thread(name,data):
    data_len = len(data)
    logging.info("Thread %s: starting", name)
    ack_pointer = pointers[1]
    while True:
        data, address = sock.recvfrom(4096)
        logging.info(" data from server %s ",data)
    logging.info("%s: finishing", name)

if __name__ == "__main__":
    format = "%(asctime)s: %(message)s"
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.settimeout(3)
    data = []
    for i in range(1,1000):
        data.append("Packet " + str(i))

    logging.basicConfig(format=format, level=logging.INFO,
                        datefmt="%H:%M:%S")

    logging.info("Main    : before creating thread")
    sender = threading.Thread(target=sender_thread, args=("Sender",data))
    receiver = threading.Thread(target=receiver_thread, args=("Receiver",data))
    sender.start()
    receiver.start()
    sender.join()
    receiver.join()
