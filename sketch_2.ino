
int LED[]={4,5,6,7};


void setup()
{
for(int i=4 ; i<8;i++)
{
  pinMode(LED[i],OUTPUT);
  
}


}

void loop()
{
 for(int i=4;i<8;i++)
 {
   digitalWrite(LED[i],HIGH);
   delay(300);
   digitalWrite(LED[i],LOW);
   delay(300);
   
 }
 for(int i=8;i>4;i--)
 {
   digitalWrite(LED[i],HIGH);
   delay(300);
   digitalWrite(LED[i],LOW);
   delay(300);
   
 }
 

}
