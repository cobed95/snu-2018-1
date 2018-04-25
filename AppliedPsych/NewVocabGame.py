# Abstract
#
# Class Diagram of 'Individual'
# class Individual -- Attributes -- A
#                 |             |
#                 |             |-- P
#                 |             |
#                 |             |-- Q
#                 |             |
#                 |             |-- objNum
#                 |             |
#                 |             |-- vocabNum
#                 |             |
#                 |             |-- fluency
#                 |             |
#                 |             |-- fitness
#                 |             |
#                 |             |-- parent
#                 |             |
#                 |             |-- fluencyArr
#                 |
#                 |-- Methods -- Individual __init__(newObjNum, newVocabNum)
#                            |
#                            |-- getA(prev, k, teacher)
#                            |
#                            |-- calculatePQ(teacher)
#                            |
#                            |-- getFluencyWith(friend)
#                            |
#                            |-- getFluencyArr()
#                            |
#                            |-- addNewObj()
#                            |
#                            |-- addNewVocab()
#                            |
#                            |-- learnNewVocab()
#                            |
#                            |-- knowsNewVocab()
#
# Function Diagram of 'NewVocabGame.py'
# main() -- languageGame(k, numOfGen, objNum, vocabNum) -- getAvgPayoff(population)
#       |                                              \
#       |                                               \
#       |                                                \
#       |                                                 \
#       |                                                  \
#       |                                                   \ __|-- communicate(population)
#       |                                                   /   |-- getNextGen(population, k)
#       |                                                  /
#       |                                                 /
#       |-- newVocabGame(firstGen, situation, k, numOfGen) -- encounterVocab(population, situation)
#       |                                                 |
#       |                                                 |-- spreadVocab(population, k)
#       |                                                 |
#       |                                                 |-- getAvgKnowledge(population)
#       |
#       |-- plot()


import numpy as np
import numpy.random as r
import matplotlib.pyplot as plt

class Individual:
    A = np.array([])
    P = np.array([])
    Q = np.array([])
    objNum = 0
    vocabNum = 0
    fluency = 0
    fitness = 0
    parent = 0

    fluencyArr = np.zeros(100)

    def __init__(self, newObjNum, newVocabNum):
        self.objNum = newObjNum
        self.vocabNum = newVocabNum
        self.A = np.zeros((self.objNum, self.vocabNum))
        self.A += 0.0000001
        self.P = r.random((self.objNum, self.vocabNum))
        self.P += 0.0000001
        for i in range(len(self.P)):
            rowSum = self.P[i].sum()
            for j in range(len(self.P[i])):
                self.P[i][j] = self.P[i][j]/rowSum
        self.Q = r.random((self.vocabNum, self.objNum))
        self.Q += 0.0000001
        for j in range(len(self.Q[0])):
            columnSum = self.Q[..., j].sum()
            for i in range(len(self.Q)):
                self.Q[i][j] = self.Q[i][j]/columnSum

    def getA(self, prev, k, teacher):
        parent = 0
        peer = 1
        if teacher == parent:
            for i in range(len(prev.P)):
                if prev.P[i].sum() != 1:
                    continue
                chosenArr = r.choice(range(len(prev.P[i])), k, p=prev.P[i])
                for chosen in chosenArr:
                    self.A[i][chosen] += 1
        elif teacher == peer:
            chosenArr = r.choice(range(len(prev.P[-1])), k, p=prev.P[-1])
            for chosen in chosenArr:
                self.A[-1][chosen] += 1
        self.A += 0.0000001

    def calculatePQ(self, teacher):
        parent = 0
        peer = 1
        if teacher == parent:
            for i in range(self.P.shape[0]):
                self.P[i] = self.A[i]/self.A[i].sum()
            for j in range(self.Q.shape[1]):
                self.Q[..., j] = self.A[j]/self.A[j].sum()
        elif teacher == peer:
            self.P[-1] = self.A[-1]/self.A[-1].sum()
            self.Q[..., -1] = self.A[-1]/self.A[-1].sum()

    def getFluencyWith(self, friend):
        speakingScore = self.P.dot(friend.Q).diagonal().sum()
        listeningScore = friend.P.dot(self.Q).diagonal().sum()
        result = (speakingScore + listeningScore)/2
        return result

    def getFluencyArr(self):
        auxArr = np.array([])
        fluencySum = self.fluencyArr.sum()
        for friend in self.fluencyArr:
            friend /= fluencySum
            auxArr = np.append(auxArr, friend)
        self.fluencyArr = auxArr

    def addNewObj(self):
        newP = np.zeros((self.P.shape[0]+1, self.P.shape[1]))
        newP[:-1] = self.P
        self.P = newP
        newQ = np.zeros((self.Q.shape[0], self.Q.shape[1]+1))
        for i in range(self.Q.shape[1]):
            newQ[..., i] = self.Q[..., i]
        self.Q = newQ
        self.A = np.zeros(self.P.shape)
        self.A += 0.0000001
        self.objNum += 1

    def addNewVocab(self):
        newP = np.zeros((self.P.shape[0], self.P.shape[1]+1))
        for i in range(self.P.shape[1]):
            newP[..., i] = self.P[..., i]
        self.P = newP
        newQ = np.zeros((self.Q.shape[0]+1, self.Q.shape[1]))
        newQ[:-1] = self.Q
        self.Q = newQ
        self.A = np.zeros(self.P.shape)
        self.A += 0.0000001
        self.vocabNum += 1

    def learnNewVocab(self, situation):
        if situation == 0:
            self.P[-1][-1] = max(self.P[-1])
            rowSum = self.P[-1].sum()
            for j in range(len(self.P[-1])):
                self.P[-1][j] /= rowSum

            self.Q[-1][-1] = max(self.Q[..., -1])
            columnSum = self.P[..., -1].sum()
            for i in range(len(self.Q)):
                self.Q[i][-1] /= columnSum

        elif situation == 1:
            self.P[-1][-1] = 1
            self.Q[-1][-1] = 1

    def knowsNewVocab(self):
        if self.P[-1].sum() == 1:
            return True
        else:
            return False

def communicate(population):
    for i in range(100):
        j = i+1
        while j < 100:
            payoff = population[i].getFluencyWith(population[j])
            population[i].fluency += payoff
            population[j].fluency += payoff
            population[i].fluencyArr[j] += payoff
            population[j].fluencyArr[i] += payoff
            j += 1
    for i in range(100):
        population[i].fluency /= 99
    fluencySum = 0
    for i in range(100):
        fluencySum += population[i].fluency
    for i in range(100):
        population[i].fitness = population[i].fluency/fluencySum

def getNextGen(population, k):
    probDenFunc = np.array([])
    for i in range(100):
        probDenFunc = np.append(probDenFunc, population[i].fitness)
    parentLabels = r.choice(range(100), 100, p=probDenFunc)

    nextGen = np.array([])
    for i in range(100):
        nextGen = np.append(nextGen, Individual(population[0].objNum, population[0].vocabNum))
        nextGen[i].parent = parentLabels[i]
        nextGen[i].getA(population[nextGen[i].parent], k, 0)
        nextGen[i].calculatePQ(0)

    return nextGen

def getAvgPayoff(population):
    payoffSum = 0
    for i in range(len(population)):
        payoffSum += population[i].fluency
    avgPayoff = payoffSum/len(population)
    return avgPayoff

def languageGame(k, numOfGen, objNum, vocabNum):
    forefathers = np.array([])
    for i in range(100):
        forefathers = np.append(forefathers, Individual(objNum, vocabNum))
    communicate(forefathers)

    ancestors = forefathers[:]
    generation = 1
    while generation < numOfGen:
        children = getNextGen(ancestors, k)
        communicate(children)
        ancestors = children[:]
        generation += 1

    print(getAvgPayoff(children))
    return children

def encounterVocab(population, situation):
    if situation == 0:
        for individual in population:
            individual.addNewVocab()

    elif situation == 1:
        for individual in population:
            individual.addNewObj()
            individual.addNewVocab()

    population[0].learnNewVocab(situation);
    population[1].learnNewVocab(situation);

def spreadVocab(population, k):
    for i in range(len(population)):
        population[i].getFluencyArr()
        if not population[i].knowsNewVocab():
            continue
        else:
            friends = r.choice(range(len(population)), 2, p=population[i].fluencyArr)
            for friend in friends:
                if population[friend].knowsNewVocab():
                    continue
                else:
                    population[friend].getA(population[i], k, 1)
                    population[friend].calculatePQ(1)

def getAvgKnowledge(population):
    knowledgeSum = 0
    for individual in population:
        knowledgeSum += individual.P[-1][-1]
    return knowledgeSum/100

def newVocabGame(firstGen, situation, k, numOfGen):
    encounterVocab(firstGen, situation)
    spreadVocab(firstGen, k)
    communicate(firstGen)

    aggData = np.array([])
    aggData = np.append(aggData, getAvgKnowledge(firstGen))

    ancestors = firstGen[:]
    generation = 1
    while generation < numOfGen:
        print(generation)
        print('start')
        children = getNextGen(ancestors, k)
        spreadVocab(children, k)
        communicate(children)
        aggData = np.append(aggData, getAvgKnowledge(children))
        ancestors = children[:]
        print('end')
        generation += 1

    return aggData

def plot(aggData0, aggData1):
    x = np.arange(100)
    plt.subplot(211)
    plt.plot(x, aggData0)
    plt.title('New vocab added')
    plt.suptitle('k = 4', fontsize=16)

    plt.subplot(212)
    plt.plot(x, aggData1)
    plt.title('New vocab & new obj added')
    plt.subplots_adjust(hspace=0.5)

    plt.show()

def main():
    firstGen = languageGame(1, 100, 5, 5)
    aggData0 = newVocabGame(firstGen, 0, 4, 100)
    aggData1 = newVocabGame(firstGen, 1, 4, 100)
    plot(aggData0, aggData1)

if __name__ == '__main__':
    main()

