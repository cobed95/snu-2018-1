import numpy as np
import numpy.random as r

def move(state, action):
    a = [-1, 1] # left, right
    Next = np.array(state) + np.array(a[action])
    if not (Next in range(7)): return state
    return Next

def e_greedy(state, V, epsilon):
    # Value update.
    values = []
    a = [-1, 1] # left, right
    for direction in a:
        s1 = state + direction
        if not (s1 in range(7)): s1 = state
        values.append(V[s1])
    values = np.array(values)

    # Policy update.
    n = float((values == values.max()).sum())
    m = float((values != values.max()).sum())
    policy = np.zeros(2)
    if m == 0:
        policy[np.where(values == values.max())] = 1/n
        return policy
    policy[np.where(values == values.max())] = (1-epsilon)/n
    policy[np.where(values != values.max())] = epsilon/m
    policy = policy/float(policy.sum())
    return policy

def main():
    gamma = 0.9
    Episode = 50
    Terminal = [(6)]
    R = np.zeros(7, dtype=int)
    R[6] = 1

    V = np.zeros(7)+0.01
    visit = np.zeros(7, dtype=int)

    for ep in range(Episode):
        epsilon = 0
        S = r.choice(range(1, 6), p=[1/5]*5)

        trace = [S]
        while not (S in Terminal):
            policy = e_greedy(S, V, epsilon)
            action = r.choice(2, p=policy)
            Next = move(S, action)
            S = Next
            trace.append(S)

        trace.reverse()

        # Monte Carlo
        Gt = 0
        for k, state in enumerate(trace):
            visit[state] += 1
            Gt = R[state] + gamma*Gt
            V[state] += (Gt-V[state])/(visit[state])

        print(len(trace))

    print()
    print(V.round(2))
    print()

if __name__ == "__main__":
    main()
