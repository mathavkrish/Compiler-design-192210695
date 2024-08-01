public Token scan() throws IOException, SyntaxException{
  for(;;peek = (char)stream.read()){
    if(peek == ' ' || peek == '\t'){
      continue;
    }else if(peek == '\n'){
      line = line + 1;
    }else{
      break;
    }
  }

  // handle comment
  if(peek == '/'){
    peek = (char) stream.read();
    if(peek == '/'){
      // single line comment
      for(;;peek = (char)stream.read()){
        if(peek == '\n'){
          break;
        }
      }
    }else if(peek == '*'){
      // block comment
      char prevPeek = ' ';
      for(;;prevPeek = peek, peek = (char)stream.read()){
        if(prevPeek == '*' && peek == '/'){
          break;
        }
      }
    }else{
      throw new SyntaxException();
    }
  }

  // handle relation sign
  if("<=!>".indexOf(peek) > -1){
    StringBuffer b = new StringBuffer();
    b.append(peek);
    peek = (char)stream.read();
    if(peek == '='){
      b.append(peek);
    }
    return new Rel(b.toString());
  }

  // handle number, no type sensitive
  if(Character.isDigit(peek) || peek == '.'){
    Boolean isDotExist = false;
    StringBuffer b = new StringBuffer();
    do{
      if(peek == '.'){
        isDotExist = true;
      }
      b.append(peek);
      peek = (char)stream.read();
    }while(isDotExist == true ? Character.isDigit(peek) : Character.isDigit(peek) || peek == '.');
    return new Num(new Float(b.toString()));
  }

  // handle word
  if(Character.isLetter(peek)){
    StringBuffer b = new StringBuffer();
    do{
      b.append(peek);
      peek = (char)stream.read();
    }while(Character.isLetterOrDigit(peek));
    String s = b.toString();
    Word w = words.get(s);
    if(w == null){
      w = new Word(Tag.ID, s);
      words.put(s, w);
    }
    return w;
  }

  Token t = new Token(peek);
  peek = ' ';
  return t;
}
