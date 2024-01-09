#include <fstream>
#include <cstdint>

enum Command{A_COMMAND, C_COMMAND, L_COMMAND};

class Parser {
  public:
    Parser();
    ~Parser();
    bool hasMoreCommands();
    void advance();
    Command commandType();
    char* symbol();
    char* dest();
    char* comp();
    char* jump();

  private:
    std::ifstream file;
    char current_command[12];
};

