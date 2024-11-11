import numpy as np

f = lambda x: 1/(1+x**2)

def trapezoidal(n, a, b):
    h = (b-a)/n
    x=np.arange(a,b+h,h)
    y=f(x)
    res = (h/2)*(y[0]+y[-1]+2*np.sum(y[1:n]))
    print(res)

def simpOneThird(n, a, b):
    h = (b-a)/n
    x=np.arange(a,b+h,h)
    y=f(x)
    res = (h/3)*(y[0]+y[-1]+4*np.sum(y[1:n:2])+2*np.sum(y[2:n-1:2]))
    print(res)

def simpThreeThird(n,a,b):
    h = (b-a)/n
    x=np.arange(a,b+h,h)
    y=f(x)
    res = (3*h/8)*(y[0]+y[-1]+3*np.sum(y[1:n])-np.sum(y[3:n-2:3]))
    print(res)

n = int(input())
a,b = map(float,input().split())
trapezoidal(n,a,b)
simpOneThird(n,a,b)
simpThreeThird(n,a,b)