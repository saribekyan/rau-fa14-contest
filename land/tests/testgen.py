import numpy as np

num = 1
def add_test(data, ans): # add params
    global num
    with open(str(num).zfill(3), 'w') as f:
        f.write('%d\n' % len(data))
        f.write('%d' % data[0])
        for i in data[1:]:
            f.write(' %d' % i)
        f.write('\n')

    with open(str(num).zfill(3) + '.a', 'w') as f:
        f.write('%d\n' % ans)
    print 'test', num, 'done'
    num += 1

data = []
with open('tax.in', 'r') as inp:
    while True:
        n, f = inp.readline().split()
        n = int(n)
        f = float(f)
        if n == 0:
            break
        data.append([n, f] + map(int, inp.readline().split()))

with open('tax.out', 'r') as out:
    for i in xrange(len(data)):
        a = float(out.readline().split()[0])
        data[i].append(a)

data = sorted(data)
for i in xrange(len(data) - 20, len(data)):
    add_test(data[i][2:-1], int(data[i][-1] / data[i][1]))

