
#ifndef ENTITY_CLASS_HPP
#define ENTITY_CLASS_HPP
  #include "../include/settingClass.hpp"

class EntityClass {
private:
  // Player Inf
  int _playerPosX;
  int _playerPosY;
  int _playerSize;
  SettingClass _settingRef;
  //Road Inf

public:
  EntityClass(SettingClass setting): _settingRef(setting) {
    _playerPosX = (_settingRef.getWindowSizeX() / 2) - 3;
    _playerPosY = _settingRef.getWindowSizeY() - (_settingRef.getWindowSizeY() / 5);
    _playerSize = 2;
  };
  int getPlayerPosX();
  int getPlayerPosY();
  int getPlayerSize();
  void drawPlayer();
};

#endif