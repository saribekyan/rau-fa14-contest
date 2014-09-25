import numpy as np

num = 1
def add_test(): # add params
    global num
    f = open('tests/' + str(num).zfill(3), 'w')
    # write f
    f.close()
    print 'test', num, 'done'
    num += 1

