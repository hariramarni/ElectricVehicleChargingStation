/*

*/
String inputs;
#define relay1 2 //Connect relay1 to pin 9

void setup()
{
Serial.begin(9600); //Set rate for communicating with phone
pinMode(relay1, OUTPUT); //Set relay1 as an output

digitalWrite(relay1, LOW); //Switch relay1 off

}
void loop()
{
while(Serial.available()) //Check if there are available bytes to read
{
delay(10); //Delay to make it stable
char c = Serial.read(); //Conduct a serial read
if (c == '#'){
break; //Stop the loop once # is detected after a word
}
inputs += c; //Means inputs = inputs + c
}
if (inputs.length() >0)
{
Serial.println(inputs);

if(inputs == "A")
{ 
digitalWrite(relay1, LOW);
}
else if(inputs == "a")
{
digitalWrite(relay1, HIGH);
}

inputs="";
}
}
