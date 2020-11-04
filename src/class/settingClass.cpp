#include "../../include/settingClass.hpp"

int SettingClass::getWindowSizeX() {
  return _windowSizeX;
}

int SettingClass::getWindowSizeY() {
  return _windowSizeY;
}

/**
 * @brief Restart Time
 *
 * @return Time before restart
 */
clock_t SettingClass::restartClock() {
  clock_t tempo = _clock;
  _clock = clock();
  return tempo;
}

clock_t SettingClass::getClock() {
  return _clock;
}

bool SettingClass::getGameState() {
  return _gameState;
}

void SettingClass::setGameState(bool state) {
  _gameState = state;
}