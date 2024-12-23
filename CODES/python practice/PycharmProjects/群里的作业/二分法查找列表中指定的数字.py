list1 = [1, 3, 4, 6, 7, 8, 9, 11, 15, 17, 19, 21, 22, 25, 29, 33, 38, 69, 107]


def binary_search(ls, target):
    left, right = 0, len(ls) - 1
    while left <= right:
        mid = (left + right) // 2
        mid_number = ls[mid]
        if mid_number == target:
            return mid + 1
        elif mid_number > target:
            return binary_search(ls[:mid], target)
        else:
            return binary_search(ls[mid+1:], target)
    return -1


index = binary_search(list1, 1)
print(index)
