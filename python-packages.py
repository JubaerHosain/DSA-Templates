from collections import deque
from queue import Queue
from sortedcontainers import SortedList

sl = SortedList([3, 5, 7, 9, 11])
print(sl)
print(2 in sl)
print(sl.bisect(7))
print(sl.bisect_left(7))
print(sl.bisect_left(6))
print(sl.bisect_right(6))
print(sl.bisect_right(7))

print(sl.index(5))