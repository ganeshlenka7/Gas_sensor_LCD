#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ---------- LCD ----------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---------- Sensor Pins ----------
const int gasAnalog = A0;
const int gasDigital = 2;

// ---------- Blinking Alert ----------
unsigned long previousMillis = 0;
const long blinkInterval = 500;
bool showAlert = false;

// ---------- Custom Icons ----------
// Gas icon ⛽
byte gasIcon[8] = {
  B00100,
  B01110,
  B01110,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};

// Smiley 😀
byte smiley[8] = {
  B00000,
  B01010,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};

// Skull 💀 (alert)
byte skullIcon[8] = {
  B01110,
  B10101,
  B11111,
  B11111,
  B01110,
  B01010,
  B10101,
  B00000
};

void setup() {
  pinMode(gasDigital, INPUT);

  lcd.init();
  lcd.backlight();

  // Load custom emojis
  lcd.createChar(0, gasIcon);
  lcd.createChar(1, smiley);
  lcd.createChar(2, skullIcon);

  // Startup animation
  lcd.setCursor(0, 0);
  lcd.write(byte(0)); // ⛽
  lcd.print(" Gas Monitor  ");
  lcd.setCursor(0, 1);
  lcd.print(" Initializing..");
  delay(1500);
  lcd.clear();
}

void loop() {
  int analogValue = analogRead(gasAnalog);
  int digitalValue = digitalRead(gasDigital);

  // ---------- LINE 1: Analog Value + Bar ----------
  lcd.setCursor(0, 0);
  lcd.write(byte(0));        // ⛽ icon
  lcd.print(" A:");
  lcd.print(analogValue);
  lcd.print(" ");

  // Bar graph (10 blocks)
  int barLength = map(analogValue, 0, 1023, 0, 10);
  lcd.setCursor(7, 0);
  for (int i = 0; i < 10; i++) {
    if (i < barLength) lcd.write(byte(255)); // Solid block
    else lcd.print(" ");
  }

  // ---------- LINE 2: Digital Status + Emoji ----------
  lcd.setCursor(0, 1);
  lcd.print("D:");
  lcd.print(digitalValue);
  lcd.print(" ");

  if (digitalValue == 1) {
    // Blinking GAS ALERT!
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= blinkInterval) {
      previousMillis = currentMillis;
      showAlert = !showAlert;
    }

    lcd.setCursor(4, 1);
    if (showAlert) {
      lcd.print("GAS ALERT!");
    } else {
      lcd.print("          "); // clear the alert space
    }

    // Show skull icon at last column
    lcd.setCursor(15, 0);
    lcd.write(byte(2)); // skull
  } 
  else {
    lcd.setCursor(4, 1);
    lcd.print("Safe        ");
    lcd.setCursor(15, 0);
    lcd.write(byte(1));  // 😀 icon
  }

  delay(200);
}
