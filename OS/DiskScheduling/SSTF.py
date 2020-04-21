def find_closest(queue,head):
    min = 100000
    min_track = -1
    for track in queue:
        if abs(head-track) < min:
            min = abs(head-track)
            min_track = track
    return min_track


def find_total_tracks(queue,head,tail=0):
    total_track = 0
    while(len(queue) > 0):
        min_track = find_closest(queue,head)
        total_track += abs(head-min_track)
        print(min_track, total_track)
        head = min_track
        queue.remove(min_track)
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
#t2()
find_total_tracks([95, 180, 34, 119, 11, 123, 62, 64],50)