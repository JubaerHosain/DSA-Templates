from collections import deque
from queue import Queue
from sortedcontainers import SortedList, SortedSet

sl = SortedList([3, 5, 7, 9, 11])
print(sl)
print(2 in sl)
print(sl.bisect(7))
# print(sl.bisect_left(7))
# print(sl.bisect_left(6))
# print(sl.bisect_right(6))
# print(sl.bisect_right(7))

# print(sl.index(5))

# Create a SortedSet
sorted_set = SortedSet([1, 2, 3, 4, 5, 6, 7, 8, 9])

# Get minimum item (first element)
min_item = sorted_set[0]
# Get maximum item (last element)
max_item = sorted_set[-1]
print("minmax", min_item, max_item)

from sortedcontainers import SortedDict

# Create a SortedDict
sorted_dict = SortedDict({
    'apple': 1,
    'banana': 2,
    'cherry': 3,
    'date': 4
})

# Get minimum key (first key in the sorted order)
min_key = next(iter(sorted_dict))

# Get maximum key (last key in the sorted order)
max_key = next(reversed(sorted_dict))

# Get values associated with those keys
min_item = sorted_dict[min_key]
max_item = sorted_dict[max_key]

print(f"Minimum key: {min_key}, Value: {min_item}")
print(f"Maximum key: {max_key}, Value: {max_item}")
