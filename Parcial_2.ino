#include  <LiquidCrystal.h>


int pin_lectura = A1;
int valor;
int voltaje;
double Volts=0.0;
double Rs=0.0;
double N=0.0;
double P=0.0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
}

void loop() {
  valor = analogRead(pin_lectura);
  voltaje = map(valor, 0, 1023, 0, 5000);
  Volts=(valor*5.0)/1023.0;
  Rs=10.0*((5.0/Volts)-1.0);
  N=pow(Rs/6.0019,-1/0.701);
  P=(N*1)/0.00980665;
  
  lcd.begin(16, 2);
  lcd.home();
  lcd.print("Jorge Raul");
  lcd.setCursor ( 0, 1 );
  lcd.print("Castillo Palmer");
  delay(1000);
  lcd.clear();
  
  
  
  lcd.begin(16, 2);
  lcd.home();
  lcd.print("Fuerza=");
  lcd.print(N,3);
  lcd.print(" N");
  lcd.setCursor ( 0, 1 );
  lcd.print("Peso=");
  lcd.print(P,3);
  lcd.print(" g");
  delay(1000);
  lcd.clear();
  
  
  Serial.print("Entrada analógica = ");
  Serial.println(valor);


  Serial.print("Voltaje en mV = ");
  Serial.println(voltaje);  
  
    Serial.print("Volts = ");
  Serial.println(Volts);
  
    Serial.print("Rs = ");
  Serial.println(Rs);
  
    Serial.print("N = ");
  Serial.println(N);
 
}
