import numpy as np

num = 1
def add_test(p, k): # add params
    global num
    f = open('tests/' + str(num).zfill(3), 'w')
    f.write('%d %d\n' % (len(p), k))
    f.write('%d' % p[0])
    for prd in p[1:]:
        f.write(' %d' % prd)
    f.write('\n')
    f.close()
    print 'test', num, 'done'
    num += 1

MOD = 1000003
M = 500000

def gen_primes():
    is_p = np.ones(M + 1, dtype='bool')
    is_p[::2] = False
    is_p[1] = False
    is_p[2] = True
    i = 3
    while i * i <= M:
        if is_p[i]:
            is_p[i * i : : i] = False
        i += 2
            
    return is_p.nonzero()[0]

primes = gen_primes()

add_test([1, 2, 3, 4, 5], 3)

add_test(np.ones(1000), 492)
add_test(np.ones(1000) * 1993, 500)
add_test(np.arange(1000) + 1234, 300)
add_test((np.arange(1000) + 1) * 10, 523)

add_test(primes[np.random.random_integers(70000 / 2, 75000 / 2, 1000)], 200)
add_test(primes[np.random.random_integers(70000 / 2, 75000 / 2, 1000)], 200)

add_test(primes[np.random.random_integers(1, 75000 / 2, 1000)], 300)
add_test(primes[np.random.random_integers(1, 75000 / 2, 1000)], 400)

add_test(np.random.random_integers(1, 1000000 / 2, 1000), 234)
add_test(np.random.random_integers(900000 / 2, 1000000 / 2, 1000), 123)
add_test(np.random.random_integers(900000 / 2, 1000000 / 2, 1000), 123)

add_test(np.ones(100000 / 2), 49238 / 2)
add_test(np.ones(100000 / 2) * 429773, 50000 / 2)
add_test(np.arange(100000 / 2) + 1234, 3000 / 2)
add_test((np.arange(100000 / 2) + 1) * 10, 52321 / 2)

add_test(primes[np.random.random_integers(70000 / 2, 75000 / 2, 100000 / 2)], 20000 / 2)
add_test(primes[np.random.random_integers(60000 / 2, 75000 / 2, 100000 / 2)], 20000 / 2)

add_test(primes[np.random.random_integers(1, 75000 / 2, 100000 / 2)], 30000 / 2)
add_test(primes[np.random.random_integers(1, 75000 / 2, 100000 / 2)], 30000 / 2)

add_test(np.random.random_integers(1, 1000000 / 2, 100000 / 2), 23456 / 2)
add_test(np.random.random_integers(900000 / 2, 1000000 / 2, 100000 / 2), 12345 / 2)
add_test(np.random.random_integers(900000 / 2, 1000000 / 2, 100000 / 2), 12345 / 2)

