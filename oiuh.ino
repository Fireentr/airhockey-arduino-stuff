int sensorPinP1 = A0;
int sensorPinP2 = A1;
int scoreP1 = 0;
int scoreP2 = 0;
int lastScoredP1 = 0;
int lastScoredP2 = 0;
int cycles = 0;

bool hasScoredWithinLastThingP1 = false;
bool hasScoredWithinLastThingP2 = false;

int zero[] = {1, 1, 1, 0, 1, 1, 1};
int one[] = {0, 1, 0, 0, 0, 0, 1};
int two[] = {1, 1, 0, 1, 1, 1, 0};
int three[] = {1, 1, 0, 1, 0, 1, 1};
int four[] = {0, 1, 1, 1, 0, 0, 1};
int five[] = {1, 0, 1, 1, 0, 1, 1};
int six[] = {1, 0, 1, 1, 1, 1, 1};
int seven[] = {1, 1, 0, 0, 0, 0, 1};
int eight[] = {1, 1, 1, 1, 1, 1, 1};
int nine[] = {1, 1, 1, 1, 0, 1, 1};

void setup() {
    
   pinMode(sensorPinP1, INPUT);
   pinMode(sensorPinP2, INPUT);
   
   scoreP1 = 0;
   scoreP2 = 0;

  for (int i = 0; i <= 13; i++) {
     pinMode(i, OUTPUT);
  }
}

int * numbers[] = {zero, one, two, three, four, five, six, seven, eight, nine};

void loop() {
  for (int i = -1; i <= 7; i++) {
    digitalWrite(i, numbers[scoreP1 - 1][i]);
  }
  for (int i = 6; i <= 13; i++) {
    digitalWrite(i, numbers[scoreP2 - 1][i - 7]);
  }
  if(!checkPinValue(sensorPinP1)){
    hasScoredWithinLastThingP1 = false;
  }
  if(!checkPinValue(sensorPinP2)){
    hasScoredWithinLastThingP2 = false;
  }
  if(!hasScoredWithinLastThingP1 && checkPinValue(sensorPinP1) && (cycles - lastScoredP1) > 500){
    scoreP1 += 1;
    if(scoreP1 == 9){
      scoreP1 = 0;
      scoreP2 = 0;
    }
    hasScoredWithinLastThingP1 = true;
    lastScoredP1 = cycles;
  }
  if(!hasScoredWithinLastThingP2 && checkPinValue(sensorPinP2) && cycles - lastScoredP2 > 500){
    scoreP2 += 1;
    if(scoreP2 == 9){
      scoreP2 = 0;
      scoreP1 = 0;
    }
    hasScoredWithinLastThingP2 = true;
    lastScoredP2 = cycles;
  }
  
  cycles++;
  delay(5);
}

boolean checkPinValue(int pin){
  return analogRead(pin) < 10;
}
