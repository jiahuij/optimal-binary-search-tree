 a program in VS C++ 2017 to implement the algorithm for the optimal binary search
 
tree problem shown in class. Your program should first prompt the user for the total number of

keys. It then asks the user to enter the keys and the probability for each key (both are entered on

one line). Your program then computes the A matrix and the R matrix and displays them to the

screen (in a 2-dimensional fashion). The last thing your program does before it quits is to build

the optimal binary search tree for the keys. The following shows a scenario of running a sample

program, where user's inputs are represented in boldface.

Enter the total number of keys: 3

Enter the 3 keys separated by at least 1 space: john adam mary

Enter the probability for the 3 keys separated by at least 1 space: 0.2 0.7 0.1

key1 = adam

key2 = john

key3 = mary

The following shows the A matrix and the R matrix computed, respectively.

0 0.7 1.1 1.4

0.0 0.2 0.4

0.0 0.1

0.0

0 1 1 1

0 2 2

0 3

0

The following shows the optimal binary search tree for john, adam, and mary.

adam

john

mary

You may assume that all inputs entered are valid. You may also assume that the total number

of keys entered is no more than 10. Print your optimal binary search tree in a breadth-first

fashion shown as follows.

root of the tree: adam

left child of adam: nil

right child of adam: john

left child of john: nil

right child of john: mary
