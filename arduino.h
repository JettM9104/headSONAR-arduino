typedef enum { OUTPUT, INPUT } mode;
typedef enum { HIGH, LOW } ud;

#include <string>

class serial {
private:
  int channel;
public:
  void begin(int chanel) { channel = chanel; }
  void print(std::string hi) {}
  void println(std::string hi) {}
  void println(int skibidi) {}
  void println(float skibidi) {}
  void print(int skibidi) {}
  void print(float skibidi) {}
};

serial Serial;

void pinMode(int number, mode io) {}
void digitalWrite(int number, ud state) {}
float pulseIn(int number, ud state) { return 0.0; }
void delayMicroseconds(int time) {}
void delay(int time) {}
void tone(int port, int pitch) {}
void noTone(int port) {}
bool digitalRead(int port) { return 0; }

