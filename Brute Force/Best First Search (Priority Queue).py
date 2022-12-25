from copy import deepcopy
import time

# matrix direction
MOVES = {"U": [-1, 0], "D": [1, 0], "L": [0, -1], "R": [0, 1]}
# matrix target
FINAL = [[1, 2, 3], [4, 5, 0], [6, 7, 8]]


class Node:

    def __init__(self, current_node, previous_node, x, y, moves):
        self.current_node = current_node
        self.previous_node = previous_node
        self.x = x
        self.y = y
        self.moves = moves

    def f(self):
        return self.x + self.y


def get_position(current_state, element):

    for row in range(len(current_state)):
        if element in current_state[row]:
            return (row, current_state[row].index(element))


def getAdjNode(node):

    listNode = []
    emptyPos = get_position(node.current_node, 0)

    for moves in MOVES.keys():

        newPos = (emptyPos[0] + MOVES[moves][0], emptyPos[1] + MOVES[moves][1])

        if 0 <= newPos[0] < len(node.current_node) and 0 <= newPos[1] < len(node.current_node[0]):
            newState = deepcopy(node.current_node)
            newState[emptyPos[0]][emptyPos[1]] = node.current_node[newPos[0]][newPos[1]]
            newState[newPos[0]][newPos[1]] = 0

            listNode.append(Node(newState, node.current_node, node.x + 1, calculateCost(newState), moves))

    return listNode


def calculateCost(current_state):

    cost = 0

    for row in range(len(current_state)):
        for col in range(len(current_state[0])):
            pos = get_position(FINAL, current_state[row][col])
            cost += abs(row - pos[0]) + abs(col - pos[1])

    return cost


def getBestNode(openSet):

    firstIteration = True

    for node in openSet.values():

        if firstIteration or node.f() < bestF:
            firstIteration = False
            bestNode = node
            bestF = bestNode.f()

    return bestNode


def searchPath(set):

    node = set[str(FINAL)]
    branch = list()

    while node.moves:

        branch.append({
            'moves': node.moves,
            'node': node.current_node
        })

        node = set[str(node.previous_node)]

    branch.append({
        'moves': '',
        'node': node.current_node
    })

    branch.reverse()

    return branch


def printResult(resultArray):

    print('------')

    j = 0

    for x in range(len(resultArray)):

        for i in resultArray[x]:

            if (i != 0):
                print(i, end=" ")
            else:
                print(end="0 ")

            j += 1

            if (j >= 3):
                print()
                j = 0

    global depth
    depth += 1


def main(puzzle):

    open_set = {str(puzzle): Node(puzzle, puzzle, 0, calculateCost(puzzle), "")}
    closed_set = {}

    while True:

        test_node = getBestNode(open_set)
        closed_set[str(test_node.current_node)] = test_node

        if test_node.current_node == FINAL:
            return searchPath(closed_set)

        adj_node = getAdjNode(test_node)

        for node in adj_node:

            if str(node.current_node) in closed_set.keys() or str(node.current_node) in open_set.keys() and open_set[str(node.current_node)].f() < node.f():
                continue

            open_set[str(node.current_node)] = node

        del open_set[str(test_node.current_node)]


if __name__ == '__main__':

    # this is start matrix
    t0 = time.time()
    matrix = main([
        [4, 1, 3],
        [6, 2, 5],
        [7, 8, 0]
    ])

    depth = 0

    for b in matrix:

        if b['moves'] != '':

            letter = ''

            printResult(b['node'])

            if b['moves'] == 'U':
                letter = 'up'
            elif b['moves'] == 'R': \
                    letter = "right"
            elif b['moves'] == 'L':
                letter = 'left'
            elif b['moves'] == 'D':
                letter = 'down'

            print('Depth:', depth)
            print('Move:', letter)

    print()
    print('------')
    print('Total steps: ', len(matrix) - 1)

    t1 = time.time()
    print('Time:', t1 - t0)
    print('------')
