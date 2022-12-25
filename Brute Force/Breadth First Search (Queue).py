from queue import Queue
import copy
import time


def printNode(node):

    for row in node[0]:
        print(row)

    global nodeNumber
    print('Node:', nodeNumber)
    print('Depth:', len(node[2]))
    print('Moves:', node[2])
    print('------')
    nodeNumber += 1


def checkFinal(node):

    if node[0] == finalNode:
        printNode(node)
        return True

    if node[0] not in visitedList:
        printNode(node)
        queue.put(node)
        visitedList.append(node[0])

    return False


if __name__ == '__main__':

    startNode = [[4, 1, 3], [6, 2, 5], [7, 8, 0]]
    finalNode = [[1, 2, 3], [4, 5, 0], [6, 7, 8]]

    found = False

    nodeNumber = 0
    visitedList = []
    queue = Queue()
    queue.put((startNode, nodeNumber, []))
    visitedList.append(startNode)
    printNode((startNode, nodeNumber, []))
    t0 = time.time()

    while (not found and not queue.empty()):

        currentNode = queue.get()
        matrix = currentNode[0]
        moves = currentNode[2]

        for i in range(3):
            for j in range(3):
                if matrix[i][j] == 0:
                    blankIndex = (i, j)
                    break

        if blankIndex[0] > 0:

            upNode = copy.deepcopy(matrix)
            upNode[blankIndex[0]][blankIndex[1]] = upNode[blankIndex[0] - 1][blankIndex[1]]
            upNode[blankIndex[0] - 1][blankIndex[1]] = 0
            found = checkFinal((upNode, nodeNumber + 1, moves + ['up']))

        if blankIndex[1] > 0 and not found:

            leftNode = copy.deepcopy(matrix)
            leftNode[blankIndex[0]][blankIndex[1]] = leftNode[blankIndex[0]][blankIndex[1] - 1]
            leftNode[blankIndex[0]][blankIndex[1] - 1] = 0
            found = checkFinal((leftNode, nodeNumber + 1, moves + ['left']))

        if blankIndex[0] < 2 and not found:

            downNode = copy.deepcopy(matrix)
            downNode[blankIndex[0]][blankIndex[1]] = downNode[blankIndex[0] + 1][blankIndex[1]]
            downNode[blankIndex[0] + 1][blankIndex[1]] = 0
            found = checkFinal((downNode, nodeNumber + 1, moves + ['down']))

        if blankIndex[1] < 2 and not found:

            rightNode = copy.deepcopy(matrix)
            rightNode[blankIndex[0]][blankIndex[1]] = rightNode[blankIndex[0]][blankIndex[1] + 1]
            rightNode[blankIndex[0]][blankIndex[1] + 1] = 0
            found = checkFinal((rightNode, nodeNumber + 1, moves + ['right']))

    t1 = time.time()
    print('Time:', t1 - t0)
    print('------')
