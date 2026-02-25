#include <Servo.h>
Servo s;
float sp, err, integ, kp, ki, fake=512, out;
bool isStop = false;

void setup() {
  pinMode(11, OUTPUT);
  pinMode(2, INPUT_PULLUP); // Стоп
  pinMode(3, INPUT_PULLUP); // Сброс
  s.attach(9);
}

void loop() {
  // Проверка кнопок (с задержкой от дребезга)
  if (digitalRead(2) == LOW) { isStop = true; s.detach(); digitalWrite(11, 0); delay(200); }
  if (digitalRead(3) == LOW) { isStop = false; s.attach(9); integ = 0; delay(200); }
  
  // Если режим Стоп — пропускаем всю логику
  if (isStop) return;

  // Чтение потенциометров
  sp = analogRead(0);          // Уставка
  kp = analogRead(1) * 0.02;   // Агрессия (размах)
  ki = analogRead(2) * 0.0005; // Вялость (время)

  // ПИД-регулятор
  err = sp - fake;
  integ += err;
  out = 512 + (err * kp) + (integ * ki);
  out = constrain(out, 0, 1023);

  // Вывод на устройства
  s.write(map(out, 0, 1023, 0, 180));
  analogWrite(11, map(out, 0, 1023, 0, 255));

  // Эмуляция инерции датчика (чтобы качало)
  fake = fake + (out - fake) * 0.05;
  
  delay(60); // Задержка для плавности
}