// Определение пинов
const int led1 = 2; // Первый светодиод
const int led2 = 3; // Второй светодиод
const int buttonPin = 4; // Кнопка

// Переменные
bool isRunning = false; // Флаг работы мигалки
bool buttonState = false; // Текущее состояние кнопки
bool lastButtonState = false; // Предыдущее состояние кнопки
unsigned long previousMillis = 0; // Для работы с таймером
const long interval = 500; // Интервал мигания (в миллисекундах)
bool led1State = false; // Состояние первого светодиода

void setup() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(buttonPin, INPUT);
}

void loop() {
    // Чтение состояния кнопки
    buttonState = digitalRead(buttonPin);

    // Если кнопка нажата и отпущена
    if (buttonState && !lastButtonState) {
        isRunning = !isRunning; // Переключение состояния мигалки
        digitalWrite(led1, LOW); // Выключение светодиодов при остановке
        digitalWrite(led2, LOW);
    }
    lastButtonState = buttonState; // Обновление состояния кнопки

    // Работа мигалки
    if (isRunning) {
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= interval) {
            previousMillis = currentMillis;

            // Переключение состояния светодиодов
            led1State = !led1State;
            digitalWrite(led1, led1State ? HIGH : LOW);
            digitalWrite(led2, led1State ? LOW : HIGH);
        }
    }
}
