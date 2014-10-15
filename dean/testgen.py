import numpy as np

num = 1
def add_test(n, t, d): # add params
    global num
    f = open('tests/' + str(num).zfill(3), 'w')
    # write f

    assert 1 <= n and n <= 1000000
    assert 1 <= len(d) and len(d) <= 1000000

    f.write('%d %d\n' % (n, len(d)))
    for i in xrange(len(t)):
        assert t[i] == 'S' or t[i] == 'D'
        assert 1 <= d[i][0] and d[i][0] <= n
        assert 1 <= d[i][1] and d[i][1] <= n
        f.write('%c %d %d\n' % (t[i], d[i][0], d[i][1]))
    f.close()
    print 'test', num, 'done'
    num += 1

def random_test(n1, n2, m):
    x = np.arange(n1 + n2) + 1
    np.random.shuffle(x)
    d = np.transpose(np.vstack([x[np.random.random_integers(0, n1 - 1, m)],
                                x[np.random.random_integers(n1, n1 + n2 - 1, m)]]))
    t = np.array(['S', 'D', 'D', 'D', 'D'])[np.random.random_integers(0, 4, m)]
    for i in xrange(m):
        if t[i] == 'S':
            d[i,:] = np.random.random_integers(1, n1 + n2, 2)

    add_test(n1 + n2, t, d)

def line_test(n):
    x = np.arange(n) + 1
    np.random.shuffle(x)

    d = np.transpose(np.vstack([x[:-1], x[1:]]))
    q = np.transpose(np.vstack([np.random.random_integers(1, n, 500000),
                                np.random.random_integers(1, n, 500000)]))
    d = np.vstack([d, q])
    t = np.hstack([np.array(['D']).repeat(n - 1), np.array(['S']).repeat(500000)])
    add_test(n, t, d)

random_test(10, 10, 20)
line_test(10)

random_test(1000, 1000, 20000)
random_test(1000, 1000, 20000)
random_test(1000, 1000, 20000)
random_test(1000, 1000, 20000)
random_test(100000, 500000, 1000000)
random_test(500000, 100000, 1000000)
random_test(50000, 50000, 1000000)
random_test(500000, 500000, 1000000)
random_test(500000, 500000, 1000000)
random_test(500000, 200000, 1000000)
random_test(500000, 200000, 1000000)
random_test(500000, 200000, 1000000)
random_test(500000, 200000, 1000000)
random_test(500000, 200000, 1000000)
random_test(500000, 500000, 1000000)
random_test(500000, 500000, 1000000)

line_test(500000)
line_test(200000)

