int ledsBoard[6][5] = { {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0} };
int latchpinCursor=9;
int datapinCursor=10;
int clockpinCursor=8;
int latchpinBoard=12;
int datapinBoard=13;
int clockpinBoard=11;
int buzzer=3;
int button1=14; //left
int button2=15; //center
int button3=16; //right
long future;
char userInput;

//CONNECT FOUR VARIABLES
int ledCursor;
boolean hasSomeoneWon;
boolean areThereAnySpacesLeft;
boolean WhoseTurn;
boolean firstTurn;

//PATTERN VARIABLES
int currentMode;
long lastTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  digitalWrite(latchpinCursor, LOW);
  digitalWrite(latchpinBoard, LOW);
  pinMode(latchpinBoard, OUTPUT);
  pinMode(clockpinBoard, OUTPUT);
  pinMode(datapinBoard, OUTPUT);
  pinMode(latchpinCursor, OUTPUT);
  pinMode(clockpinCursor, OUTPUT);
  pinMode(datapinCursor, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(buzzer, OUTPUT);
  adjustBoard();
  future=0;
  
  ledCursor = 1;
  hasSomeoneWon=false;
  areThereAnySpacesLeft=true;
  WhoseTurn=false;
  firstTurn=true;
  
  lastTime=0;
  currentMode=0;
  
  userInput = 0;
  Serial.println("Please pick a game. Enter 1 for CONNECT FOUR. Enter 2 for PATTERN.");
  while(Serial.available()<=0){}
  userInput=Serial.read(); 
  if(userInput=='1') adjustCursor1();
  else if(userInput=='2') adjustCursor2();
  Serial.println("Press 3 to go reselect a game");
}
//********MAIN LOOP*******
void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial.read()=='3') setup();
  if(userInput=='1')
    loop1();
  else if(userInput=='2')
    loop2();

  /*
  loop0();
  Serial.print(digitalRead(button1));
  Serial.print(" ");
  Serial.print(digitalRead(button2));
  Serial.print(" ");
  Serial.println(digitalRead(button3));
  */
}

void loop0(){ //TURNS ON ALL LEDs
  digitalWrite(latchpinCursor,LOW);
  shiftOut(datapinCursor, clockpinCursor, MSBFIRST, 255);
  shiftOut(datapinCursor, clockpinCursor, MSBFIRST, 255);
  digitalWrite(latchpinCursor,HIGH);

  digitalWrite(latchpinBoard,LOW);
  shiftOut(datapinBoard,clockpinBoard, MSBFIRST, 255);
  shiftOut(datapinBoard,clockpinBoard, MSBFIRST, 255);
  shiftOut(datapinBoard,clockpinBoard, MSBFIRST, 255);
  shiftOut(datapinBoard,clockpinBoard, MSBFIRST, 255);
  shiftOut(datapinBoard,clockpinBoard, MSBFIRST, 255);
  shiftOut(datapinBoard,clockpinBoard, MSBFIRST, 255);
  shiftOut(datapinBoard,clockpinBoard, MSBFIRST, 255);
  shiftOut(datapinBoard,clockpinBoard, MSBFIRST, 255);
  digitalWrite(latchpinBoard,HIGH);
}

void adjustBoard() {
  digitalWrite(latchpinBoard, LOW);
  int output1=0;
  int output2=0;
  int output3=0;
  int output4=0;
  int output5=0;
  int output6=0;
  int output7=0;
  int output8=0;

  if (ledsBoard[0][0] !=0) {
    if (ledsBoard[0][0] ==2) output1=output1+1;
    else output1=output1+2;
  }
  if (ledsBoard[1][0] !=0) {
    if (ledsBoard[1][0] ==2) output1=output1+4;
    else output1=output1+8;
  }
  if (ledsBoard[2][0] !=0) {
    if (ledsBoard[2][0] ==2) output1=output1+16;
    else output1=output1+32;
  }
  if (ledsBoard[3][0] !=0) {
    if (ledsBoard[3][0] ==2) output1=output1+64;
    else output1=output1+128;
  }
  if (ledsBoard[4][0] !=0) {
    if (ledsBoard[4][0] ==2) output2=output2+1;
    else output2=output2+2;
  }
  if (ledsBoard[5][0] !=0) {
    if (ledsBoard[5][0] ==2) output2=output2+4;
    else output2=output2+8;
  }
  if (ledsBoard[0][1] !=0) {
    if (ledsBoard[0][1] ==2) output2=output2+16;
    else output2=output2+32;
  }
  if (ledsBoard[1][1] !=0) {
    if (ledsBoard[1][1] ==2) output2=output2+64;
    else output2=output2+128;
  }
  if (ledsBoard[2][1] !=0) {
    if (ledsBoard[2][1] ==2) output3=output3+1;
    else output3=output3+2;
  }
  if (ledsBoard[3][1] !=0) {
    if (ledsBoard[3][1] ==2) output3=output3+4;
    else output3=output3+8;
  }
  if (ledsBoard[4][1] !=0) {
    if (ledsBoard[4][1] ==2) output3=output3+16;
    else output3=output3+32;
  }
  if (ledsBoard[5][1] !=0) {
    if (ledsBoard[5][1] ==2) output3=output3+64;
    else output3=output3+128;
  }
  if (ledsBoard[0][2] !=0) {
    if (ledsBoard[0][2] ==2) output4=output4+1;
    else output4=output4+2;
  }
  if (ledsBoard[1][2] !=0) {
    if (ledsBoard[1][2] ==2) output4=output4+4;
    else output4=output4+8;
  }
  if (ledsBoard[2][2] !=0) {
    if (ledsBoard[2][2] ==2) output4=output4+16;
    else output4=output4+32;
  }
  if (ledsBoard[3][2] !=0) {
    if (ledsBoard[3][2] ==2) output4=output4+64;
    else output4=output4+128;
  }
  if (ledsBoard[4][2] !=0) {
    if (ledsBoard[4][2] ==2) output5=output5+1;
    else output5=output5+2;
  }
  if (ledsBoard[5][2] !=0) {
    if (ledsBoard[5][2] ==2) output5=output5+4;
    else output5=output5+8;
  }
  if (ledsBoard[0][3] !=0) {
    if (ledsBoard[0][3] ==2) output5=output5+16;
    else output5=output5+32;
  }
  if (ledsBoard[1][3] !=0) {
    if (ledsBoard[1][3] ==2) output5=output5+64;
    else output5=output5+128;
  }
  if (ledsBoard[2][3] !=0) {
    if (ledsBoard[2][3] ==2) output6=output6+1;
    else output6=output6+2;
  }
  if (ledsBoard[3][3] !=0) {
    if (ledsBoard[3][3] ==2) output6=output6+4;
    else output6=output6+8;
  }
  if (ledsBoard[4][3] !=0) {
    if (ledsBoard[4][3] ==2) output6=output6+16;
    else output6=output6+32;
  }
  if (ledsBoard[5][3] !=0) {
    if (ledsBoard[5][3] ==2) output6=output6+64;
    else output6=output6+128;
  }
  if (ledsBoard[0][4] !=0) {
    if (ledsBoard[0][4] ==2) output7=output7+1;
    else output7=output7+2;
  }
  if (ledsBoard[1][4] !=0) {
    if (ledsBoard[1][4] ==2) output7=output7+4;
    else output7=output7+8;
  }
  if (ledsBoard[2][4] !=0) {
    if (ledsBoard[2][4] ==2) output7=output7+16;
    else output7=output7+32;
  }
  if (ledsBoard[3][4] !=0) {
    if (ledsBoard[3][4] ==2) output7=output7+64;
    else output7=output7+128;
  }
  if (ledsBoard[4][4] !=0) {
    if (ledsBoard[4][4] ==2) output8=output8+1;
    else output8=output8+2;
  }
  if (ledsBoard[5][4] !=0) {
    if (ledsBoard[5][4] ==2) output8=output8+4;
    else output8=output8+8;
  }
  //...
  shiftOut(datapinBoard, clockpinBoard, MSBFIRST, output8);
  shiftOut(datapinBoard, clockpinBoard, MSBFIRST, output7);
  shiftOut(datapinBoard, clockpinBoard, MSBFIRST, output6);
  shiftOut(datapinBoard, clockpinBoard, MSBFIRST, output5);
  shiftOut(datapinBoard, clockpinBoard, MSBFIRST, output4);
  shiftOut(datapinBoard, clockpinBoard, MSBFIRST, output3);
  shiftOut(datapinBoard, clockpinBoard, MSBFIRST, output2);
  shiftOut(datapinBoard, clockpinBoard, MSBFIRST, output1);
  digitalWrite(latchpinBoard, HIGH);
}

//********CONNECT FOUR METHODS***********
void loop1() {
  // put your main code here, to run repeatedly:
  //BUTTON CODE
  int b1State=digitalRead(button1);
  int b2State=digitalRead(button2);
  int b3State=digitalRead(button3);
  long now=millis();
  
  if (firstTurn==true) {
    long determination=random(0, 1);
    if (determination==0) WhoseTurn=true;
    else WhoseTurn=false;
    firstTurn=false;
  }
  if (areThereAnySpacesLeft==true) {
    areThereAnySpacesLeft=anySpacesLeft();
  }
  if (hasSomeoneWon==false && areThereAnySpacesLeft==true) {
    adjustCursor1();
    adjustBoard();
    if (b3State==1 && now>future) { //button 1 pressed (left)
      future=now+800;
      if (ledCursor == 1) ledCursor=6;
      else ledCursor = ledCursor-1;
    }
    else if (b1State==1 && now>future) { //button 3 pressed (right)
      future=now+800;
      if (ledCursor == 6) ledCursor=1;
      else ledCursor = ledCursor+1;
    }
    else if (b2State==1 && now>future) { //button 2 pressed (center)
      future=now+800;
      if (ledsBoard[ledCursor-1][4] != 0) {
        //do the error music thing
        tone(buzzer, 69.30);
        delay(500);
        noTone(buzzer);
      }
      else {
        if (ledsBoard[ledCursor-1][0] == 0) {
          if (WhoseTurn==false) 
            ledsBoard[ledCursor-1][0]=2; //red
          else 
            ledsBoard[ledCursor-1][0]=3; //green
          WhoseTurn=!WhoseTurn;
        }
        else {
          for (int test=4; test>0; test--) 
          {
            if (ledsBoard[ledCursor-1][test-1] != 0) 
            {
              if (WhoseTurn == false) 
                ledsBoard[ledCursor-1][test]=2;
              else 
                ledsBoard[ledCursor-1][test]=3;
              test = 0;
              WhoseTurn=!WhoseTurn;
            }
          }
        }
        hasSomeoneWon=didSomeoneWin(!WhoseTurn);
      }
    }
  }
  else if (hasSomeoneWon==true) {
    adjustBoard();
    int firstOutput = 0;
    int secondOutput = 0;
    digitalWrite(latchpinCursor, LOW);
    if (WhoseTurn==false) firstOutput=firstOutput+63;
    else {
      firstOutput=64+128;
      secondOutput=255;
    }
    shiftOut(datapinCursor, clockpinCursor, MSBFIRST, firstOutput);
    shiftOut(datapinCursor, clockpinCursor, MSBFIRST, secondOutput);
    digitalWrite(latchpinCursor, HIGH);
    playSoundEffects(0);
    boolean temp=false;
    if((b1State==1 && now>future)|| (b2State==1 && now>future) || (b3State==1 && now>future)) temp=true;
    if (temp==true) resetGame();
  }
  //situation for draw
  else if (areThereAnySpacesLeft==false) {
    digitalWrite(latchpinCursor, LOW);
    shiftOut(datapinCursor, clockpinCursor, MSBFIRST, 149);
    shiftOut(datapinCursor, clockpinCursor, MSBFIRST, 10);
    playSoundEffects(1);
    boolean temp=false;
    if((b1State==1 && now>future)|| (b2State==1 && now>future) || (b3State==1 && now>future)) temp=true;
    if (temp==true) resetGame();
  }
}

void playSoundEffects(int whichOne) {
  if (whichOne==0) {
    //a5, b5, c6
    if (millis()%3500<500) tone(buzzer, 880.00);
    else if (millis()%3500<1000) tone(buzzer, 987.77);
    else if (millis()%3500<1500) noTone(buzzer);
    else if (millis()%3500<2000) tone(buzzer, 1046.50);
    else if (millis()%3500<2500) noTone(buzzer);
    else if (millis()%3500<3000) tone(buzzer, 1046.50);
    else noTone(buzzer);
  }
  else {
    //g3, a3, g3, f3
    if (millis()%4000<500) tone(buzzer, 196.00);
    else if (millis()%4000<1000) noTone(buzzer);
    else if (millis()%4000<1500) tone(buzzer, 220.00);
    else if (millis()%4000<2000) noTone(buzzer);
    else if (millis()%4000<2500) tone(buzzer, 196.00);
    else if (millis()%4000<3000) noTone(buzzer);
    else if (millis()%4000<3500) tone(buzzer, 174.61);
    else noTone(buzzer);
  }
}

void adjustCursor1() {
  int firstOutput = 0;
  int secondOutput = 0;
  digitalWrite(latchpinCursor, LOW);
    if (WhoseTurn==false) { //2 - RED
      firstOutput=pow(2, ledCursor-1);
      if (ledCursor==1) firstOutput=1;
      else if (ledCursor==2) firstOutput=2;
      else if (ledCursor==3) firstOutput=4;
      else if (ledCursor==4) firstOutput=8;
      else if (ledCursor==5) firstOutput=16;
      else if (ledCursor==6) firstOutput=32;
    }
    else { //3 - GREEN
      if (ledCursor==1) firstOutput = 64;
      else if (ledCursor == 2) firstOutput= 128;
      else if (ledCursor==3) secondOutput=1;
      else if (ledCursor==4) secondOutput=2;
      else if (ledCursor==5) secondOutput=4;
      else if (ledCursor==6) secondOutput=8;
    }
    shiftOut(datapinCursor, clockpinCursor, MSBFIRST, secondOutput);
    shiftOut(datapinCursor, clockpinCursor, MSBFIRST, firstOutput);
    digitalWrite(latchpinCursor, HIGH);
}

void resetGame() {
  for (int a=0; a<6; a++) { //Reset board values
    for (int b=0; b<5; b++) {
      ledsBoard[a][b]=0;
    }
  }
  ledCursor=1;
  hasSomeoneWon=false;
  areThereAnySpacesLeft=true;
  firstTurn=true;
  future=0;
  noTone(buzzer);
  WhoseTurn=false;
  adjustCursor1(); //needed?
  adjustBoard(); //needed?
}

boolean didSomeoneWin(boolean turn) {
  boolean wellQuestionMark=false;
  int color;
  if (turn==true) color = 3; //green
  else color = 2; //red
  //testing diagonals bottom-left to top-right
  for (int a=0; a<3; a++) { 
    for (int b=0; b<2; b++) {
      if (ledsBoard[a][b]==color)
        if (ledsBoard[a+1][b+1]==color)
          if (ledsBoard[a+2][b+2]==color)
            if (ledsBoard[a+3][b+3]==color) wellQuestionMark=true;
    }
  }
  //testing diagonals bottom-right to top-left
  for (int a=3; a<6; a++) {
    for (int b=0; b<2; b++) {
      if (ledsBoard[a][b]==color)
        if (ledsBoard[a-1][b+1]==color)
          if (ledsBoard[a-2][b+2]==color)
            if (ledsBoard[a-3][b+3]==color) wellQuestionMark=true;
    }
  }
  //testing horizontals
  for (int a=0; a<3; a++) {
    for (int b=0; b<5; b++) {
      if (ledsBoard[a][b]==color)
        if (ledsBoard[a+1][b]==color)
          if (ledsBoard[a+2][b]==color)
            if (ledsBoard[a+3][b]==color) wellQuestionMark=true;
    }
  }
  //testing verticals
  for (int a=0; a<6; a++) {
    for (int b=0; b<2; b++) {
      if (ledsBoard[a][b]==color)
        if (ledsBoard[a][b+1]==color)
          if (ledsBoard[a][b+2]==color)
            if (ledsBoard[a][b+3]==color) wellQuestionMark=true;
    }
  }
  return wellQuestionMark;
}

boolean anySpacesLeft() { //Array of [6][5]
  boolean wellQuestionMark = false;
  for (int a=0; a<6; a++)
    if (ledsBoard[a][4]==0) wellQuestionMark = true;
  return wellQuestionMark;
}

//*********PATTERN METHODS********
void loop2(){
  // put your main code here, to run repeatedly:
  //Button Code in Loop
  int b1State=digitalRead(button1);
  int b2State=digitalRead(button2);
  int b3State=digitalRead(button3);
  long now=millis();
  //Serial.print(currentMode);
  if (millis()>(lastTime+7000)) {
    currentMode=0;
    noTone(buzzer);
  }
  if (currentMode==0) adjustCursor2();
  adjustBoard();
  if (currentMode==1) pattern1();
  else if (currentMode==2) pattern2();
  else if (currentMode==3) pattern3();

  else {
    int tempo[6][5]=  { {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0} };
    for (int i=0; i<6; i++)
    {
      for (int j=0; j<5; j++)
      {
        ledsBoard[i][j]=tempo[i][j];
      }
    }
  }

  if(b1State==1 && now>future){
    if (currentMode!=1) lastTime=millis();
    currentMode=1;
    future=now+800; //Cooldown - Doesn't register another press until 600 ms later. Can change cooldown
    tone(buzzer, 880.00);
    digitalWrite(latchpinCursor, LOW);
  }
  else if(b2State==1 && now>future){
    if (currentMode!=2) lastTime=millis();
    currentMode=2;
    future=now+800; //Cooldown
    tone(buzzer, 220.00);
    digitalWrite(latchpinCursor, LOW);
  }
  else if(b3State==1 && now>future){
    if (currentMode!=3) lastTime=millis();
    currentMode=3;
    future=now+800; //Cooldown
    tone(buzzer, 12);
    digitalWrite(latchpinCursor, LOW);
  }
}

void pattern1() {
  if (millis()%4200<700) {

    int temp[6][5] = { {2, 2, 2, 3, 3},
                        {3, 2, 2, 2, 3},
                        {3, 3, 2, 2, 2},
                        {3, 3, 3, 2, 2},
                        {2, 3, 3, 3, 2},
                        {2, 2, 3, 3, 3} };
    for (int i=0; i<6; i++)
    {
      for (int j=0; j<5; j++)
      {
        ledsBoard[i][j]=temp[i][j];
      }
    }
  }
  else if (millis()%4200<1400) {
    int temp[6][5] = { {3, 2, 2, 2, 3},
                        {3, 3, 2, 2, 2},
                        {3, 3, 3, 2, 2},
                        {2, 3, 3, 3, 2},
                        {2, 2, 3, 3, 3},
                        {2, 2, 2, 3, 3} };
    for (int i=0; i<6; i++)
    {
      for (int j=0; j<5; j++)
      {
        ledsBoard[i][j]=temp[i][j];
      }
    }
  }
  else if (millis()%4200<2100) {
    int temp[6][5] = { {3, 3, 2, 2, 2},
                        {3, 3, 3, 2, 2},
                        {2, 3, 3, 3, 2},
                        {2, 2, 3, 3, 3},
                        {2, 2, 2, 3, 3},
                        {3, 2, 2, 2, 3} };
     for (int i=0; i<6; i++)
    {
      for (int j=0; j<5; j++)
      {
        ledsBoard[i][j]=temp[i][j];
      }
    }
  }
  else if (millis()%4200<2800) {
    int temp[6][5] = { {3, 3, 3, 2, 2},
                        {2, 3, 3, 3, 2},
                        {2, 2, 3, 3, 3},
                        {2, 2, 2, 3, 3},
                        {3, 2, 2, 2, 3},
                        {3, 3, 2, 2, 2} };
     for (int i=0; i<6; i++)
    {
      for (int j=0; j<5; j++)
      {
        ledsBoard[i][j]=temp[i][j];
      }
    }
  }

  else if (millis()%4200<3500) {
    int temp[6][5] = { {2, 3, 3, 3, 2},
                        {2, 2, 3, 3, 3},
                        {2, 2, 2, 3, 3},
                        {3, 2, 2, 2, 3},
                        {3, 3, 2, 2, 2},
                        {3, 3, 3, 2, 2} };
    for (int i=0; i<6; i++)
    {
      for (int j=0; j<5; j++)
      {
        ledsBoard[i][j]=temp[i][j];
      }
    }
  }
  else {
    int temp[6][5] = { {2, 2, 3, 3, 3},
                        {2, 2, 2, 3, 3},
                        {3, 2, 2, 2, 3},
                        {3, 3, 2, 2, 2},
                        {3, 3, 3, 2, 2},
                        {2, 3, 3, 3, 2} };
    for (int i=0; i<6; i++)
    {
      for (int j=0; j<5; j++)
      {
        ledsBoard[i][j]=temp[i][j];
      }
    }
  }
}

void pattern2() {
  if (millis()%2000<1000) {
    int temp[6][5] = { {2, 2, 2, 2, 2},
                        {2, 3, 3, 3, 2},
                        {2, 3, 2, 3, 2},
                        {2, 3, 2, 3, 2},
                        {2, 3, 3, 3, 2},
                        {2, 2, 2, 2, 2} };
    for (int i=0; i<6; i++)
    {
      for (int j=0; j<5; j++)
      {
        ledsBoard[i][j]=temp[i][j];
      }
    }
  }
  else {
    int temp[6][5] = { {3, 3, 3, 3, 3},
                        {3, 2, 2, 2, 3},
                        {3, 2, 3, 2, 3},
                        {3, 2, 3, 2, 3},
                        {3, 2, 2, 2, 3},
                        {3, 3, 3, 3, 3} };
     for (int i=0; i<6; i++)
    {
      for (int j=0; j<5; j++)
      {
        ledsBoard[i][j]=temp[i][j];
      }
    }

  }
}

void pattern3() {

  if (millis()%3000<1500) {
        int temp[6][5] = { {3, 3, 3, 3, 3},
                        {3, 3, 3, 3, 3},
                        {3, 3, 3, 3, 3},
                        {3, 3, 3, 3, 3},
                        {3, 3, 3, 3, 3},
                        {3, 3, 3, 3, 3} };
    for (int i=0; i<6; i++)
    {
      for (int j=0; j<5; j++)
      {
        ledsBoard[i][j]=temp[i][j];
      }
    }
  }

   else {
     int temp[6][5] = { {2, 2, 2, 2, 2},
                        {2, 2, 2, 2, 2},
                        {2, 2, 2, 2, 2},
                        {2, 2, 2, 2, 2},
                        {2, 2, 2, 2, 2},
                        {2, 2, 2, 2, 2} };
      for (int i=0; i<6; i++)
    {
      for (int j=0; j<5; j++)
      {
        ledsBoard[i][j]=temp[i][j];
      }
    }
   }

}

void adjustCursor2() {
  int firstOutput = 0;
  int secondOutput = 0;
  digitalWrite(latchpinCursor, LOW);
    if (millis()%2000<1000) {
      firstOutput=63;
    }
    else {
      firstOutput=192;
      secondOutput=15;
    }
  shiftOut(datapinCursor, clockpinCursor, MSBFIRST, secondOutput);
  shiftOut(datapinCursor, clockpinCursor, MSBFIRST, firstOutput);
  digitalWrite(latchpinCursor, HIGH);
}
