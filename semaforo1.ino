  /*Programacion de un semaforo de coches, con un semaforo de peatones, con boton. Que al precionar el boton, 
   se cambia para que el peaton pueda cruzar. con un tiempo de espera y parpadeo del led verde de coches antes de cambiar. 
   El led verde de peatones tambien parpadea antes de cambiar a verde*/
   
  int rojo = 4; //led rojo de coches
  int amarillo = 5; //led amarillo de coches
  int verde = 6; //led verde de coches
  int pulsador = 7; //boton o pulsador
  int pverde = 3; //led verde de peatones
  int projo = 2; //led rojo de peatones
  
void setup() {
  // especificacion de si es entrada/ salida de los componentes led y boton
  pinMode(verde,OUTPUT); //verde coches coches salida
  pinMode(amarillo,OUTPUT); //amarillo coches salida
  pinMode(rojo,OUTPUT); //rojo coches salida
  //pinMode(pulsador,INPUT); //boton entrada
  pinMode(pverde,OUTPUT); //verde peatones salida
  pinMode(projo,OUTPUT); //rojo peatones salida
}

void loop() {
  //decision de si el pulsador o boton esta apretado
  if(digitalRead(pulsador) == HIGH){
    digitalWrite(rojo,HIGH); //rojo coches encendido
    digitalWrite(projo,LOW); //rojo peatones apagado
    digitalWrite(pverde,HIGH); //verde peatones encendido
    delay(500); //tiempo de ejecucion
    }else{
      digitalWrite(projo,HIGH); //rojo peatones encendido
      digitalWrite(verde,HIGH); //verde coches encendido
      delay(1000); //timpo de espera
      for(int i = 0; i < 3; i++){ // ciclo for para el parpadeo del led verde coches
        digitalWrite(projo,HIGH); //rojo peatones encendido
        digitalWrite(verde,LOW); //verde coches apagado
        delay(500); //timpo de ejecucion
        digitalWrite(projo,HIGH); //rojo peatones encendido
        digitalWrite(verde,HIGH); //verde coches encendido
        delay(500); //tiempo de espera
      } //fin del for
        digitalWrite(verde,LOW); //verde coches apagado
        digitalWrite(projo,HIGH); //rojo peatones encendido
        digitalWrite(amarillo,HIGH); //amarillo coches encendido
        delay(2000);// tiempo de espera
        digitalWrite(projo,HIGH); //rojo peatones encendido
        digitalWrite(amarillo,LOW); //amarillo coches apagado
        digitalWrite(rojo,HIGH); //rojo coches encendido
        digitalWrite(pverde,HIGH); // verde peatones encendido
        digitalWrite(projo,LOW); //rojo peatones apagado
        delay(5000);//tiempo de espera
        for(int j = 0; j < 3; j++){ //ciclo for para el parpadeo del led verde peatones
          digitalWrite(pverde,HIGH); //verde peatones encendido
          delay(500); // tiempo de ejecucion
          digitalWrite(pverde,LOW); //verde peatones apagado
          delay(500); //tiempo de ejecucion
        }
        digitalWrite(rojo,LOW); //rojo coches apagado
        digitalWrite(pverde,LOW); //verde peatones apagado
    } //fin de la desicion
} // fin del loop
