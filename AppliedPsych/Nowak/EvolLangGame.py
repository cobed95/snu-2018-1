import numpy as np
import numpy.random as r
import matplotlib.pyplot as plt

#Each individual speaker is treated as an instance of the class Individual().
class Individual:
    A = np.array([]) #Associative matrix A.
    P = np.array([]) #Active matrix P.
    Q = np.array([]) #Passive matrix Q.
    fluency = 0 #Average fluency data updated as communicate() procedure runs.
    fitness = 0 #Fitness score used to generate the individuals of the next generation.
    parent = 0 #Indicates the index of the particular individuals parent. Used to generate Associative matrices of descendant generations.

    #Initialization of the instance. The attributes A, P, Q are instantiated as zeros or random values.
    def __init__(self):
        self.A = np.zeros((5, 5))
        self.A += 0.0001
        self.P = r.random((5, 5))
        self.P += 0.0001
        for i in range(len(self.P)):
            rowSum = self.P[i].sum()
            for j in range(len(self.P[i])):
                self.P[i][j] = self.P[i][j]/rowSum
        self.Q = r.random((5, 5))
        self.Q += 0.0001
        for i in range(len(self.Q)):
            for j in range(len(self.Q)):
                self.Q[i][j] = self.Q[i][j]/self.Q[:,j].sum()

    #Calculates Associative matrix A of a child individual from the Active matrix P of the parent individual.
    def getA(self, prev, k):
        for i in range(len(prev.P)):
            chosenArr = r.choice(range(5), k, p=prev.P[i])
            for chosen in chosenArr:
                self.A[i][chosen] += 1
        self.A += 0.0001

    #Calculates Active matrix P and Passive matrix Q from Associative matrix A, acquired by .getA() method.
    def calculatePQ(self):
        for i in range(len(self.P)):
            for j in range(len(self.P[i])):
                self.P[i][j] = self.A[i][j]/self.A[i].sum()
        for i in range(len(self.Q)):
            for j in range(len(self.Q[i])):
                self.Q[i][j] = self.A[i][j]/self.A[:,j].sum()

#Gets a population represented by a numpy array, and updates the fluency and fitness attributes of all individuals.
def communicate(population):
    for i in range(100):
        j = i+1
        while j < 100:
            iScore = population[i].P.dot(population[j].Q).diagonal().sum()
            jScore = population[j].P.dot(population[i].Q).diagonal().sum()
            payoff = (iScore + jScore)/2
            population[i].fluency += payoff
            population[j].fluency += payoff
            j += 1
    for i in range(100):
        population[i].fluency /= 99
    fluencySum = 0
    for i in range(100):
        fluencySum += population[i].fluency
    for i in range(100):
        population[i].fitness = population[i].fluency/fluencySum

#Gets a parent population and learning frequency k, and returns child population with appropriate A, P, Q attributes.
def getNextGen(population, k):
    probDenFunc = np.array([])
    for i in range(100):
        probDenFunc = np.append(probDenFunc, population[i].fitness)
    parentLabels = r.choice(range(100), 100, p=probDenFunc)

    nextGen = np.array([])
    for i in range(100):
        nextGen = np.append(nextGen, Individual())
        nextGen[i].parent = parentLabels[i]
        nextGen[i].getA(population[nextGen[i].parent], k)
        nextGen[i].calculatePQ()

    return nextGen

#Gets a parent population and returns the average payoff value. Used to plot data on matplotlib object.
def getAvgPayoff(population):
    payoffSum = 0
    for i in range(len(population)):
        print(population[i].fluency)
        payoffSum += population[i].fluency
    avgPayoff = payoffSum/len(population)
    return avgPayoff

#Gets learning frequency k and total number of generations, and actually runs the evolutionary language game.
def languageGame(k, numOfGen):
    forefathers = np.array([])
    for i in range(100):
        forefathers = np.append(forefathers, Individual())
    communicate(forefathers)

    aggData = np.array([])
    aggData = np.append(aggData, getAvgPayoff(forefathers))

    ancestors = forefathers[:]
    generation = 1
    while generation < numOfGen:
        children = getNextGen(ancestors, k)
        communicate(children)
        aggData = np.append(aggData, getAvgPayoff(children))
        ancestors = children[:]
        generation += 1

    return aggData

#adds data to the matplotlib object.
def plot(aggData):
    x = np.arange(len(aggData))
    y = aggData[x]
    plt.plot(x, y)

#The first argument of languageGame() is the changeable k value.
#The code may be modified to get k as an integer input from the console.
#Such implementation seemed trivial, and thus was omitted in this particular code.
def main():
    for i in range(20):
        aggData0 = languageGame(1, 100)
        plot(aggData0)
        plt.subplot(221)
        plt.title('k = 1')
        aggData1 = languageGame(4, 100)
        plot(aggData1)
        plt.subplot(222)
        plt.title('k = 4')
        aggData2 = languageGame(7, 100)
        plot(aggData2)
        plt.subplot(223)
        plt.title('k = 7')
        aggData3 = languageGame(10, 100)
        plot(aggData3)
        plt.subplot(224)
        plt.title('k = 10')
    plt.show()

if __name__ == '__main__':
    main()

