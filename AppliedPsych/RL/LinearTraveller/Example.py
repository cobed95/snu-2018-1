import numpy as np
import numpy.random as r



def move(state, action):
    a = [(-1,0), (1,0), (0,-1), (0,1)] # up, down, left, right
    Next = tuple(np.array(state) + np.array(a[action]))
    if not (Next[0] in range(4)): return state
    if not (Next[1] in range(4)): return state
    return Next

def e_greedy(state, V, epsilon):
    # Value update.
    values = []
    a = [(-1,0), (1,0), (0,-1), (0,1)] # up, down, left, right
    for direction in a:
        s1 = tuple(np.array(state) + np.array(direction))
        if not (s1[0] in range(4)): s1 = state
        if not (s1[1] in range(4)): s1 = state
        values.append(V[s1])
    values = np.array(values) # Values for 4 actions at the state.

    # Policy update.
    n = float((values == values.max()).sum())
    m = float((values != values.max()).sum())
    policy = np.zeros(4)
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
    Terminal = [(3, 3)]
    R = np.zeros((4, 4), dtype=int)
    R[3, 3] = 1

    V = np.zeros((4, 4))+0.01
    visit = np.zeros((4, 4), dtype=int)

    for ep in range(Episode):
        #epsilon = 1/(ep+2.0)
        epsilon = 0
        S = (0, 0)

        trace = [S]
        while not (S in Terminal):
            policy = e_greedy(S, V, epsilon)
            action = r.choice(4, p=policy)
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
