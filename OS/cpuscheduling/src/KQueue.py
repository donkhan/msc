class KQueue:
    def __init__(self):
        self.queue = []

    def push(self,obj):
        self.queue.append(obj)

    def pop(self):
        if len(self.queue) == 0:
            return None
        obj = self.queue[0]
        self.queue.remove(obj)
        return obj

    def empty(self):
        return len(self.queue) <= 0