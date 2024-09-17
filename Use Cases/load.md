## Use case: Load Game State

| **Actors**                       |        |
| -------------------------------- | ------ |
| Primary actors                   | Player       |
| Secondary actors                 | System       |
| **Preconditions**                |  The program is running in the main menu.   |
| **Scenario sketch**              | ![flow chart: load](/Use%20Cases/imgs/load.png)       |
| Standard flow                    | Step 1: The Player picks the "load" option. |
|                                  | Step 2: The System lists the saved game states. |
|                                  | Step 3: The Player picks one save file. |
|                                  | Step 4: The System loads the game state.  |
|                                  | Step 5: The Use Case ends successful.  |
| Alternative / exceptional flow 1 | Step 1: The Player picks the "load" option. |
|                                  | Step 2: The System shows a empty list.   |
|                                  | Step 3: The Use Case ends unsuccessful.    |
| Alternative / exceptional flow 2 | Step 1: The Player picks the "load" option.   |
|                                  | Step 2: The System lists the saved game states.   |
|                                  | Step 3: The Player goes back to the main menu to start a new game instead.    |
|                                  | Step 4: The Use Case ends unsuccessful.    |
| **Postconditions**               | A previous game session can be resumed.        |
