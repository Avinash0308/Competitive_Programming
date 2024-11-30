import sys


def solve(N, tree):
    v = [[0] * N for _ in range(N)]
    maxy = -sys.maxsize
    x, y = 0, 0
    for i in range(N):
        for j in range(i + 1, N):
            v[i][j] = abs(tree[i][0] - tree[j][0]) + abs(tree[i][1] - tree[j][1])
            v[j][i] = v[i][j]
            if maxy < v[j][i]:
                x, y = j, i
                maxy = v[j][i]

    a, b = 0, 0
    for i in range(N):
        for j in range(i + 1, N):
            if i != x and j != x:
                a = max(a, v[i][j])
            if i != y and j != y:
                b = max(b, v[i][j])

    return min(a, b)


# Test the function
v = [[1, 2], [2, 4], [2, 6], [3, 9], [2, 8]]
print(solve(5, v))
