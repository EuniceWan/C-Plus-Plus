# IPD Homework 7: Hexapawn


## Summary

For this homework, we achieve an interactive program implementing
the two-player abstract strategy game [Hexapawn].

## Goals

To design a whole program from scratch, while maintaining good style and
logical factoring.

## Specification

The rules of Hexapawn are available in [the Hexapawn Wikipedia
article], and our program implement [Hexapawn] rules.

Unlike traditional 3×3 Hexapawn, our game supports board
dimensions from 3×3 to 8×8. Changing a dimension is as easy as
changing a constant.

At each turn, our game displays the state of the board and which
player’s turn it is. It then allows the player to select a move.
Here is an example of what that display looks like for a 5×3 game:

````
   | a | b | c | d | e |
---+---+---+---+---+---+---
 3 | B | B | B | B | B | 3
---+---+---+---+---+---+---
 2 |   | W |   |   |   | 2
---+---+---+---+---+---+---
 1 | W |   | W | W | W | 1
---+---+---+---+---+---+---
   | a | b | c | d | e |

Player B’s move:
  0: a3–a2
  1: a3–b2
  2: c3–c2
  3: c3–b2
  4: d3–d2
  5: e3–e2
>
````

When a player wins, either by reaching the other side or leaving the
other player with no available moves, a messages to this effect should
be displayed and the program should terminate.

## Design

We design 9 function to complete the game:

// Initial value
hexapawn::hexapawn(int & n_n, int & n_m)

// draw chessboard
void hexapawn::new_chessboard()

// draw chesspieces
void hexapawn::new_chess()

// follow the rule to play
void hexapawn::play()

// draw chessboard style
void hexapawn::draw_board()

// to find which position the chesspiece can move to
void hexapawn::player1_move()
void hexapawn::player2_move()

// select one way to move chesspiece 
void hexapawn::player1_showselection() 
void hexapawn::player2_showselection()

// move chesspiece according to the selection 
void hexapawn::player1_domove()
void hexapawn::player2_domove()

<discovery>

The test.cpp and main function can't work at the same time.

