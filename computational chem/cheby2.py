import numpy as np

def f(x):
    return 1 / (1 + 16 * x**2)

def transform_interval(x, a, b):
    return (2*x-(a+b))/(b-a)



def chebyshev_nodes(n):
    cheb_nodes = np.zeros(n)
    for i in range(n):
        cheb_nodes[i] = np.cos((2 * i + 1) * np.pi / (2 * n))*5 # transformed by multiplying 5
        
    return cheb_nodes

def cheb_Ts(n, x):
    return np.cos(n * np.arccos(x))

def cheb_coeff(n):
    cheb_coff = np.zeros(n)
    cheb_node = chebyshev_nodes(n)
    print(cheb_node);
    for i in range(n):
        cheb_coff[0] += f(cheb_node[i]) 
    cheb_coff[0] /= n
    # print(cheb_coff[0])

    for j in range(1, n):
        for k in range(n):
            cheb_coff[j] += f(cheb_node[k]) * np.cos(j * np.pi * (2 * k + 1) / (2 * n))
        cheb_coff[j] = 2 * cheb_coff[j] / n
        # print(cheb_coff[j])
    return cheb_coff

def cheb_poly(n, x, a,b):
    c = cheb_coeff(n)
    ans = 0
    for i in range(n):
        ans += c[i] * cheb_Ts(i, transform_interval(x,a,b))
    return ans

# Example usage:
n = 20
x = 1.2
a=-5
b=5
print( cheb_poly(n, x, a,b))