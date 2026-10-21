#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int RELAY_I_SUP = 19;
const int RELAY_D_SUP = 18;
const int RELAY_I_INF = 16;
const int RELAY_D_INF = 17;

void drawArrowUp() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(45, 2);
  display.print("ARRIBA");

  display.fillTriangle(64, 18, 50, 36, 78, 36, SSD1306_WHITE);
  display.fillRect(59, 36, 10, 22, SSD1306_WHITE);
  display.display();
}

void drawArrowDown() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(45, 2);
  display.print("ABAJO");

  display.fillTriangle(64, 58, 50, 40, 78, 40, SSD1306_WHITE);
  display.fillRect(59, 18, 10, 22, SSD1306_WHITE);
  display.display();
}

void drawArrowLeft() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(30, 2);
  display.print("IZQUIERDA");

  display.fillTriangle(30, 38, 55, 20, 55, 56, SSD1306_WHITE);
  display.fillRect(55, 33, 22, 10, SSD1306_WHITE);
  display.display();
}

void drawArrowRight() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(38, 2);
  display.print("DERECHA");

  display.fillTriangle(98, 38, 73, 20, 73, 56, SSD1306_WHITE);
  display.fillRect(51, 33, 22, 10, SSD1306_WHITE);
  display.display();
}

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Fallo al inicializar la pantalla SSD1306"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(15, 25);
  display.print("SISTEMA LISTO");
  display.display();
  delay(1500);

  pinMode(RELAY_D_SUP, OUTPUT);
  pinMode(RELAY_D_INF, OUTPUT);
  pinMode(RELAY_I_SUP, OUTPUT);
  pinMode(RELAY_I_INF, OUTPUT);

  digitalWrite(RELAY_D_SUP, HIGH);
  digitalWrite(RELAY_D_INF, HIGH);
  digitalWrite(RELAY_I_SUP, HIGH);
  digitalWrite(RELAY_I_INF, HIGH);
}

void loop() {
  digitalWrite(RELAY_I_SUP, HIGH);
  digitalWrite(RELAY_D_SUP, HIGH);
  digitalWrite(RELAY_I_INF, LOW);
  digitalWrite(RELAY_D_INF, LOW);
  drawArrowUp();
  delay(3000);

  digitalWrite(RELAY_I_SUP, LOW);
  digitalWrite(RELAY_D_SUP, LOW);
  digitalWrite(RELAY_I_INF, HIGH);
  digitalWrite(RELAY_D_INF, HIGH);
  drawArrowDown();
  delay(3000);

  digitalWrite(RELAY_D_SUP, HIGH);
  digitalWrite(RELAY_D_INF, HIGH);
  digitalWrite(RELAY_I_SUP, LOW);
  digitalWrite(RELAY_I_INF, LOW);
  drawArrowLeft();
  delay(3000);

  digitalWrite(RELAY_I_SUP, HIGH);
  digitalWrite(RELAY_I_INF, HIGH);
  digitalWrite(RELAY_D_SUP, LOW);
  digitalWrite(RELAY_D_INF, LOW);
  drawArrowRight();
  delay(3000);
}