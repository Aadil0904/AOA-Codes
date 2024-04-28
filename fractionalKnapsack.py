def fractionalKnapsack(W, arr):
    arr.sort(key=lambda x: (x[0]/x[1]), reverse=True)
    finalvalue = 0.0
    for item in arr:
        if item[1] <= W:
            W -= item[1]
            finalvalue += item[0]
        else:
            finalvalue += item[0] * W / item[1]
            break
    return finalvalue

W = 4
arr = [(3, 1), (2, 2), (1, 3)]

max_val = fractionalKnapsack(W, arr)
print(max_val)
