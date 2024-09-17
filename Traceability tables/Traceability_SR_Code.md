# Traceability Table

### SR = System Requirement
&nbsp;

| Classes | Game | Menu | FileManager |  ReversiBoard | Placeholder | Discs | Player | User | Computer |
|   --   |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |     
| **SR-201** The software SHALL start the game on command. |  X  |  X |
| **SR-202** The software SHALL initialize the game with 2 black und 2 white disks placed in the middle of the board. |     |  |  | X |
| **SR-203** The software SHALL be one user versus the KI. |    |  |  | | | |X |X  | X| 
| **SR-204** The software SHALL be able to replay a saved game on command. |      | X | X |
| **SR-205** The software SHALL provide a menu for the user to pick between a new game or continuing a saved game. |      | X | X |
| **SR-206** The software SHALL show every move of both players. |          | | | X| 
| **SR-207** The software SHALL finish the game WHEN all the squares are full. |   X      |
| **SR-208** The software SHALL finish the game WHEN both players have no valid moves. |  X   |
| **SR-209** The software SHALL display the final score WHEN the game is finshed.|    X    |
| **SR-210** The software SHALL pass the current player WHEN there are no valid moves available.|    X   |
| **SR-211** The software SHOULD display the score after every move.|     X  |
| **SR-212** WHEN the game is finished the software SHALL give the player the option to replay the game or exit the game.|   X     |  X |
| **SR-213** The software SHALL give the player the option to quit the game at anytime without saving with the input 'exit'. |  | X    |
| **SR-214** WHILE the game is running the software SHALL allow the system to place the disc only on valid squares and after the player played. |    |   |    |  X  |  X  |   |  X |
| **SR-215** WHEN a player places a disc that is horizontal in line to one of his discs and between them are enemy disc THEN the system SHALL flip all discs in between. |   |  |  | X  | | X |
| **SR-216** WHEN a player places a disc that is vertical in line to one of his discs and between them are enemy disc THEN the system SHALL flip all discs in between. |   |  |  | X  | | X |
| **SR-217** WHEN a player places a disc that is diagonal in line to one of his discs and between them are enemy disc THEN the system SHALL flip all discs in between. |  |  |  | X  | | X |
| **SR-218** WHEN a player places a disc that is: horizontal, vertical and diagonal to his discs and between them are enemy discs the player SHALL win all of the enemys disc in between. |  |  |  | X  | | X |
| **SR-219** The user SHALL see his input on the console. |   X | X |   | X |
| **SR-220** The player SHALL only be able to make valid moves on the board.|    |  |  |   | X |
| **SR-221** The system SHALL wait upon the user's input. |    | | | | | | X      |
| **SR-222** The user SHALL decide, which character his discs ('W' or 'B') shall have at the start of the game.|  | | | | | | | X   |
| **SR-223** The software SHALL show played discs as an 'W' or 'B' on the board.|    | | | X  |
| **SR-224** The software SHALL show squares, which are no valid moves as an '-' on the board. |  | | |X | X   |
| **SR-225** The software SHALL show squares, which allow valid moves as an '+' on the board. |  | | |X | X   |
| **SR-226** The user SHALL be able to navigate the actions(start, reload, save....) with shortened character inputs. | X | X    |
| **SR-227** The user SHALL give the input as coordinates with a character between A & H for the row and a number between 1 & 8 for the column (i.e. 'H8') to make his move. |  | | |X   | | | | X |
| **SR-228** The user SHALL be able to stop and save the game at any point with the input('SS'/'ss'). |   | X  | X    |
| **SR-229** The system SHALL display all possible commands WHEN the user makes a wrong input. |  X |
| **SR-230** IF the user makes an invalid move THEN the system SHALL notify the user with the message 'wrong move'.   |   |   | | |  | | | X|
| **SR-231** WHEN the user starts the software the user sees an output where he can decide between start a new game or reload (i.e Start a new game (s) or reload a game (r)). |   X  | X  | X  |
| **SR-232** WHILE the user is in an active game session, he can enter the submenu with the input 'o'. | X | 
| **SR-233** The KI/ computer SHALL only be able to play valid moves. | | | | | | | | | X |
| **SR-234** The KI/ computer SHALL follow at least one [AI Strategy](https://gitlab.rz.htw-berlin.de/m14_vv/2022ws_team2a/-/blob/main/Use%20Cases/AI_strategy.md) . | | | | | | | | | X |
| **SR-235** The KI/ computer SHOULD follow all [AI Strategies](https://gitlab.rz.htw-berlin.de/m14_vv/2022ws_team2a/-/blob/main/Use%20Cases/AI_strategy.md) in a predefined order. | | | | | | | | | X |
| **SR-236** The software SHALL provide a saved file format as shown in save_file(1..N).txt. | | | X | | 

