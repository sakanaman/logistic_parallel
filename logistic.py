import logistic as logi
import matplotlib.pyplot as plt
import time

x0 = 0.1
mu0 = 2.7
mu1 = 4.0
m = 300
N = 500
iter_mu = 6000
delta_mu = (mu1 - mu0)/iter_mu

start = time.time()

record = logi.logistic(x0, mu0, delta_mu, iter_mu, m, N)
plt.plot(record.mu_list, record.x_list, ".", markersize =0.2)

end = time.time()
print("time: {}".format((end - start)) + "[sec]")

plt.show()