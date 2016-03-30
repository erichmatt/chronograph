unsigned long time1;
unsigned long time2;
unsigned long elapsed;
const int start_timer = 2;
const int stop_timer = 3;
int start_state = 1;
int stop_state = 1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(start_timer, INPUT);
  pinMode(stop_timer, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Ready: ");
  while(start_state == 1){
    start_state = digitalRead(start_timer);
  }
  time1 = micros();
  while(stop_state == 1){
    stop_state = digitalRead(stop_timer);
  }
  time2 = micros();
  elapsed = time2 - time1;
  Serial.print("Time: ");
  Serial.println(elapsed);
  delay(1000);
  start_state = digitalRead(start_timer);
  stop_state = digitalRead(stop_timer);
}
