
#ifndef SETTING_CLASS_HPP
#define SETTING_CLASS_HPP
  #include <ncurses.h>
  #include <time.h>

class SettingClass {
private:
  // Player Inf
  int _windowSizeX;
  int _windowSizeY;
  clock_t _clock;
  bool _gameState;

  //Road Inf

public:
  SettingClass() {
    _gameState = true;
    _clock = clock();

    initscr();
    getmaxyx(stdscr, _windowSizeY, _windowSizeX);
  };
  int getWindowSizeX();
  int getWindowSizeY();
  clock_t restartClock();
  clock_t getClock();
  bool getGameState();
  void setGameState(bool state);
};

#endif