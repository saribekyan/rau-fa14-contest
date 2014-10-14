import numpy as np

num = 1
def add_test(strings): # add params
    global num
    f = open('tests/' + str(num).zfill(3), 'w')
    # write f
    f.write('%d\n' % len(strings));
    for s in strings:
        f.write('%s\n' % s);
    f.close()
    print 'test', num, 'done'
    num += 1

M = 1000
def random_test(n, l):
    s = ''.join(map(chr, np.random.random_integers(ord('a'), ord('z'), l)))
    d = []
    for i in xrange(n):
        t = ''.join(map(chr, np.random.random_integers(ord('a'), ord('z'), np.random.randint(0, M - l + 1))))
        j = np.random.randint(len(t) + 1)
        d.append(t[:j] + s + t[j:])

    return d

add_test(['a'])
add_test(['asdf'])
add_test(['asdf', 'asdf'])
add_test(['asdf', 'qwer'])

add_test(random_test(10, 10))
add_test(random_test(100, 100))
add_test(random_test(100, 300))
add_test(random_test(100, 300))
add_test(random_test(100, 300))
add_test(random_test(100, 300))
add_test(random_test(100, 10))
add_test(random_test(100, 2))
add_test(random_test(100, 20))
add_test(random_test(100, 900))
add_test(random_test(100, 700))
add_test(random_test(100, 800))

