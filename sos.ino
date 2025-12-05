// К контакту 13 подключен светодиод через 220 Oм, присвоим ему имя "led"
int led = 13;

// --- ОПРЕДЕЛЕНИЕ ВРЕМЕННЫХ КОНСТАНТ ---
const int DOT_TIME = 100;                     // Длительность ТОЧКИ (Dot) в мс (100 мс)
const int DASH_TIME = DOT_TIME * 3;           // Длительность ТИРЕ (Dash) в мс (300 мс)
const int PAUSE_IN_LETTER = DOT_TIME;         // Пауза между элементами одной буквы (100 мс)
const int PAUSE_BETWEEN_LETTERS = DASH_TIME;  // Пауза между буквами (300 мс)
const int PAUSE_BETWEEN_SOS = DOT_TIME * 7;   // Пауза между полными сигналами SOS (700 мс)

// --- ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ ---
// Функция для генерации "Точки" (Dot)
void dot() {
  digitalWrite(led, HIGH);
  delay(DOT_TIME);
  digitalWrite(led, LOW);
  delay(PAUSE_IN_LETTER);  // Пауза после точки
}

// Функция для генерации "Тире" (Dash)
void dash() {
  digitalWrite(led, HIGH);
  delay(DASH_TIME);
  digitalWrite(led, LOW);
  delay(PAUSE_IN_LETTER);  // Пауза после тире
}

// --- СТРУКТУРА ПРОГРАММЫ ---

void setup() {
  // инициализируем цифровой вывод как выход:
  pinMode(led, OUTPUT);
}

// основной цикл:
void loop() {
  // 1. БУКВА "S" ( . . . )
  dot();  // Первая точка
  dot();  // Вторая точка
  dot();  // Третья точка
``
  // Пауза между буквами S и O
  delay(PAUSE_BETWEEN_LETTERS);

  // 2. БУКВА "O" ( — — — )
  dash();  // Первое тире
  dash();  // Второе тире
  dash();  // Третье тире

  // Пауза между буквами O и S
  delay(PAUSE_BETWEEN_LETTERS);

  // 3. БУКВА "S" ( . . . )
  dot();  // Первая точка
  dot();  // Вторая точка
  dot();  // Третья точка

  // Пауза перед повторением сигнала (пауза между SOS)
  delay(PAUSE_BETWEEN_SOS);
}