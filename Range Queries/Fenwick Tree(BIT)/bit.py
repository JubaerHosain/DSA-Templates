class BIT:
    def __init__(self, size):
        self.size = size
        self.tree = [0] * (size + 1)  # 1-based indexing

    def update(self, index, delta):
        while index <= self.size:
            self.tree[index] += delta
            index += index & -index 

    def prefix_sum(self, index):
        result = 0
        while index > 0:
            result += self.tree[index]
            index -= index & -index
        return result

    def range_sum(self, start, end):
        return self.prefix_sum(end) - self.prefix_sum(start-1)


bit = BIT(10)
bit.update(1, 5)
bit.update(3, 3)
bit.update(7, 2)
print("Sum of first 3 elements:", bit.range_sum(1, 3))  # Output: 8
print("Sum of first 7 elements:", bit.range_sum(1, 7))  # Output: 10
print("Sum of first 10 elements:", bit.range_sum(3, 10))  # Output: 5
