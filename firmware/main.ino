const int PLAY_PIN = 18;        //signal pin to audio module 
const int BUTTON_PIN = 15;      //Story Trigger button

void setup() {
  pinMode(PLAY_PIN, OUTPUT);    //
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  digitalWrite(PLAY_PIN, LOW);

  Serial.begin(115200);
  Serial.println("Dastaan Box Ready 🪆 ");
}

void loop() {

  if (digitalRead(BUTTON_PIN) == LOW) {

    Serial.println("Button Pressed - Playing Story....");

    digitalWrite(PLAY_PIN, HIGH);
    delay(1000);      // trigger PLAYE - trigger pulse to audio module

    digitalWrite(PLAY_PIN, LOW);
    //Wait for button release before listening again 
    while (digitalRead(BUTTON_PIN) == LOW) {
      delay(10);      // wait for button release
    }

    delay(500);        //debounce
  }
}
