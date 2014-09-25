import numpy as np

num = 1
def add_test(a): # add params
    global num
    f = open('tests/' + str(num).zfill(3), 'w')
    f.write(str(len(a)) + '\n')
    f.write('%d' % a[0])
    for b in a[1:]:
        f.write(' %d' % b)
    f.write('\n')
    f.close()
    print 'test', num, 'done'
    num += 1

def gen_test(n, m):
    a = np.random.random_integers(5000, 10000, m)
    a = a[np.random.random_integers(0, m-1, n)]
    add_test(a)

add_test(np.ones(10) * 100)
add_test(np.ones(100000) * 10000)
add_test(np.arange(100000) + 1)

gen_test(100, 10)
gen_test(100, 10)
gen_test(100000, 100)
gen_test(100000, 1)
gen_test(1, 1)
gen_test(100000, 1000)
gen_test(100000, 100000)
gen_test(100000, 100000)
gen_test(100000, 100000)

add_test(np.repeat(np.arange(1000) + 1000, 100))

