import numpy as np
import math

def product_sum(val, terms):  
    total_sum = 0
    for i in range(terms):
        product = 1
        for j in range(terms):
            if i != j:
                product *= (val - j)
        total_sum += product
    return total_sum

def interpolate():
    x = np.array(list(map(float, input("Enter x values: ").split())))
    y = np.array(list(map(float, input("Enter y values: ").split())))
    x_val = float(input("Enter the value of x to estimate y: "))
    
    h = x[1] - x[0]
    s = (x_val - x[0]) / h
    n = len(x)
    
    difference_table = np.zeros((n, n))
    difference_table[:, 0] = y
    
    for col in range(1, n):
        for row in range(n - col):
            difference_table[row, col] = difference_table[row + 1, col - 1] - difference_table[row, col - 1]

    delta = difference_table[0]
    result = 0
    for order in range(1, n):
        result += delta[order] * product_sum(s, order) / math.factorial(order)

    result /= h
    print("The estimated value of the derivative at x =", x_val, "is:", result)

interpolate()