#include <Servo.h> // Подключаем библиотеку

Servo myServo;    // Создаем объект сервопривода
int servoPin = 9;


// установки:
void setup() {
// инициализируем последовательную передачу данных со скоростью 9600 бит в секунду:
Serial.begin(9600);
myServo.attach(servoPin); // Привязываем серво к 9 пину
}
// основной цикл:
void loop() {
// читаем значение на аналоговом входе 0:

int sensorValue = analogRead(A0);
float servoAngle = sensorValue * 0.17578125;

// выводим на монитор считанное значение:
Serial.println(sensorValue);
myServo.write(servoAngle);
delay(10); // задержка в промежутке между считываниями для стабильности
}