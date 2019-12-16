#in python there are 3 types data collection
#1.List  []
#2.Tuple    ()
#3.Dictonaries {}

#array is another type of data collectiion
import array as arr
a = arr.array('i', [2, 4, 6, 8])
print("First element:", a[0])
print("Second element:", a[1])
print("Last element:", a[-1])

numbers_list = [2, 5, 62, 5, 42, 52, 48, 5]
numbers_array = arr.array('i', numbers_list)
print(numbers_array[2:5]) # 3rd to 5th
print(numbers_array[:-5]) # beginning to 4th
print(numbers_array[5:])  # 6th to end
print(numbers_array[:])   # beginning to end

# append and extend
numbers = arr.array('i', [1, 2, 3])
numbers.append(4)
print(numbers)     # Output: array('i', [1, 2, 3, 4])
# extend() appends iterable to the end of the array
numbers.extend([5, 6, 7]) 
print(numbers)     # Output: array('i', [1, 2, 3, 4, 5, 6, 7])
