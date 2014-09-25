import numpy as np

num = 1
def add_test(s, queries): # add params
    global num
    f = open('tests/' + str(num).zfill(3), 'w')

    s = ''.join([str(int(i)) for i in s])
    f.write('%s\n' % s)
    f.write('%d\n' % len(queries))
    for query in queries:
        f.write('%d %d\n' % (query[0], query[1]))

    f.close()
    print 'test', num, 'done'
    num += 1

def rand_queries(n, m):
    queries = np.vstack([np.random.random_integers(0, n-1, m),
                         np.random.random_integers(0, n-1, m)])
    return np.transpose(queries)

def first_line(n, m):
    s = (np.random.randn(n) < 0.5)
    queries = np.transpose(np.vstack([np.zeros(n), np.arange(n)]))
    add_test(s, queries)

def random_test(n, m, one_ratio):
    s = (np.random.randn(n) < one_ratio)
    queries = rand_queries(n, m)
    add_test(s, queries)

def zero_then_one(n0, n1, m):
    s = np.hstack([np.zeros(n0), np.ones(n1)])
    queries = rand_queries(n1 + n0, m)
    add_test(s, queries)

def one_then_zero(n1, n0, m):
    s = np.hstack([np.ones(n1), np.zeros(n0)])
    queries = rand_queries(n0 + n1, m)
    add_test(s, queries)

random_test(    10,     10,     0.5)
random_test(    10,    100,      -1) # all zeros
random_test(    10,    100,       2) # all ones
random_test(  1000,   1000,     0.5)
random_test(  1000,   1000,     0.5)
random_test(100000, 100000,     0.7)
random_test(100000, 100000,     0.3)
random_test(100000, 100000,     0.8)
random_test(100000, 100000,     0.5)
random_test(100000, 100000,     0.5)
random_test(100000, 100000,     0.5)
random_test(100000, 100000,     0.5)
random_test(100000, 100000,     0.5)

zero_then_one(50000, 50000, 100000)
one_then_zero(40000, 60000, 100000)
first_line(100000, 100000)

