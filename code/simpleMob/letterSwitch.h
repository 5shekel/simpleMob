byte nextTempLetter (byte key) {
  if (lang == HEBREW) {
    switch (key) {
    case 0:
      switch (tempLetter) {
      case NO_LETTER:
        return 0x20;
        break;
      case 0x20:
        return '0';
        break;
      case '0':
        return 0x20;
        break;
      }
      break;

    case 1:
      switch (tempLetter) {
      case NO_LETTER:
        return '.';
        break;
      case '.':
        return ',';
        break;
      case ',':
        return '?';
        break;
      case '?':
        return '!';
        break;
      case '!':
        return '1';
        break;
      case '1':
        return '.';
        break;
      }
      break;

    case 2:
      switch (tempLetter) {
      case NO_LETTER:
        return 0x83;
        break;
      case 0x83:
        return 0x84;
        break;
      case 0x84:
        return 0x85;
        break;
      case 0x85:
        return '2';
        break;
      case '2':
        return 0x83;
        break;
      }
      break;

    case 3:
      switch (tempLetter) {
      case NO_LETTER:
        return 0x80;
        break;
      case 0x80:
        return 0x81;
        break;
      case 0x81:
        return 0x82;
        break;
      case 0x82:
        return '3';
        break;
      case '3':
        return 0x80;
        break;
      }
      break;

    case 4:
      switch (tempLetter) {
      case NO_LETTER:
        return 0x8e;
        break;
      case 0x8e:
        return 0x8d;
        break;
      case 0x8d:
        return 0x90;
        break;
      case 0x90:
        return 0x8f;
        break;
      case 0x8f:
        return '4';
        break;
      case '4':
        return 0x8e;
        break;
      }
      break;

    case 5:
      switch (tempLetter) {
      case NO_LETTER:
        return 0x89;
        break;
      case 0x89:
        return 0x8b;
        break;
      case 0x8b:
        return 0x8a;
        break;
      case 0x8a:
        return 0x8c;
        break;
      case 0x8c:
        return '5';
        break;
      case '5':
        return 0x89;
        break;
      }
      break;

    case 6:
      switch (tempLetter) {
      case NO_LETTER:
        return 0x86;
        break;
      case 0x86:
        return 0x87;
        break;
      case 0x87:
        return 0x88;
        break;
      case 0x88:
        return '6';
        break;
      case '6':
        return 0x86;
        break;
      }
      break;

    case 7:
      switch (tempLetter) {
      case NO_LETTER:
        return 0x98;
        break;
      case 0x98:
        return 0x99;
        break;
      case 0x99:
        return 0x9a;
        break;
      case 0x9a:
        return '7';
        break;
      case '7':
        return 0x98;
        break;
      }
      break;

    case 8:
      switch (tempLetter) {
      case NO_LETTER:
        return 0x96;
        break;
      case 0x96:
        return 0x95;
        break;
      case 0x95:
        return 0x97;
        break;
      case 0x97:
        return '8';
        break;
      case '8':
        return 0x96;
        break;
      }
      break;

    case 9:
      switch (tempLetter) {
      case NO_LETTER:
        return 0x91;
        break;
      case 0x91:
        return 0x92;
        break;
      case 0x92:
        return 0x94;
        break;
      case 0x94:
        return 0x93;
        break;
      case 0x93:
        return '9';
        break;
      case '9':
        return 0x91;
        break;
      }
      break;

    }
  } 
  else {
    // *********************** English *************************
    switch (key) {
    case 0:
      switch (tempLetter) {
      case NO_LETTER:
        return 0x20;
        break;
      case 0x20:
        return '0';
        break;
      case '0':
        return 0x20;
        break;
      }
      break;

    case 1:
      switch (tempLetter) {
      case NO_LETTER:
        return '.';
        break;
      case '.':
        return ',';
        break;
      case ',':
        return '?';
        break;
      case '?':
        return '!';
        break;
      case '!':
        return 0x60;
        break;
      case 0x60:
        return '1';
        break;
      case '1':
        return '.';
        break;
      }
      break;

    case 2:
      switch (tempLetter) {
      case NO_LETTER:
        return 'A';
        break;
      case 'A':
        return 'B';
        break;
      case 'B':
        return 'C';
        break;
      case 'C':
        return '2';
        break;
      case '2':
        return 'A';
        break;
      }
      break;

    case 3:
      switch (tempLetter) {
      case NO_LETTER:
        return 'D';
        break;
      case 'D':
        return 'E';
        break;
      case 'E':
        return 'F';
        break;
      case 'F':
        return '3';
        break;
      case '3':
        return 'D';
        break;
      }
      break;

    case 4:
      switch (tempLetter) {
      case NO_LETTER:
        return 'G';
        break;
      case 'G':
        return 'H';
        break;
      case 'H':
        return 'I';
        break;
      case 'I':
        return '4';
        break;
      case '4':
        return 'G';
        break;
      }
      break;

    case 5:
      switch (tempLetter) {
      case NO_LETTER:
        return 'J';
        break;
      case 'J':
        return 'K';
        break;
      case 'K':
        return 'L';
        break;
      case 'L':
        return '5';
        break;
      case '5':
        return 'J';
        break;
      }
      break;

    case 6:
      switch (tempLetter) {
      case NO_LETTER:
        return 'M';
        break;
      case 'M':
        return 'N';
        break;
      case 'N':
        return 'O';
        break;
      case 'O':
        return '6';
        break;
      case '6':
        return 'M';
        break;
      }
      break;

    case 7:
      switch (tempLetter) {
      case NO_LETTER:
        return 'P';
        break;
      case 'P':
        return 'Q';
        break;
      case 'Q':
        return 'R';
        break;
      case 'R':
        return 'S';
        break;
      case 'S':
        return '7';
        break;
      case '7':
        return 'P';
        break;
      }
      break;

    case 8:
      switch (tempLetter) {
      case NO_LETTER:
        return 'T';
        break;
      case 'T':
        return 'U';
        break;
      case 'U':
        return 'V';
        break;
      case 'V':
        return '8';
        break;
      case '8':
        return 'T';
        break;
      }
      break;

    case 9:
      switch (tempLetter) {
      case NO_LETTER:
        return 'W';
        break;
      case 'W':
        return 'X';
        break;
      case 'X':
        return 'Y';
        break;
      case 'Y':
        return 'Z';
        break;
      case 'Z':
        return '9';
        break;
      case '9':
        return 'W';
        break;
      }
      break;
    }
  } 
}

