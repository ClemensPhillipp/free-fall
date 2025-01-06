int max_up_speed = 40;
int max_down_speed = 255;
int min_down_speed = 15;
int pause_time = 3000;
int falling_time = 1800;

const int GSM1 = 9;
const int upper_sensor_pin = 8;
const int lower_sensor_pin = 7;
#define In1 10
#define In2 11

void setup() {
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(GSM1, OUTPUT);
  pinMode(upper_sensor_pin, INPUT);
  pinMode(lower_sensor_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  delay(pause_time);
  up();
  while (true) {
    if (digitalRead(upper_sensor_pin) == HIGH) {
      analogWrite(GSM1, 0);
      break;
    }
  }
  delay(pause_time);
  down();
  while (true) {
    if (digitalRead(lower_sensor_pin) == HIGH) {
      analogWrite(GSM1, 0);
      digitalWrite(In1, LOW);
      digitalWrite(In2, LOW);
      break;
    }
  }
  delay(pause_time);
}

void up() {
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  for (int i = 0; i <= max_up_speed; i += 1) {
    analogWrite(GSM1, i);
    delay(10);
  }
}

void down() {
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  analogWrite(GSM1, max_down_speed);
  delay(falling_time);
  analogWrite(GSM1, min_down_speed);
}
