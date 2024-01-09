#include <cstdint>
#include <string>
class Code {
  public:
    uint8_t dest(char* mnemonic){
      uint8_t ret = 0;
      uint8_t index = 0;
      while(mnemonic[index] != '=') {
        switch (mnemonic[index]) {
          case 'A':
            ret |= 4;
            break;
          case 'D':
            ret |= 2;
            break;
          default:
            ret |= 1;
        }
        index++;
      }
      return ret;
    }

    uint8_t comp(char* mnemonic){
      uint8_t index = 0;

      switch (mnemonic[index]) {
        case '0':
          return 42;
        case '1': 
          return 63;
        case '-':
          switch(mnemonic[index+1]) {
            case '1':
              return 58;
            case 'D':
              return 15;
            case 'A':
              return 51;
            case 'M':
              return 115;
          }
          break;
        case '!':
          switch (mnemonic[index+1]) {
            case 'D':
              return 8;
            case 'A':
              return 49;
            case 'M':
              return 113;
          }
          break;
        case 'D':
          switch (mnemonic[index+1]) {
            case '+':
              switch (mnemonic[index+2]) {
                case '1':
                  return 31;
                case 'A':
                  return 2;
                case 'M':
                  return 66;
              }
              break;
            case '-':
              switch (mnemonic[index+2]) {
                case '1':
                  return 14;
                case 'A':
                  return 19;
                case 'M':
                  return 83;
              }
              break;
            case '&':
              switch (mnemonic[index+2]) {
                case 'A':
                  return 0;
                case 'M':
                  return 64;
              }
              break;
            case '|':
              switch (mnemonic[index+2]) {
                case 'A':
                  return 21;
                case 'M':
                  return 85;
              }
              break;
            default:
              return 12;
          }
          break;
        case 'A':
          switch (mnemonic[index+1]) {
            case '+':
              return 55;
            case '-':
              switch (mnemonic[index+2]) {
                case '1':
                  return 50;
                case 'D':
                  return 7;
              }
              break;
            default:
              return 48;
          }
          break;
        case 'M':
          switch (mnemonic[index+1]) {
            case '+':
              return 119;
            case '-':
              switch (mnemonic[index+2]) {
                case '1':
                  return 114;
                case 'D':
                  return 71;
              }
              break;
            default:
              return 112;
          }
          break;
      }
      return 42;
    }
    uint8_t jump(char* mnemonic){
      uint8_t index = 0;
      switch (mnemonic[index]) {
        case 'E':
          return 2;
        case 'G':
          switch (mnemonic[index+1]) {
            case 'E':
              return 3;
            case 'T':
              return 1;
          }
          break;
        case 'L':
          switch (mnemonic[index+1]) {
            case 'E':
              return 6;
            case 'T':
              return 4;
          }
          break;
        case 'M':
          return 7;
        case 'N':
          return 5;
      }
    return 0;
  }
};
