from quick_sort import sort


def binary_search(low, high, key):

    if high >= low:
        mid = int(low + (high - low) / 2)

        if key == array[mid]:
            return mid

        elif key > array[mid]:
            return binary_search(mid, high, key)
        else:
            return binary_search(low, mid, key)
    else:
        return -1


array = [5, 23, 45, 34, 12, 4, 55, 43, 89, 99, 999]
sort(array)  # sort array using quick sort
key = 43
print(binary_search(0, len(array), key))
