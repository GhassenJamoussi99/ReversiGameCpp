#include <iostream>

#include "computer.h"
#include "reversigame.h"
#include "reversiboard.h"
#include "log.h"

#include <vector>
#include <utility>
#include <cstdlib>

void Computer::move(ReversiGame *game)
{
    LOG(INFO) << "Computer::move()";

    // Use current time as seed for random generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Priority 1 : Corners
    this->cornersRules(game);
    // Priority 2 : DangerZone
    this->dangerZoneRules(game);
    // Priority 3 : Isolated C Square
    this->isolatedCSquareRules(game);
    // Priority 4 : Randomize
    this->randomRules(game);
    // Else pass
    
    LOG(INFO) << "Computer color = "<< getComputerColor();

    if (false == priority_4 && false == priority_3 &&
        false == priority_1 && false == priority_2)
    {
        LOG(INFO) << "Computer will pass";
    }
}

void Computer::cornersRules(ReversiGame *game)
{
    ReversiBoard *reversiboard = game->getReversiBoard();
    bool corner_available = false;

    // Priority 1 : Corners
    if (priority_1)
    {
        LOG(INFO) << "Checking priority 1";
        if (reversiboard->getBoardCell(0, 0) == '+')
        {
            valid_moves.push_back(std::make_pair(0, 0));
            corner_available = true;
        }

        if (reversiboard->getBoardCell(7, 0) == '+')
        {
            valid_moves.push_back(std::make_pair(7, 0));
            corner_available = true;
        }

        if (reversiboard->getBoardCell(0, 7) == '+')
        {
            valid_moves.push_back(std::make_pair(0, 7));
            corner_available = true;
        }

        if (reversiboard->getBoardCell(7, 7) == '+')
        {
            valid_moves.push_back(std::make_pair(7, 7));
            corner_available = true;
        }

        if (false == corner_available)
            priority_1 = false;

        if (priority_1)
        {
            LOG(INFO) << "Priority 1 is valid: Corner(s) is/are available";
            unsigned int r = (unsigned int)(rand() % valid_moves.size());
            reversiboard->setBoardCell(valid_moves[r].first, valid_moves[r].second, getComputerColor());
            LOG(INFO) << "Set in current board for computer " << valid_moves[r].first << " " << valid_moves[r].second;
            reversiboard->setupDiscRulesForComputer(valid_moves[r].first, valid_moves[r].second, game);
            // finished
        }
    }
}

void Computer::dangerZoneRules(ReversiGame *game)
{
    ReversiBoard *reversiboard = game->getReversiBoard();

    /* Priority 2 : Danger zone
     Trigger when :
      - No valid corners are available.
    */
    valid_moves.clear();
    if (true == priority_2 && false == priority_1)
    {
        LOG(INFO) << "Checking priority 2";
        for (int i = 0; i < 8; i++)
        {
            if (false == priority_2)
                break;
            for (int j = 0; j < 8; j++)
            {
                // first horizontal row of danger zone
                // second horizontal row of danger zone
                // first vertical and left row of danger zone
                // second vertical and right row of danger zone
                bool dangerZone = (j >= 1 && j <= 6 && i == 1) ||
                                  (j >= 1 && j <= 6 && i == 6) ||
                                  (i >= 1 && i <= 6 && j == 1) ||
                                  (i >= 1 && i <= 6 && j == 6);

                // if there's a piece to place outside the danger zone
                if (false == dangerZone && reversiboard->getBoardCell(i, j) == '+')
                {
                    priority_2 = false;
                    break;
                }
                else if (true == dangerZone && true == priority_2)
                {
                    // valid moves in the danger zone
                    valid_moves.push_back(std::make_pair(i, j));
                }
            }
        }

        // if there are places only in the danger zone
        if (priority_2)
        {
            LOG(INFO) << "Priority 2 is valid: Valid moves are only in the danger zone";
            // set piece in random place in the danger zone
            unsigned int r = (unsigned int)(rand() % valid_moves.size());
            reversiboard->setBoardCell(valid_moves[r].first, valid_moves[r].second, getComputerColor());
            LOG(INFO) << "Set in current board for computer " << valid_moves[r].first << " " << valid_moves[r].second;
            reversiboard->setupDiscRulesForComputer(valid_moves[r].first, valid_moves[r].second, game);
            // finished
        }
    }
}

void Computer::isolatedCSquareRules(ReversiGame *game)
{
    ReversiBoard *reversiboard = game->getReversiBoard();

    /* Priority 3 : Isolated C-Squares Can be a trouble
     Trigger when :
      - No valid corners are available.
      - Disc can be placed outside the danger zone.
    */
    valid_moves.clear();
    if (true == priority_3 && false == priority_1 && false == priority_2)
    {
        LOG(INFO) << "Checking priority 3";
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                bool dangerZoneC = (0 == i && 1 == j) || (1 == i && 0 == j) || (6 == i && 0 == j) || (7 == i && 1 == j) | (0 == i && 6 == j) || (1 == i && 7 == j) || (6 == i && 7 == j) || (7 == i && 6 == j);

                // if there's a piece outside the danger zone of C-Square
                if (false == dangerZoneC && reversiboard->getBoardCell(i, j) == '+')
                {
                    priority_3 = false;
                    break;
                }
                else if (true == dangerZoneC && true == priority_3)
                {
                    // valid moves in the danger zone of C-Square
                    valid_moves.push_back(std::make_pair(i, j));
                }
            }
        }

        // if there are places only in the danger zone of C-Square
        if (priority_3)
        {
            LOG(INFO) << "Priority 3 is valid: Valid moves are only in the danger zone of C-Square";
            // set piece in random place in the danger zone of C-Square
            unsigned int r = (unsigned int)(rand() % valid_moves.size());
            reversiboard->setBoardCell(valid_moves[r].first, valid_moves[r].second, getComputerColor());
            LOG(INFO) << "Set in current board for computer " << valid_moves[r].first << " " << valid_moves[r].second;
            reversiboard->setupDiscRulesForComputer(valid_moves[r].first, valid_moves[r].second, game);
            // finished
        }
    }
}

void Computer::randomRules(ReversiGame *game)
{
    ReversiBoard *reversiboard = game->getReversiBoard();
    LOG(INFO) << "Checking priority 4";
    valid_moves_safe.clear();

    if (true == priority_4 && false == priority_3 && false == priority_1 && false == priority_2) {
        //save safe moves without the danger zone in a vector
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                bool dangerZoneC = (0 == i && 1 == j) || (1 == i && 0 == j) || 
                                   (6 == i && 0 == j) || (7 == i && 1 == j) ||
                                   (0 == i && 6 == j) || (1 == i && 7 == j) || 
                                   (6 == i && 7 == j) || (7 == i && 6 == j);

                bool dangerZone = (j >= 1 && j <= 6 && i == 1) ||
                                  (j >= 1 && j <= 6 && i == 6) ||
                                  (i >= 1 && i <= 6 && j == 1) ||
                                  (i >= 1 && i <= 6 && j == 6);

                if (false == dangerZoneC && false == dangerZone && reversiboard->getBoardCell(i, j) == '+')
                    valid_moves_safe.push_back(std::make_pair(i, j));
            }
        }

        if (0 == valid_moves_safe.size()){
            priority_4 = false;
        }        
    }

    // if there are valid moveis
    if (priority_4)
    {
        LOG(INFO) << "Priority 4 is valid: Random square";

        // set piece in random place in the danger zone of C-Square
        unsigned int r = (unsigned int)(rand() % valid_moves_safe.size());
        reversiboard->setBoardCell(valid_moves_safe[r].first, valid_moves_safe[r].second, getComputerColor());
        LOG(INFO) << "Set in current board for computer " << valid_moves_safe[r].first << " " << valid_moves_safe[r].second;
        reversiboard->setupDiscRulesForComputer(valid_moves_safe[r].first, valid_moves_safe[r].second, game);
        // finished
    }
}
