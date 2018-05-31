# V(S(t)new) = V(S(t))old + alpha(G(S(t)) - V(S(t))old)

import numpy as np
import numpy.random as r

def random_move(S):
    new_S = r.choice([S-1,S+1],p=[0.5,0.5])
    return new_S

def e_greedy(S,V,eps):
    if V[S-1]==V[S+1]:    new_S = r.choice([S-1,S+1],p=[0.5,0.5])
    elif V[S-1] > V[S+1]: new_S = r.choice([S-1,S+1],p=[1-eps,eps])
    else : new_S = r.choice([S-1,S+1],p=[eps,1-eps])
    return new_S

# Agent
V = np.zeros(7)
N = np.zeros(7)
gamma = 0.9
R = np.zeros(7);R[6]=1

for t in range(100):
    eps = 0.5
    S = r.randint(1,5)
    trace = [S]
    while S in range(1, 6):
        S = e_greedy(S, V, eps)
        trace.append(S)

    trace.reverse()

    G = 0
    for S in trace:
        N[S] += 1
        G = R[S] + gamma*G
        V[S] += (1/N[S])*(G - V[S])
        # alpha = (1/N[s])
        # we're trying to get an average,
        # so we devide by frequency of visit.
    print(V.round(2), len(trace))
