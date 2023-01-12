
import numpy as np
import matplotlib.pyplot as plt

# m = 10
li_mean = []
x = np.random.exponential(scale=50, size=10)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_mean.append(x.mean())

x = np.random.exponential(scale=50, size=100)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_mean.append(x.mean())

x = np.random.exponential(scale=50, size=500)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_mean.append(x.mean())

x = np.random.exponential(scale=50, size=1000)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_mean.append(x.mean())

x = np.random.exponential(scale=50, size=5000)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_mean.append(x.mean())

x = np.random.exponential(scale=50, size=10000)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_mean.append(x.mean())

x = np.random.exponential(scale=50, size=50000)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_mean.append(x.mean())

print("Exponential Distribution")
print("Mean of m = 10, 100, 500, 1000, 5000, 10000, 50000")

li_values = ['10', '100', '500', '1000', '5000', '10000', '50000']
print(li_mean)
for i in range(0, len(li_mean)):
    li_mean[i] = round(li_mean[i], 2)
print("")
print(li_mean)

plt.plot(li_values, li_mean)
plt.title("Exponential Distribution")
plt.show()

# Uniform
li_meanU = []
x = np.random.uniform(0, 1, size=10)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_meanU.append(x.mean())

x = np.random.uniform(0, 1, size=100)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_meanU.append(x.mean())

x = np.random.uniform(0, 1, size=500)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_meanU.append(x.mean())

x = np.random.uniform(0, 1, size=1000)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_meanU.append(x.mean())

x = np.random.uniform(0, 1, size=5000)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_meanU.append(x.mean())

x = np.random.uniform(0, 1, size=10000)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_meanU.append(x.mean())

x = np.random.uniform(0, 1, size=50000)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_meanU.append(x.mean())

print("")
print("Uniform Distribution")
print("Mean of m = 10, 100, 500, 1000, 5000, 10000, 50000")

li_valuesU = ['10', '100', '500', '1000', '5000', '10000', '50000']
print(li_meanU)
for i in range(0, len(li_meanU)):
    li_meanU[i] = round(li_meanU[i], 2)
print("")
print(li_meanU)

plt.plot(li_valuesU, li_meanU)
plt.title("Uniform Distribution")
plt.show()

# Bernoulli
li_meanB = []
x = np.random.uniform(0, 1, size=10)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_meanB.append(x.mean())

x = np.random.uniform(0, 1, size=100)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_meanB.append(x.mean())

x = np.random.uniform(0, 1, size=500)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_meanB.append(x.mean())

x = np.random.uniform(0, 1, size=1000)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_meanB.append(x.mean())

x = np.random.uniform(0, 1, size=5000)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_meanB.append(x.mean())

x = np.random.uniform(0, 1, size=10000)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_meanB.append(x.mean())

x = np.random.uniform(0, 1, size=50000)
for i in range(0, len(x)):
    x[i] = round(x[i], 2)
li_meanB.append(x.mean())

print("")
print("Bernoulli Distribution")
print("Mean of m = 10, 100, 500, 1000, 5000, 10000, 50000")

li_valuesB = ['10', '100', '500', '1000', '5000', '10000', '50000']
print(li_meanB)
for i in range(0, len(li_meanB)):
    li_meanB[i] = round(li_meanB[i], 2)
print("")
print(li_meanB)

plt.plot(li_valuesB, li_meanB)
plt.title("Bernoulli Distribution")
plt.show()

# 2
print("2 Start")
li_ex2 = []
size_2pow = [1, 2, 4, 8, 16, 32]

rand_exp = np.random.exponential(5, 10000)
for i in size_2pow:
    j = 0
    for j in range(0, i):
        arr = np.random.choice(rand_exp, 1000)
        mean = arr.mean()
        li_ex2.append(mean)
    plt.plot(li_ex2)
    plt.title("Exponential Distribution")
    plt.show()
    li_ex2.clear()

li_me = []
rand_uni = np.random.uniform(0, 1, 10000)
for i in size_2pow:
    j = 0
    for j in range(0, i):
        arr = np.random.choice(rand_uni, 1000)
        mean = arr.mean()
        li_me.append(mean)
    plt.plot(li_me)
    plt.title("Uniform Distribution")
    plt.show()
    li_me.clear()

li_me3 = []
rand_ber = np.random.binomial(1, 0.6, 10000)
for i in size_2pow:
    j = 0
    for j in range(0, i):
        arr = np.random.choice(rand_ber, 1000)
        mean = arr.mean()
        li_me3.append(mean)
    plt.plot(li_me3)
    plt.title("Bernoulli Distribution")
    plt.show()
    li_me3.clear()
