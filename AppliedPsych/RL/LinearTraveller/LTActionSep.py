# V(S(t)new) = V(S(t))old + alpha(G(S(t)) - V(S(t))old)
# SARSA (State-Action-Reward-State-Action)
# Attempted but failed.

import numpy as np
import numpy.random as r

def random_move(S):
    new_S = r.choice([S-1,S+1],p=[0.5,0.5])
    return new_S

def e_greedy(S,Q,eps):
    Left = 0; Right = 1
    if Q[S, Left]==Q[S, Right]:
        A = r.choice([Left,Right],p=[0.5,0.5])
    elif Q[S, Left] > Q[S, Right]:
        A = r.choice([Left,Right],p=[1-eps,eps])
    else:
        A = r.choice([Left,Right],p=[eps,1-eps])
    return A

def next_state(S, A):
    if S == 0 and A == 0:
        return 0;
    elif A == 0:
        return S-1;
    else:
        return S+1;

# Agent
Q = np.zeros((7, 2))
N = np.zeros((7, 2))
gamma = 0.9
R = np.ones(7)*(-1); R[6]=1
eps = 0.5

for t in range(10):
    S = r.randint(1,5)
    A = r.randint(2)
    trace = [S]
    N[S, A] += 1.0
    while S in range(1, 6):
        eps *= 0.9
        Next = next_state(S, A)
        new_A = e_greedy(Next, Q, eps)
        A = e_greedy(Next, Q, eps)
        G = R[S]+gamma*Q[Next, A]
        Q[S] = Q[S] + (1.0/N[S, A])*(G - Q[S, A])
        S = Next; A = new_A
        N[S, A] += 1.0
        trace.append(S)
    print(trace)

#    G = 0
#    for S in trace:
#        N[S] += 1
#        G = R[S] + gamma*G
#        V[S] += (1/N[S])*(G - V[S])
        # alpha = (1/N[s])
        # we're trying to get an average,
        # so we devide by frequency of visit.
    print(Q.round(2), len(trace))
