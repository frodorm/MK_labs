// ����������� �����
const int led1 = 2; // ������ ���������
const int led2 = 3; // ������ ���������
const int buttonPin = 4; // ������

// ����������
bool isRunning = false; // ���� ������ �������
bool buttonState = false; // ������� ��������� ������
bool lastButtonState = false; // ���������� ��������� ������
unsigned long previousMillis = 0; // ��� ������ � ��������
const long interval = 500; // �������� ������� (� �������������)
bool led1State = false; // ��������� ������� ����������

void setup() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(buttonPin, INPUT);
}

void loop() {
    // ������ ��������� ������
    buttonState = digitalRead(buttonPin);

    // ���� ������ ������ � ��������
    if (buttonState && !lastButtonState) {
        isRunning = !isRunning; // ������������ ��������� �������
        digitalWrite(led1, LOW); // ���������� ����������� ��� ���������
        digitalWrite(led2, LOW);
    }
    lastButtonState = buttonState; // ���������� ��������� ������

    // ������ �������
    if (isRunning) {
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= interval) {
            previousMillis = currentMillis;

            // ������������ ��������� �����������
            led1State = !led1State;
            digitalWrite(led1, led1State ? HIGH : LOW);
            digitalWrite(led2, led1State ? LOW : HIGH);
        }
    }
}
