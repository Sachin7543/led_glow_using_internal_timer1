#define ledPin 13
int led_state=0;
void setup()
{
  pinMode(ledPin, OUTPUT);
  // initialize timer1 
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A = 31249;            // compare match register 16MHz/256/2Hz
  TCCR1B = TCCR1B |(1 << WGM12);   // CTC mode
  TCCR1B = TCCR1B |((1 << CS12)|(1 << CS10));    // 256 prescaler 
  TIMSK1 = TIMSK1 |(1 << OCIE1A);  // enable timer compare interrupt
  sei();             // enable all interrupts

}
void loop()
{
  // your program here…
}

ISR(TIMER1_COMPA_vect)          // timer compare interrupt service routine
{
  led_state=!led_state;        // toggle LED pin
  digitalWrite(ledPin, led_state);   
}
