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

def gen_primes():
    is_p = np.ones(MOD + 1, dtype='bool')
    is_p[::2] = False
    is_p[1] = False
    is_p[2] = True
    i = 3
    while i * i <= MOD:
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

add_test(primes[np.random.random_integers(70000, 75000, 1000)], 200)
add_test(primes[np.random.random_integers(70000, 75000, 1000)], 200)

add_test(primes[np.random.random_integers(1, 75000, 1000)], 300)
add_test(primes[np.random.random_integers(1, 75000, 1000)], 400)

add_test(np.random.random_integers(1, 1000000, 1000), 234)
add_test(np.random.random_integers(900000, 1000000, 1000), 123)
add_test(np.random.random_integers(900000, 1000000, 1000), 123)

add_test(np.ones(100000), 49238)
add_test(np.ones(100000) * 999983, 50000)
add_test(np.arange(100000) + 1234, 3000)
add_test((np.arange(100000) + 1) * 10, 52321)

add_test(primes[np.random.random_integers(70000, 75000, 100000)], 20000)
add_test(primes[np.random.random_integers(60000, 75000, 100000)], 20000)

add_test(primes[np.random.random_integers(1, 75000, 100000)], 30000)
add_test(primes[np.random.random_integers(1, 75000, 100000)], 30000)

add_test(np.random.random_integers(1, 1000000, 100000), 23456)
add_test(np.random.random_integers(900000, 1000000, 100000), 12345)
add_test(np.random.random_integers(900000, 1000000, 100000), 12345)

