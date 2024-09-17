## Use case: Restart

| **Actors**                       |        |
| -------------------------------- | ------ |
| Primary actors                   | Player       |
| Secondary actors                 | System       |
| **Preconditions**                | The game is on run mode.   |
| **Scenario sketch**              | ![flow chart: restart](/Use%20Cases/imgs/reset.png)       |
| Standard flow                    | Step 1: The Player selects the return option. |
|                                  | Step 2: The System shows the list of options. |
|                                  | Step 3: The Player chooses the "restart" option. |
|                                  | Step 4: The System asks for a confirmation.  |
|                                  | Step 5: The Player confirms the action.  |
|                                  | Step 6: The System returns to a new game session.  |
|                                  | Step 7: The Use Case ends successful.  |
| Alternative / exceptional flow 1 | Step 1: The Player selects the return option. |
|                                  | Step 2: The System shows the list of options.   |
|                                  | Step 3: The player chooses the option "Cancel".   |
|                                  | Step 4: The Use Case ends unsuccessful.    |
| Alternative / exceptional flow 2 | Step 1: The Player selects the return option. |
|                                  | Step 2: The System shows the list of options.   |
|                                  | Step 3: The Player chooses the "restart" option.   |
|                                  | Step 4: The System asks for a confirmation.    |
|                                  | Step 5: The Player rejects the action.  |
|                                  | Step 6: The Use Case ends unsuccessful.    |
| **Postconditions**               | The board has been reset to a new game.    |
