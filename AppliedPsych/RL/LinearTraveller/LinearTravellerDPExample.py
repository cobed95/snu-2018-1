import numpy as np
import numpy.random as r

gamma = 0.9

# Model
R = np.zeros(7)
R[6] = 1
P = np.zeros((7,7))
P[0,0] = 1
P[1,0] = 0.5; P[1,2] = 0.5
P[2,1] = 0.5; P[2,3] = 0.5
P[3,2] = 0.5; P[3,4] = 0.5
P[4,3] = 0.5; P[4,5] = 0.5
P[5,4] = 0.5; P[5,6] = 0.5
P[6,6] = 1


# Agent
V = np.zeros(7)
new_V = V

for t in range(100):
    for s in range(7):
        new_V[s] = R[s] + gamma*(V*P[s]).sum()
    V = new_V
    print(V.round(2))
