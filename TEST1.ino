
char READ = 0;

void setup() {
  Serial.begin(9600);
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(42, OUTPUT);
  
}

void loop() {
  
  if (Serial.available() > 0) {
    READ = Serial.read(); 
    Serial.print("READ : ");
    Serial.println(READ);

      if(READ == '7'){
     digitalWrite(23, HIGH);   
    }
    else if(READ == '8'){
      digitalWrite(23, LOW); 
    }
     if(READ == '4'){
     digitalWrite(40, HIGH);   
    }
    else if(READ == '5'){
      digitalWrite(40, LOW); 
    }
     if(READ == '1'){
     digitalWrite(42, HIGH);   
    }
    else if(READ == '2'){
      digitalWrite(42, LOW); 
    }

    if(READ == 0){
digitalWrite(23, LOW);
digitalWrite(40, LOW);
digitalWrite(42, LOW);
    }
    else if(READ == 9){
digitalWrite(23, HIGH);
digitalWrite(40, HIGH);
digitalWrite(42, HIGH);
    }
  }


   



    


}
