#ifndef SERVICE_HPP
#define SERVICE_HPP

class Service {
public:
  enum State {
    RUN,
    STOP,
    ERROR
  };

private:
  State _state;

protected:
  inline void setState(State state) {
    _state = state;
  }

public:
  inline State state(void) {
    return _state;
  }

public:
  inline Service(void) : _state(STOP) {}

public:
  inline void start(void) {
    if(_state == STOP) {
      _state = RUN;
    }
  }

  inline void stop(void) {
    if(_state == RUN) {
      _state = STOP;
    }
  }
};

#endif//SERVICE_HPP
