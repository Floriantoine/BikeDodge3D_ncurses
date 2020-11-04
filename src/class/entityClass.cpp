#include "../../include/entityClass.hpp"

int EntityClass::getPlayerPosX() {
  return _playerPosX;
}

int EntityClass::getPlayerPosY() {
  return _playerPosY;
}

int EntityClass::getPlayerSize() {
  return _playerSize;
}

void EntityClass::drawPlayer() {
    int loop = 0;

    while (loop < _playerSize) {
        mvaddch(_playerPosY, _playerPosX + loop, '#');
        mvaddch(_playerPosY + 1, _playerPosX + loop, '#');
        mvaddch(_playerPosY + 2, _playerPosX + loop, '#');
        loop++;
    }
}