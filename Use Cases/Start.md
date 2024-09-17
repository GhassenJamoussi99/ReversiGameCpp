# Use cases

## Use case 1: Start game

| **Actors**                       |        |
| -------------------------------- | ------ |
| Primary actors                   |Player      |
| Secondary actors                 |System    |
| **Preconditions**                |Game option is selected     |
| **Scenario sketch**              |![flow chart: load](/Use%20Cases/imgs/start.PNG)     |
| **Standard flow**                    |Step 1:The player starts the game  |
|                                  |Step 2:The player selects the black disc |
|                                  |Step 3:The system runs the game|
| **Alternative / exceptional flow 1** |Step 1:The player starts the game |
|                                  |Step 2:The player selects white disc  |
|                                  |Step 3:The system runs the game|
| **Postconditions**               |The game is running      |


## Use case 2: Pause the game 

| **Actors**                       |        |
| -------------------------------- | ------ |
| Primary actors                   |Player      |
| Secondary actors                 |System |
| **Preconditions**                |The game is on run mode     |
| **Scenario sketch**              | ![flow chart: load](/Use%20Cases/imgs/pause.PNG)        |
| **Standard flow**                    |Step 1:The player click on return button |
|                                  |Step 2:The system saves the current state of the game|
|                                  |Step 3:The system shows a list of options|
| **Alternative / exceptional flow 1** |Step 1:The system shows a list of options|
|                                  |Step 2:The player chooses the option "Cancel"|
|                                  |Step 3:The system returns to the recent state of the game|
| **Alternative / exceptional flow 2** |Step 1:The system shows a list of options|
|                                  |Step 2:The player chooses the option "Exit"  |
|                                  |Step 3:The system ends and switch off the game|
| **Postconditions**               |The game can be resumed or ended|




## Use case 3:  Show result 

| **Actors**                       |        |
| -------------------------------- | ------ |
| Primary actors                   |System     |
| Secondary actors                 |    -    |
| **Preconditions**                |The game is ended   |
| **Scenario sketch**              |![flow chart: load](/Use%20Cases/imgs/score.PNG) |
|  **Standard flow**                   |Step 1:The game score is displayed   |
| **Postconditions**               |A list can be displayed with top scores     |







