def solve(n, q):
    a = [[0, 0] for _ in range(n)]
    b = [[0, 0] for _ in range(n)]
    c = [[0, 0] for _ in range(n)]
    d = [[0, 0] for _ in range(n)]
    
    ans = [0] * n
    for i in range(len(q)):
        val = q[i][1]
        ind = q[i][0]
        if ind < 0 or ind >= n or val <= 0:
            continue
        ans[ind] -= val
        a[max(0, ind - val)][0] += max(0, val - ind)
        a[max(0, ind - val)][1] += 1
        c[ind][0] = val
        c[ind][1] += 1
        b[min(ind + val, n - 1)][0] += max(0, val - n + 1 + ind)
        b[min(ind + val, n - 1)][1] += 1
        d[ind][0] = val
        d[ind][1] += 1

    cur = num = 0
    for i in range(n):
        cur += num
        cur += a[i][0]
        num += a[i][1]
        ans[i] += cur
        cur -= c[i][0]
        num -= c[i][1]

    cur = num = 0
    for i in range(n - 1, -1, -1):
        cur += num
        cur += b[i][0]
        num += b[i][1]
        ans[i] += cur
        cur -= d[i][0]
        num -= d[i][1]

    return ans


print(solve(3, [[2,6],[0,1],[1,2]]))
