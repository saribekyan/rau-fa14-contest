import matplotlib.pyplot as plt
fig = plt.gcf()

ax = plt.gca()
ax.cla() # clear things for fresh plot
# change default range so that new circles will work
ax.set_xlim((-1000,1000))
ax.set_ylim((-1000,1000))
ax.plot()

d = [
-931, -622, 64,
302, 498, 63,
-414, -216, 66,
59, 410, 64,
-787, 440, 63,
-82, -88, 8,
94, -81, 8,
-2, -47, 8,
50, 49, 9,
-15, 2, 7]

x = d[::3]
y = d[1::3]
r = d[2::3]
#print x
#print y
#print r

for i in xrange(len(x)):
    fig.gca().add_artist(plt.Circle((x[i], y[i]), r[i], color='r'))
fig.savefig('plotcircles.png')

