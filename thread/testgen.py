import numpy as np

MAX = 100000000

def check(X, Y, x, y, r):
    assert abs(X) <= MAX and abs(Y) <= MAX

    assert len(x) <= 100
    assert len(x) == len(y) and len(y) == len(r)
    assert (abs(x) <= MAX).sum() == len(x)
    assert (abs(y) <= MAX).sum() == len(x)
    assert (r <= MAX).sum() == len(x)
    assert (r > 0).sum() == len(x)

    for i in xrange(len(x)):
        for j in xrange(len(x)):
            if i != j:
                assert (x[i] - x[j]) ** 2 + (y[i] - y[j]) ** 2 > (r[i] + r[j]) ** 2
        assert x[i] ** 2 + y[i] ** 2 > r[i] ** 2
        assert (x[i] - X) ** 2 + (y[i] - Y) ** 2 > r[i] ** 2

num = 1
def add_test(X, Y, x, y, r): # add params
    check(X, Y, np.array(x), np.array(y), np.array(r))

    import matplotlib.pyplot as plt
    fig = plt.gcf()

    ax = plt.gca()
    ax.cla() # clear things for fresh plot
    # change default range so that new circles will work
    ax.set_xlim((-100,1000))
    ax.set_ylim((-100,700))

    for i in xrange(len(x)):
        fig.gca().add_artist(plt.Circle((x[i], y[i]), r[i], color='r'))
    fig.savefig('plotcircles.png')

    global num
    f = open('tests/' + str(num).zfill(3), 'w')

    f.write('%d %d %d\n' % (len(x), X, Y));
    for i in xrange(len(x)):
        f.write("%d %d %d\n" % (x[i], y[i], r[i]))

    f.close()
    print 'test', num, 'done'
    num += 1

def random_test(n, X, Y):
    d = np.zeros((n, 3))

    for i in xrange(n/2):
        while True:
            d[i][:2] = np.random.random_integers(-MAX, MAX, 2)
            d[i][2] = np.random.randint(MAX/16, MAX/15) + 1
            x, y, r = tuple(d[i])
            if x ** 2 + y **2 <= r ** 2:
                continue
            if (x - X) ** 2 + (y - Y) ** 2 <= r ** 2:
                continue

            j = 0
            while j < i:
                if (x - d[j][0]) ** 2 + (y - d[j][1]) ** 2 <= (r + d[j][2]) ** 2:
                    break
                j += 1

            if j == i:
                break

    for i in xrange(n/2, n):
        while True:
            d[i][:2] = np.random.random_integers(-100, 100, 2)
            d[i][2] = np.random.randint(7, np.random.randint(5) + 11) + 1
            x, y, r = tuple(d[i])
            if x ** 2 + y **2 <= r ** 2:
                continue
            if (x - X) ** 2 + (y - Y) ** 2 <= r ** 2:
                continue

            j = 0
            while j < i:
                if (x - d[j][0]) ** 2 + (y - d[j][1]) ** 2 <= (r + d[j][2]) ** 2:
                    break
                j += 1

            if j == i:
                break


    add_test(X, Y, d[:, 0], d[:, 1], d[:, 2])


add_test(-100, -100, [], [], [])
add_test(100, 100, [50], [50], [10])

add_test(0, 500, [0,  500, 100,  45, 10, 600, 600, 500, 1000, 600],
                 [100, 70,  10, 500, 10,   0, 400,   0,    0, 500],
                 [10,  19,  10,  30, 10,  40,  40,  50,   50,  50]);

random_test(100, 92203231, 100000000)
random_test(100, 92203231, 100000000)
random_test(100, 92203231, 100000000)
random_test(100, 92203231, 100000000)
random_test(100, -92203231, 100000000)
random_test(100, 92203231, 100000000)
random_test(100, 92203231, -10000000)
random_test(100, 92203231, 100000000)
random_test(100, -2203231, 1000000)
random_test(100, 92203231, -100000000)
random_test(100, 92203231, 100000)
random_test(100, -2203231, 100000000)
random_test(100, -92203231, -100000000)
random_test(100, -92203231, -100000000)
random_test(100, -92203231, -100000000)
random_test(100, -92203231, -100000000)
random_test(100, -92203231, -100000000)

