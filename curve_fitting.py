import numpy as np
import matplotlib.pyplot as plt

def straight():
    x = np.array(list(map(float,input("Enter x values: ").split())))
    y = np.array(list(map(float,input("Enter y values: ").split())))
    sum_x = np.sum(x)
    sum_y = np.sum(y)
    xy = x*y
    sum_xy = np.sum(xy)
    xsquare = x*x
    sum_xsquare = np.sum(xsquare)

    n = x.size
    
    A = [
        [n, sum_x],
        [sum_x,sum_xsquare]
    ]
    B = [sum_y,sum_xy]

    solution = np.linalg.solve(A,B)
    a = solution[0]
    b = solution[1]
    print(a,b)
    y1 = a+b*x
    plt.plot(x,y)
    plt.plot(x,y1, linestyle="--", color='red')
    plt.xlabel("x")
    plt.ylabel("y")
    plt.legend()
    plt.show()

def parabolic():
    x = np.array(list(map(float,input("Enter x values: ").split())))
    y = np.array(list(map(float,input("Enter y values: ").split())))
    sum_x = np.sum(x)
    sum_y = np.sum(y)
    xy = x*y
    sum_xy = np.sum(xy)
    xsquare = x*x
    sum_xsquare = np.sum(xsquare)
    xcube = xsquare*x
    sum_xcube = np.sum(xcube)
    xfour = xsquare*xsquare
    sum_xfour = np.sum(xfour)
    xsquarey = xsquare*y
    sum_xsquarey = np.sum(xsquarey)  

    n = x.size
    
    A = [
        [n, sum_x, sum_xsquare],
        [sum_x,sum_xsquare, sum_xcube],
        [sum_xsquare, sum_xcube, sum_xfour]
    ]
    B = [sum_y,sum_xy, sum_xsquarey]

    solution = np.linalg.solve(A,B)
    a = solution[0]
    b = solution[1]
    c = solution[2]
    print(a,b,c)
    y1 = a+b*x+c*x*x
    plt.plot(x,y,'-o',label='table data')
    plt.plot(x,y1,'o', linestyle="--", color='red', label='fitted data')
    plt.xlabel("x")
    plt.ylabel("y")
    plt.legend()
    plt.show()

straight()
parabolic()
    

