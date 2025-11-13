// Prueba Sensor E18-D80NK ===


// Pines
const int sensorPin = 7;   // Pin de salida del sensor
const int ledPin = 13;     // LED indicador (integrado en la placa)

int ultimoEstado = LOW;    // Variable para registrar el último estado

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Iniciando Visionix - Sensor E18-D80NK...");
  delay(1000);
}

void loop() {
  // Promediar varias lecturas para evitar falsos positivos
  int lectura = 0;
  for (int i = 0; i < 5; i++) {
    lectura += digitalRead(sensorPin);
    delay(10);
  }

  int estado = (lectura >= 3) ? HIGH : LOW;

  // Solo actuar si el estado cambió
  if (estado != ultimoEstado) {
    ultimoEstado = estado;

    if (estado == LOW) { // Dependiendo del tipo del sensor: LOW = objeto detectado
      digitalWrite(ledPin, HIGH);
      Serial.println("Objeto detectado");
      Serial.println("E18-D80NK:1"); // Compatible con ROS o Python
    } else {
      digitalWrite(ledPin, LOW);
      Serial.println("Sin objeto");
      Serial.println("E18-D80NK:0");
    }
  }

  delay(100);
}
