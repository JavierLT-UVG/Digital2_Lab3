// Definir pines de led rgb integrado en la tiva
#define ledRed PF_1
#define ledBlue PF_2
#define ledGreen PF_3

// Definir pines de led del jugador 1
#define led1P1 PB_0
#define led2P1 PB_1
#define led3P1 PE_4
#define led4P1 PE_5
#define led5P1 PB_4
#define led6P1 PA_5
#define led7P1 PA_6
#define led8P1 PA_7

// Definir pines de led del jugador 2
#define led1P2 PB_5
#define led2P2 PD_0
#define led3P2 PD_1
#define led4P2 PD_2
#define led5P2 PD_3
#define led6P2 PE_1
#define led7P2 PE_2
#define led8P2 PE_3

// Definir push buttons
#define pbP1 PF_4
#define pbP2 PF_0
#define pbReset PB_3

// Crear variables globales del programa
int estadoP1 = 0;
int estadoP2 = 0;
int pb1State = 0;
int pb2State = 0;

int raceEnable = 0;

void setup() 
{
  // Definir pines de semáforo como salidas
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);  
  pinMode(ledGreen, OUTPUT);
  
  // Definir pines de leds de Jugador 1 como salidas
  pinMode(led1P1, OUTPUT);
  pinMode(led2P1, OUTPUT);
  pinMode(led3P1, OUTPUT);
  pinMode(led4P1, OUTPUT);
  pinMode(led5P1, OUTPUT);
  pinMode(led6P1, OUTPUT);
  pinMode(led7P1, OUTPUT);
  pinMode(led8P1, OUTPUT);
  
  // Definir pines de leds de Jugador 1 como salidas
  pinMode(led1P2, OUTPUT);
  pinMode(led2P2, OUTPUT);
  pinMode(led3P2, OUTPUT);
  pinMode(led4P2, OUTPUT);
  pinMode(led5P2, OUTPUT);
  pinMode(led6P2, OUTPUT);
  pinMode(led7P2, OUTPUT);
  pinMode(led8P2, OUTPUT);
  
  // Definir push buttons
  pinMode(pbP1, INPUT_PULLUP);
  pinMode(pbP2, INPUT_PULLUP);
  pinMode(pbReset, INPUT_PULLUP);

  raceEnable = 0;
}

void loop() 
{
  
  if(digitalRead(pbP1) == 0 || digitalRead(pbP2) == 0)  // Si un jugador presiona su botón, entrar
  {   
    // Que un jugador presione su botón permite que se inicie el juego
    raceEnable = 1;   
  }

  // En caso se presione el botón de Reset
  if(digitalRead(pbReset) == 0)
  {
    estadoP1 = 0;
    contadorP1(estadoP1);
    
    estadoP2 = 0;
    contadorP2(estadoP2);
    
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledBlue, LOW);
    
    raceEnable = 0;
  }

  if(raceEnable == 1)
  {
    estadoP1 = 0;
    contadorP1(estadoP1);
    estadoP2 = 0;
    contadorP2(estadoP2);
    
    // Iniciar semáforo cada vez que va a comenzar la carrera
    semaforo();
  }

  
  while(raceEnable == 1)  // Mantenerse mientras el juego haya sido iniciado
  {
  
  // Contador de Jugador 1  
  if(digitalRead(pbP1) == 0)                    // Si el Push Button fue presionado, entrar
  {   
    pb1State = 1;
  }
  if (digitalRead(pbP1) == 1 && pb1State == 1)  // Si el Push Button fue soltado, se puede incrementar
  { 
    delay(2);
    estadoP1++;
    pb1State = 0;
  }
  
  
  // Contador de Jugador 2
  if(digitalRead(pbP2) == 0)                    // Si el Push Button fue presionado, entrar
  {   
    pb2State = 1;
  }
  if (digitalRead(pbP2) == 1 && pb2State == 1)  // Si el Push Button fue soltado, se puede incrementar
  { 
    delay(2);
    estadoP2++;
    pb2State = 0;
  }
  
  
  // Modificar LEDs acorde al contador de cada jugador
  contadorP1(estadoP1);
  contadorP2(estadoP2);
  
  
  // Secuencia de ganadores en caso lleguen a terminar su contador
  if(estadoP1 == 8)
  {
    winnerP1();
  }
  
  if(estadoP2 == 8)
  {
    winnerP2();
  }
  
  
  // En caso se presione el botón de Reset
  if(digitalRead(pbReset) == 0)
  {
    estadoP1 = 0;
    contadorP1(estadoP1);
    
    estadoP2 = 0;
    contadorP2(estadoP2);
    
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledBlue, LOW);
    
    raceEnable = 0;
    break;
  }
  
  }
}

void semaforo()
{
  // Color rojo en semáforo
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, LOW);
  
  delay(1000);
  
  // Color amarillo en semáforo
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledBlue, LOW);
  
  delay(1000);
  
  // Color verde en semáforo
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledBlue, LOW);
  
  delay(1000);
  
  // Se apaga el semáforo, el juego puede empezar
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, LOW);
}

void contadorP1 (int estado)
{
  switch(estado)
  {
    case 0:
    clrP1();
    break;
    
    case 1:
    clrP1();
    digitalWrite(led1P1, HIGH);
    break;
    
    case 2:
    clrP1();
    digitalWrite(led2P1, HIGH);
    break;
    
    case 3:
    clrP1();
    digitalWrite(led3P1, HIGH);
    break;
    
    case 4:
    clrP1();
    digitalWrite(led4P1, HIGH);
    break;
    
    case 5:
    clrP1();
    digitalWrite(led5P1, HIGH);
    break;
    
    case 6:
    clrP1();
    digitalWrite(led6P1, HIGH);
    break;
    
    case 7:
    clrP1();
    digitalWrite(led7P1, HIGH);
    break;
    
    case 8:
    clrP1();
    digitalWrite(led8P1, HIGH);
    break;
  }
}

void contadorP2 (int estado)
{
  switch(estado)
  {
    case 0:
    clrP2();
    break;
    
    case 1:
    clrP2();
    digitalWrite(led1P2, HIGH);
    break;
    
    case 2:
    clrP2();
    digitalWrite(led2P2, HIGH);
    break;
    
    case 3:
    clrP2();
    digitalWrite(led3P2, HIGH);
    break;
    
    case 4:
    clrP2();
    digitalWrite(led4P2, HIGH);
    break;
    
    case 5:
    clrP2();
    digitalWrite(led5P2, HIGH);
    break;
    
    case 6:
    clrP2();
    digitalWrite(led6P2, HIGH);
    break;
    
    case 7:
    clrP2();
    digitalWrite(led7P2, HIGH);
    break;
    
    case 8:
    clrP2();
    digitalWrite(led8P2, HIGH);
    break;
  }
}

void clrP1()
{
  digitalWrite(led1P1, LOW);
  digitalWrite(led2P1, LOW);
  digitalWrite(led3P1, LOW);
  digitalWrite(led4P1, LOW);
  digitalWrite(led5P1, LOW);
  digitalWrite(led6P1, LOW);
  digitalWrite(led7P1, LOW);
  digitalWrite(led8P1, LOW);
}

void clrP2()
{
  digitalWrite(led1P2, LOW);
  digitalWrite(led2P2, LOW);
  digitalWrite(led3P2, LOW);
  digitalWrite(led4P2, LOW);
  digitalWrite(led5P2, LOW);
  digitalWrite(led6P2, LOW);
  digitalWrite(led7P2, LOW);
  digitalWrite(led8P2, LOW);
}

void winnerP1()
{
  // Encender LED azul
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, HIGH);
  // Terminar juego
  raceEnable = 0;
}

void winnerP2()
{
  // Encender LED verde
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledBlue, LOW);
  // Terminar juego
  raceEnable = 0;
}
