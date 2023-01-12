import numpy as np


#Running the Simulation with 15 IID Binomial RV for size=1 each, with n=1000 trials, probability of success is p=0.5

X1 = np.random.binomial(1000, 0.5, 1)
X2 = np.random.binomial(1000, 0.5, 1)
X3 = np.random.binomial(1000, 0.5, 1)
X4 = np.random.binomial(1000, 0.5, 1)
X5 = np.random.binomial(1000, 0.5, 1)
X6 = np.random.binomial(1000, 0.5, 1)
X7 = np.random.binomial(1000, 0.5, 1)
X8 = np.random.binomial(1000, 0.5, 1)
X9 = np.random.binomial(1000, 0.5, 1)
X10 = np.random.binomial(1000, 0.5, 1)
X11 = np.random.binomial(1000, 0.5, 1)
X12 = np.random.binomial(1000, 0.5, 1)
X13 = np.random.binomial(1000, 0.5, 1)
X14 = np.random.binomial(1000, 0.5, 1)
X15 = np.random.binomial(1000, 0.5, 1)
print(X1)

XN = (X1 + X2 + X3 + X4 + X5 + X6 + X7 + X8 + X9 + X10 +
      X11 + X12 + X13 + X14 + X15)/15  # Sample Mean
mean = np.mean(XN)  # Calculated mean of the sample
print("Sample Mean: " + str(mean))
