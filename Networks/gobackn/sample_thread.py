import logging
import threading
import time

# N - Window Size
N = 5

def sender_thread(name):
    logging.info("Thread %s: starting", name)
    time.sleep(2)
    logging.info("Thread %s: finishing", name)

def receiver_thread(name):
    logging.info("Thread %s: starting", name)
    time.sleep(2)
    logging.info("%s: finishing", name)

if __name__ == "__main__":
    format = "%(asctime)s: %(message)s"
    logging.basicConfig(format=format, level=logging.INFO,
                        datefmt="%H:%M:%S")

    logging.info("Main    : before creating thread")
    sender = threading.Thread(target=sender_thread, args=("Sender",))
    receiver = threading.Thread(target=sender_thread, args=("Receiver",))
    sender.start()
    receiver.start()
    sender.join()
    receiver.join()
