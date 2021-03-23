def solve(p, t, A):
    if(t - A[p] == 0):
        return True
    elif(t - A[p] > 0):
        return False
    else:
        return solve(p+1, t - A[p], A)
