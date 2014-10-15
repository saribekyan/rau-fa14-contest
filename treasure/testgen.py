import numpy as np
import math

num = 1
def add_test(X, Y, polygon): # add params
    global num
    with open('tests/' + str(num).zfill(3), 'w') as f:
        f.write('%d %d %d\n' % (X, Y, len(polygon)))
        for p in polygon:
            f.write('%.10lf %.10lf\n' % (p[0], p[1]))
    print 'test', num, 'done'
    num += 1

def polygon(X, Y, x, y, r, n):
    assert 0 <= x - r and x + r <= X
    assert 0 <= y - r and y + r <= Y
    assert r >= 1

    alpha = 2 * math.pi / n

    a = 0

    xc = []
    yc = []
    for i in xrange(n):
        xc.append(x + r * math.cos(a))
        yc.append(y + r * math.sin(a))
        a += alpha

    return np.transpose(np.vstack([xc, yc]))

add_test(100, 100, np.array([[41.1, 41.1],
                             [41.1, 41.9],
                             [90.1, 41.9],
                             [90.1, 41.1]]))

add_test(10, 10, np.array([[0, 0],
                           [0, 10],
                           [10, 10],
                           [10, 0]]))

add_test(100, 100, np.array([[0.1, 0.1],
                             [0.1, 1.5],
                             [0.9, 1.5],
                             [0.9, 0.1]]))

add_test(100, 100, np.array([[10.1, 20.1],
                             [10.1, 21.5],
                             [10.9, 21.5],
                             [10.9, 20.1]]))

add_test(100, 100, np.array([[90.1, 0.1],
                             [90.1, 1.5],
                             [90.9, 1.5],
                             [90.9, 0.1]]))


add_test(1, 1, np.array([[0, 0],
                         [0, 1],
                         [1, 1],
                         [1, 0]]))

add_test(100, 100, polygon(100, 100, 50, 50, 1, 5))
add_test(100, 100, polygon(100, 100, 10, 10, 5, 10))
add_test(100, 100, polygon(100, 100, 55, 52, 2, 3))
add_test(100, 100, polygon(100, 100, 90, 80, 1, 5))
add_test(100, 100, polygon(100, 100, 10, 95, 1, 5))

add_test(100, 100, polygon(100, 100, 1, 99,  1, 20))
add_test(100, 100, polygon(100, 100, 23, 78, 1, 40))
add_test(100, 100, polygon(100, 100, 17, 95, 1, 3))
add_test(100, 100, polygon(100, 100, 87, 43, 1, 5))
add_test(100, 100, polygon(100, 100, 82, 65, 1, 5))

