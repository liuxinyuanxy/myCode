import sys
f = []
g = []
f.append(1)
g.append(1)
print("Input limitition:")
len = int(input())
print("Initiating...")
for i in range(1, len):
    if ((i - 1) % 3 == 0):
        f.append(2 * f[(i - 1) // 3])
    else:
        f.append(0)
    for j in range(0, i, 2):
        f[i] = f[i] + 3 * f[j // 2] * f[i - 1 - j]
    for j in range(0, i):
        f[i] = f[i] + g[j] * f[i - 1 - j]
    f[i] = f[i] // 6
    g.append(0)
    for j in range(0, i + 1):
        g[i] = g[i] + f[j] * f[i - j]
print("Initiated")
while 1:#什么？你想退出？你都会用Python了你不会退出？
    print("输入碳原子个数:")
    n = input()
    n = int(n)
    print(f[n])        