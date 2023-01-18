import random

suites = ['S', 'C', 'H', 'D']
fullDeck = ['JK', 'JK']
for suite in suites:
    fullDeck += ['A' + suite, 'J' + suite, 'Q' + suite, 'K' + suite]
    fullDeck += [str(x) + suite for x in range(2, 11)]
#

power = ['3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A', '2']

def getPower(card):
    if card == 'JK':
        return 13
    #
    return power.index(card[:-1])
#

class TycoonGame:
    def __init__(this):
        this.lastFinished = [-1, -1, -1, -1]
        this.playerPoints = [0, 0, 0, 0]
        this.setupRound()
        this.sortHands()
    #

    def setupRound(this, cont = False):
        deck = fullDeck + []
        playerDecks = []
        for i in range(4):
            playerDecks += [[deck.pop(random.randint(0, len(deck) - 1)) for x in range(13)]]
        #
        if cont:
            for i in range(4):
                this.playerPoints[this.finished[i]] += 10 * (3 - i)
            #
            this.turn = this.finished[3]
            for i in range(2, 4, 1):
                playerDecks[this.finished[i]] += [deck.pop(0)]
            #
            this.lastFinished = this.finished
        else:
            this.turn = random.randInt(0, 3)
            players = [x for x in range(4)]
            for i in range(2):
                playerDecks[players.pop(random.randint(0, len(players) - 1))] += [deck.pop(0)]
            #
        #

        this.playerDecks = playerDecks
        this.revolution = False
        this.center = []
        this.finished = [-1, -1, -1, -1]
        this.passes = 0
    #

    def sortHands(this):
        for i in range(4):
            this.playerDecks[i].sort(key = getPower)
            print(this.playerDecks[i])
        #
    #

    def makeMove(this, move):
        if not this.isValid(move):
            return False
        #

        #Pass turn
        if len(move) == 0:
            this.turn = (this.turn + 1) % 4
            this.passes += 1
            return True
        #
        this.passes = 0

        #Get Card Type
        type = move + []
        if len(type) > 1:
            while 'JK' in type:
                type.remove('JK')
            #
        #
        type = type[0]

        #Check for a Revolution
        if len(move) == 4:
            this.revolution = !this.revolution
        #

        #Move cards from hand to center
        for card in move:
            this.playerDecks[this.turn].remove(card)
        #
        this.center = move

        #Check if player is finished & bankrupt the previous Tycoon
        if len(this.playerDecks[this.turn]) == 0:
            i = this.finished.index(-1)
            this.finished[i] = this.turn
            if i == 0 and this.lastFinished[0] != -1 and this.lastFinished[0] != this.turn:
                this.finished[3] = this.lastFinished[0]
            #
        #

        #Check if the round is over
        if this.finished[2] != -1 and this.finished[3] != -1:
            this.setupRound(True)
            return True
        #

        #Next turn
        currentPlayer = this.turn
        while (this.turn := (this.turn + 1) % 4) in this.finished:
            this.passes += 1
            if this.turn == currentPlayer:
                this.finished[this.finished.index(-1)] = currentPlayer
                this.setupRound(True)
                return True
            #
        #



    #

    def isValid(this, move):
        #Check for Pass or invalid type
        try:
            if len(move) == 0:
                return True
            #
        except:
            return False
        #

        #Check if you have the cards
        deck = this.playerDecks[this.turn]
        try:
            for card in move:
                deck.remove(card)
            #
        except:
            return False
        #

        #Check Length
        if len(this.center) != len(move) and len(this.center) != 0:
            return False
        #
        if len(set(move)) >= 2:
            return False
        #
        if len(set(move)) == 2 and 'JK' not in move:
            return False
        #

        #GET CENTER AND MOVE STRENGTHS
        center = this.center + []
        if len(center) > 1:
            while 'JK' in center:
                center.remove('JK')
            #
        #
        center = center[0]
        move = move + []
        if len(move) > 1:
            while 'JK' in move:
                move.remove('JK')
            #
        #
        move = move[0]

        #CHECK IF CARD IS HIGHER THAN DECK - Handle REVOLUTION
        if center == 'JK':
            if move == '3S' and len(this.center) == 1:
                return True
            #
            return False
        #
        if move == 'JK':
            return True
        #
        if not this.revolution:
            return power.index(move[:-1]) > power.index(center[:-1])
        else:
            return power.index(move[:-1]) < power.index(center[:-1])
        #
        return False
    #
#
