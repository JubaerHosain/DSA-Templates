from queue import PriorityQueue 

class Item:
    def __init__(self, x: int, y: int, z: str) -> None:
        self.x = x
        self.y = y
        self.z = z

    def __lt__(self, other) -> bool:
        return self.y < other.y
    
    def __eq__(self, other) -> bool:
        return self.y == other.y
    
    def __str__(self) -> str:
        return f"({self.x}, {self.y}, {self.z})"
    
pq = PriorityQueue()
pq.put(Item(1, 2, "a"))
pq.put(Item(3, 4, "b"))
pq.put(Item(2, 3, "c"))
pq.put(Item(4, 2, "d"))
pq.put(Item(4, 2, "e"))

while not pq.empty():
    i = pq.get()
    print(i)

print("ended")