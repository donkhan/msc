

def find_total_tracks(queue,head,tail=0):
    total_track = 0
    for track in queue:
        total_track += abs(track-head)
        head = track
    print total_track

def t1():
    queue = [98, 183, 37, 122, 14, 124, 65, 67]
    head = 53
    find_total_tracks(queue,head)

def t2():
    queue = [54, 95, 180, 34, 119, 11, 123, 62, 64 ,76 ]
    head = 50
    tail = 199
    find_total_tracks(queue,head,tail)

def t3():
    find_total_tracks([95, 180, 34, 119, 11, 123, 62, 64],50)

t3()