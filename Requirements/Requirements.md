# Stakeholder Needs

## Functional Requirements

SN-001: The software SHALL implement "Reversi" as a computer game with all its according rules.

*Reversi is a 2-player board game in which players take turns placing white and black pieces on an 8x8 board. The winner is the player who has the most pieces on the board at the end of the game. Reversi is explained, e.g., on [Wikipedia](https://en.wikipedia.org/wiki/Reversi).*

SN-002: To repeat games, it SHALL be possible to store user input on file and to read the input back from file.


## Non-Functional Requirements

SN-101: The software SHALL be implemented in C++.

SN-102: The software SHALL use text based input and output for user interaction.

SN-103: The software SHALL run under Linux.

SN-104: The software source code SHOULD be structured such that each function comprises not more than 20 lines of code.

SN-105: Function parameters SHALL be handed over explicitly.

SN-106: The file format used for storing user input SHALL be readable for humans.

SN-107: The software SHALL be documented in Doxygen style.

SN-108: Software and development documentation SHALL use English language.

SN-109: Text-based development documentation SHALL be create in MarkDown format.

# System Requirements

SR-201 The software SHALL start the game on command. 

SR-202 The software SHALL initialize the game with 2 black und 2 white disks placed in the middle of the board. 

SR-203 The software SHALL be one of the two players.

SR-204 The software SHALL be able to replay a saved game on command.

SR-205 The software SHALL provide a menu for the user to pick between a new game or continuing a saved game.

SR-206 The software SHALL save every move of both players.

SR-207 The software SHALL finish the game WHEN all the squares are full.

SR-208 The software SHALL finish the game WHEN both players have no valid moves.

SR-209 The software SHALL display the final score WHEN the game is finished.

SR-210 The software SHALL pass the current player WHEN there are no valid moves available. 

SR-211 The software SHOULD display the score after every move.

SR-212 WHEN the game is finished the software SHALL give the player the option to replay the game or exit the game.

SR-213 The software SHALL give the player the option to quit the game at anytime without saving with the input 'exit'.

SR-214 WHILE the game is running the software SHALL allow the system to place the disc only on valid squares and after the player played.

SR-215 WHEN a player places a disc that is **horizontal** in line to one of his discs and between them are enemy disc THEN the system SHALL flip all discs in between.

SR-216 WHEN a player places a disc that is **vertical** in line to one of his discs and between them are enemy disc THEN the system SHALL flip all discs in between.

SR-217 WHEN a player places a disc that is **diagonal** in line to one of his discs and between them are enemy disc THEN the system SHALL flip all discs in between.

SR-218 WHEN a player places a disc that is: **horizontal, vertical and diagonal** to his discs and between them are enemy discs the player SHALL win all of the enemys disc in between.

SR-219 The user SHALL see his input on the console.

SR-220 The player SHALL only be able to make valid moves on the board.

SR-221 The system SHALL wait upon the user's input.

SR-222 The user SHALL decide, which character his discs ('W' or 'B') shall have at the start of the game.

SR-223 The software SHALL show played discs as an 'W' or 'B' on the board.

SR-224 The software SHALL show squares, which are no valid moves as an '-' on the board.

SR-225 The software SHALL show squares, which allow valid moves as an '+' on the board.

SR-226 The user SHALL be able to navigate the actions(start, reload, save....) with shortened character inputs.

SR-227 The user SHALL give the input as coordinates with a character between A & H for the row and a number between 1 & 8 for the column (i.e. 'H8') to make his move.

SR-228 The user SHALL be able to stop and save the game at any point with the input('SS'/'ss').

SR-229 The system SHALL display all possible commands WHEN the user makes a wrong input.

SR-230 IF the user makes an invalid move THEN the system SHALL notify the user with the message 'wrong move'.

SR-231 WHEN the user starts the software the user sees an output where he can decide between start a new game or reload (i.e Start a new game (s) or reload a game (r))

SR-232 WHILE the user is in an active game session, he can enter the submenu with the input 'o'.

SR-233 The KI/ computer SHALL only be able to play valid moves.

SR-234 The KI/ computer SHALL follow at least one AI Strategy.

SR-235 The KI/ computer SHOULD follow all AI Strategies in a predefined order.

SR-236 The software SHALL provide a saved file format as shown in save_file(1..N).txt.
