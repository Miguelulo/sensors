// Definir pines para los ejes y el botón del joystick
const int pinX = A0;
const int pinY = A1;
const int pinButton = 2;

void setup() {
  // Iniciar la comunicación serie a 9600 baudios
  Serial.begin(9600);
  
  // Configurar el pin del botón como entrada con resistencia pull-up
  pinMode(pinButton, INPUT_PULLUP);
}

void loop() {
  // Leer el valor del eje X (0 a 1023)
  int xValue = analogRead(pinX);
  
  // Leer el valor del eje Y (0 a 1023)
  int yValue = analogRead(pinY);
  
  // Leer el estado del botón (LOW cuando está presionado, HIGH cuando no lo está)
  int buttonState = digitalRead(pinButton);
  
  // Enviar los valores leídos por el puerto serie
  Serial.print("Eje X: ");
  Serial.print(xValue);
  Serial.print("\tEje Y: ");
  Serial.print(yValue);
  Serial.print("\tBotón: ");
  Serial.println(buttonState == LOW ? "Pulsado" : "No pulsado");
  
  // Esperar un corto período de tiempo antes de la siguiente lectura
  delay(100);
}
