import numpy as np
from matplotlib import pylab as pl
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt

NX=101
NT=300
L=10.
T=6.
Dx=L/NX

data = np.loadtxt("Data.dat")
grid = np.reshape(data, (NX, NT))


fig = plt.figure()
ax = fig.gca(projection='3d')
ax.set_xlabel('Tiempo')
ax.set_ylabel('Posicion')
ax.set_zlabel('Desplazamiento')


x1 = np.linspace(0, T, NT)
y1 = np.linspace(0, L, NX)

xx, yy = np.meshgrid(x1, y1)

surf = ax.plot_surface(xx, yy, grid,cmap=pl.cm.jet)

fig.colorbar(surf, shrink=0.5, aspect=5)
plt.savefig("plot_grad.png")

X=[]
Y_i=[]
Y_f=[]

for i in range(NX):
    X.append(Dx*i)
    Y_i.append(grid[i][0])
    Y_f.append(grid[i][NT-1])

plt.figure()
plt.plot(X,Y_i)
plt.plot(X,Y_f)
plt.gca().legend(('Tiempo inicial','Tiempo final'))
plt.xlabel("Posicion")
plt.ylabel("Desplazamiento")
plt.savefig("plot_norm.png")
