#include <Servo.h> // Подключаем библиотеку

Servo myServo;    // Создаем объект сервопривода
int servoPin = 9;

// цифровой вход 2 присоединен к кнопке. Назовем его:
int pushButton = 2;
// проведем необходимые установки:
void setup() {
// инициализируем последовательную передачу данных со скоростью 9600 бит в секунду:
Serial.begin(9600);
// назначим вывод 2 входом:
pinMode(pushButton, INPUT);
myServo.attach(servoPin); // Привязываем серво к 9 пину
}

// основной цикл:
void loop() {
// читаем значение на входе:
int buttonState = digitalRead(pushButton);
if (buttonState == 0) {
  myServo.write(0);    // поворачивает сервопривод в изначальное положение
}
else if (buttonState == 1) {
  myServo.write(180);    // поворачивает сервопривод в крайнее положение
}
// вывод и значение на монитор:
Serial.println(buttonState);
delay(100); // задержка для стабильного считывания
}