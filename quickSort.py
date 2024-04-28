def quickSort(arr): 
   if len(arr) <= 1:
      return arr
   mid = arr[len(arr) // 2]
   left = [x for x in arr if x < mid]
   middle = [x for x in arr if x == mid]
   right = [x for x in arr if x > mid]

   return quickSort(left) + middle + quickSort(right)

arr = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
sorted_arr = quickSort(arr)
print("Sorted array:", sorted_arr)
