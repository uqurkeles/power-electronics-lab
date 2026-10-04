// Arduino UNO / Nano
// 20 kHz PWM on D9 (OC1A)
// Initial duty cycle: 50%

void setup() {
  pinMode(9, OUTPUT);

  // Clear Timer1 configuration
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;

  // Fast PWM, TOP = ICR1
  // fPWM = 16 MHz / (1 * (1 + 799))
  //      = 20 kHz

  ICR1 = 799;

  // 50% duty cycle
  OCR1A = 400;

  // Non-inverting PWM on OC1A (D9)
  TCCR1A |= (1 << COM1A1);

  // Fast PWM Mode 14
  TCCR1A |= (1 << WGM11);
  TCCR1B |= (1 << WGM12) | (1 << WGM13);

  // Prescaler = 1
  TCCR1B |= (1 << CS10);
}

void loop() {
}
