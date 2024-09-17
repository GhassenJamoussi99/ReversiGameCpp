## Use case: Save

| **Actors**                       |        |
| -------------------------------- | ------ |
| Primary actors                   | Player       |
| Secondary actors                 | System       |
| **Preconditions**                |  The game is running.   |
| **Scenario sketch**              | <img src="imgs/save.png" width="450"/>       |
| Standard flow                    | Step 1: Player selects "save" option. |
|                                  | Step 2: Player names new "save" file. |
|                                  | Step 3: System saves the state of the game in the new file. |
| Alternative / exceptional flow   | Step 2: Player chooses an existing "save" file.   |
|                                  | Step 3: System overwrites and saves the new state of the game in the existing file. |
| **Postconditions**               | Game state saved successfully.        |
