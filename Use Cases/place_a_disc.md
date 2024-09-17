## Use case: Place a disc

| **Actors**                       |        |
| -------------------------------- | ------ |
| Primary actors                   | Player |
| Secondary actors                 | System |
| **Preconditions**                | The game is running. |
| **Scenario sketch**              | <img src="imgs/place_a_disc.png" width="300"/>      |
| Standard flow                    | Step 1: Player places a disc in a valid square. |
|                                  | Step 2: System places a disc in a valid square. |
| Alternative / exceptional flow 1 | Step 1: Player passes as no valid square is available. |
| Alternative / exceptional flow 2 | Step 2: System passes as no valid square is available. |
| **Postconditions**               | Disc is placed successfully. |
