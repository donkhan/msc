
def has(queue,element):
    for i in queue:
        if i == element:
            return True
    return False

def find_total_tracks(queue,head,tail=0):
    total_track = 0
    i_head = head
    while(head > 0):
        if has(queue,head):
            total_track += abs(head-i_head)
            print("Serviced ", head)
            queue.remove(head)
            i_head = head
        head = head - 1
    i_head = 0
    while (len(queue) > 0):
        if has(queue, head):
            total_track += abs(head-i_head)
            i_head = head
            print("Serviced ", head)
            queue.remove(head)
        head = head + 1
    print(total_track)

def t1():
    queue = [98, 183, 37, 122, 14, 124, 65, 67]
    head = 53
    find_total_tracks(queue,head)

def t2():
    queue = [54, 95, 180, 34, 119, 11, 123, 62, 64 ,76 ]
    head = 50
    tail = 199
    find_total_tracks(queue,head,tail)

#t1()
t2()