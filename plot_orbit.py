import numpy as np
import matplotlib.pyplot as plt

# load the columns
x, y, energy, err = np.loadtxt("orbit.txt", unpack=True)

# create and save the plot
fig = plt.figure(figsize=(4,6))
ax1 = fig.add_subplot(211)
ax2 = fig.add_subplot(212)

ax1.plot(x, y)
ax1.set_title("leapfrog")
ax1.set_xlabel("x")
ax1.set_ylabel("y")

# ax2.set_title("energy")
ax2.plot(err)
ax2.set_xlabel("t")
ax2.set_ylabel("energy relative error")


plt.savefig("orbit.pdf", bbox_inches='tight', pad_inches=0.1)

plt.close()
