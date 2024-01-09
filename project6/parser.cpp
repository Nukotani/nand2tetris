#include <fstream>
#include <cstdint>

enum Command{A_COMMAND, C_COMMAND, L_COMMAND};

class Parser {
  public:
    Parser(char* filename);
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

    void copy(char* source, char* dest, uint8_t n);
};

Parser::Parser(char* filename) {
  file.open(filename);
}

Parser::~Parser() {
  file.close();
}

bool Parser::hasMoreCommands() {
  return !file.eof();
}

void Parser::advance() {
  char buff[12];
  do {
    file.getline(buff, 12);
  } while(buff[0] == '#');
  copy(buff, current_command, 12);
}

Command Parser::commandType() {
  switch(current_command[0]) {
    case '(':
      return L_COMMAND;
    case '@':
      return A_COMMAND;
    default:
      return C_COMMAND;
  }
}

char* Parser::symbol() {
  static char buffer[1024];
  uint8_t index = 1;

  do{
    buffer[index] = current_command[index];
  }while(buffer[index] != ')' | buffer[index] != '\0');
  return buffer;
}

char* Parser::comp() {

}

void Parser::copy(char* source, char* dest, uint8_t n){
  for(int i = 0; i < n; i++){
    dest[i] = source[i];
  }
}
