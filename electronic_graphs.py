import matplotlib.pyplot as plt

plt.grid()
plt.xlabel (r'$x$')
plt.ylabel(r'$F*(x)$')
plt.title ("График эмпирической функции распределения\nдля интервального ряда")
plt.ylim(0,3)
plt.plot ([70,80,90,100,110,120,130],[2.54,2.54,2.54,2.54,2.54,2.54,2.54],'-bo')
plt.show()