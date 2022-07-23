# AutoPlayer-Chess-With-Alpha-Beta-Pruning

Game of chess has been a classic AI problem and these days there are several excellent open source
implementations of automatic chess players are available on line. In this assignment we are going to make
yet another FAST-chess player that will play chess using some well-established strategies along with
**MINIMAX** to compute moves for a chess player. 

To complete this assignment you have been provided with an abstract base class called **chessPlayer** and two
demo player classes named **humanPlayer** and **autoPlayer**. Along with these two class, another class, called
**gameState**, is also provided that holds state of the game at any given time. The state of the chess at any
given time consists of information about player turn (i.e. an enumeration called **Color** with a value of 1 means
**WHITE** player will move and 0 means **BLACK** player will move) and an 8 x 8 chess board with chess pieces
encoded as shown below. 


![alt text](https://github.com/fazeelkhalid/Chess-With-Alpha-Beta-Pruning/blob/main/Images/board1.png)



The **negative numbers** represent **pieces** of **Black player** and **positive numbers** represent **pieces** of **Whiteplayer**

For your convenience, all major functions for playing chess are already implemented and the chess state also
includes a list of valid moves available at any given time. 

Your primary job in this assignment is to create an auto-player named **YOUR_GROUP_NAME** (the name of
your group be used to name the class). Your class will inherit the abstract base class chessPlayer and will
provide an overridden implementation the virtual function **decideMove** .
To give you an idea, a sample **autoPlayer** is also provided along with a deriver program. This auto-player
selects a move at random from a set of available moves. Try to play with the auto player and enjoy your
game. 

## AJOR TASK: DECIDE A SINGLE MOVE USING MINIMAX (DFS) ALGORITHM
Your implementation must use alpha-beta pruning and a **max-depth** parameter to specify the maximum
depth of the tree to be used for making a single move. Indeed this would require an implementation of the
evaluation function as well. [3 Marks]. 

## Grading Guidelines
Marks will be awarded for 

* a detailed review of available Evaluation Functions (You must submit a report explaining various
evaluation functions already available)
* a detailed description of your own evaluation function 
* correct implementation of your auto player 
* ranking of your player w.r.t the remaining students(Tentative)


Please remember that you are not allowed to modify the existing classes and must provide only your own
auto-player class that must be a child of the abstract ***chessPlayer*** class. You are free to define your own class
structure as you desire. 



**If a change is needed in the base code, you can post your suggestion on google classroom stream and it will be considered**

**Further submission guidelines will be provided as we progress.**

**The base code has been written using CODEBLOCKS and you might have to re-arrange it to port it to other development environments like Visual Studios**