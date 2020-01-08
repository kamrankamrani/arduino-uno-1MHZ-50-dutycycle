const uint8_t TIMER2_OUTPUT = 3;  // OC2B
const uint8_t PERIOD = 16;      // 16 MHZ / 16 = 1 MHZ

void setup()
{
    pinMode(TIMER2_OUTPUT, OUTPUT);
    TCCR2B = 0;           // stop timer
    TCNT2  = 0;           // reset timer
    TCCR2A = _BV(COM2B1)  // non-inverting PWM on OC2B
           | _BV(WGM20)   // fast PWM mode, TOP = OCR2A
           | _BV(WGM21);  
    TCCR2B = _BV(WGM22);  
    OCR2A = PERIOD - 1;
    OCR2B = PERIOD/2 - 1;
}


void loop(){
  TCCR2B |= _BV(CS20); 
}

