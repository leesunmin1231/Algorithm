def initMatrix(size):
    lst = [[0]*size for _ in range(size)]
    return lst

def add(A, B, size):
    ans = initMatrix(size)
    for i in range(size):
        for j in range(size):           
            ans[i][j] = A[i][j] + B[i][j]
    return ans

def minus(A, B, size):
    ans = initMatrix(size)
    for i in range(size):
        for j in range(size):
            ans[i][j] = A[i][j] - B[i][j]
    return ans

def strassen(A, B, size):
    if size == 1:
        c = initMatrix(1)
        c[0][0] = A[0][0] * B[0][0]
        return c
    c = initMatrix(size)
    subsize = size // 2

    A11 = initMatrix(subsize)
    A12 = initMatrix(subsize)
    A21 = initMatrix(subsize)
    A22 = initMatrix(subsize)
    B11 = initMatrix(subsize)
    B12 = initMatrix(subsize)
    B21 = initMatrix(subsize)
    B22 = initMatrix(subsize)

    for i in range(subsize):
        for j in range(subsize):
            A11[i][j] = A[i][j]
            A12[i][j] = A[i][subsize + j]
            A21[i][j] = A[subsize + i][j]
            A22[i][j] = A[subsize + i][subsize + j]

            B11[i][j] = B[i][j]
            B12[i][j] = B[i][subsize + j]
            B21[i][j] = B[subsize + i][j]
            B22[i][j] = B[subsize + i][subsize + j]
     
    P1 = strassen(A11, minus(B12, B22, subsize), subsize)
    P2 = strassen(add(A11, A12, subsize), B22, subsize)
    P3 = strassen(add(A21, A22, subsize), B11, subsize)
    P4 = strassen(A22, minus(B21, B11, subsize),subsize)
    P5 = strassen(add(A11, A22, subsize), add(B11, B22, subsize), subsize)
    P6 = strassen(minus(A12, A22, subsize), add(B21, B22, subsize), subsize)
    P7 = strassen(minus(A11, A21, subsize), add(B11, B12, subsize), subsize)

    C11 = minus(add(add(P5, P4, subsize), P6, subsize), P2, subsize)
    C12 = add(P1, P2, subsize)
    C21 = add(P3, P4, subsize)
    C22 = minus(minus(add(P5, P1, subsize), P3, subsize), P7, subsize)

    for i in range(subsize):
        for j in range(subsize):
            c[i][j] = C11[i][j]
            c[i][j + subsize] = C12[i][j]
            c[subsize + i][j] = C21[i][j]
            c[subsize + i][subsize + j] = C22[i][j]
    
    return (c)
    


A = [[1,1,1,1,1],[1,1,1,1,1]]
B = [[2,2,2,2,2],[2,2,2,2,2]]

print(strassen(A, B, 5))
