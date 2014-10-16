import numpy as np

num = 2
def add_test(g): # add params
    global num
    a = np.arange(1, g[0] + 1)
    np.random.shuffle(a)
    b = np.arange(1, g[1] + 1)
    np.random.shuffle(b)
    np.random.shuffle(g[2])
    with open('tests/' + str(num).zfill(3), 'w') as f:
        f.write('%d %d %d\n' % (g[0], g[1], len(g[2])))
        for p in g[2]:
            f.write('%d %d\n' % (a[p[0] - 1], b[p[1] - 1]))
    print 'test', num, 'done'
    num += 1

def full(l, r):
    return (l, r, np.transpose(np.vstack([np.arange(1, l + 1).repeat(r), np.tile(np.arange(1, r + 1), l)])))

def empty(l, r):
    return (l, r, np.array([], dtype='int64'))

def concat(g1, g2):
    return (g1[0] + g2[0], g1[1] + g2[1], np.vstack([g1[2], np.transpose(np.vstack([g2[2][:, 0] + g1[0], g2[2][:, 1] + g1[1]]))]))

def random(l, r, m):
    return (l, r, np.transpose(np.vstack([np.random.random_integers(1, l, m), np.random.random_integers(1, r, m)])))

def path(n):
    return (n, n, 1 + np.transpose(np.vstack([np.arange(n).repeat(2)[:-1], np.arange(n).repeat(2)[1:]])))


add_test(path(5))
add_test(full(1, 1))
add_test(full(10, 10))
add_test(full(9, 10))
add_test(full(10, 9))
add_test(full(100, 99))
add_test(full(99, 100))
add_test(path(100))
add_test(concat(path(99), path(1)))

add_test(concat(full(50, 90), random(49, 10, 300)))
add_test(concat(full(60, 50), random(40, 50, 200)))

add_test(concat(concat(concat(concat(concat(random(10, 14, 20),  random(13, 10, 100)), full(15, 9)), random(21, 13, 1)), random(9, 10, 5)),   full(10, 20)))
add_test(concat(concat(concat(concat(concat(random(10, 14, 1000),  full(10, 13)),  random(9, 15, 1000)), random(13, 21, 900)), random(9, 10, 500)),  full(10, 20)))
add_test(concat(concat(concat(concat(concat(random(10, 14, 200), random(13, 10, 9)),   full(15, 9)), random(21, 13, 1)), random(9, 10, 50)),  full(10, 20)))
add_test(concat(concat(concat(concat(concat(path(10),  random(13, 10, 20)),  full(15, 9)), random(21, 13, 1)), random(9, 10, 100)), full(10, 20)))

add_test(concat(random(50, 50, 1000), random(40, 48, 500)))
add_test(concat(random(50, 50, 1000), random(40, 48, 500)))
add_test(concat(random(50, 50, 1000), random(40, 48, 500)))
add_test(concat(random(50, 50, 1000), random(40, 48, 500)))

add_test(concat(random(50, 50, 5000), random(40, 48, 3000)))
add_test(concat(full(50, 49), random(40, 48, 6000)))
add_test(concat(random(50, 39, 6000), random(40, 48, 3000)))
add_test(concat(random(50, 50, 3000), random(40, 48, 3000)))

add_test(empty(100, 100))
