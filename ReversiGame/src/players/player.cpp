#include "player.h"

void Player::changeTurn()
{
    userTurn = !userTurn;
}

bool Player::getUserTurn()
{
    return userTurn;
}

char Player::getUserColor()
{
    return userColor;
}

char Player::getComputerColor()
{
    return computerColor;
}

void Player::setUserColor(char color)
{
  userColor = color;
}

void Player::setComputerColor(char color)
{
  computerColor = color;
}