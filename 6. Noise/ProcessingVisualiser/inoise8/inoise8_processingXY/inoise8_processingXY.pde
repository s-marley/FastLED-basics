import controlP5.*;
import grafica.*;
import processing.serial.*;

Serial myPort;
String Input;
String Output;
long outputTime = millis();

int[] data;
int numPoints = 100;
GPointsArray points = new GPointsArray(numPoints);
GPlot plot;

ControlP5 gui;
CheckBox chk;
Textlabel txt;

int xSliderValue = 0;
int scaleSliderValue = 10;
int timeSliderValue = 0;
int animateCheckBoxValue = 0;
int lastTime = 0;

void setup() {
  
  // Canvas setup
  size(1280,720);
  background(150);
  
  // Serial setup
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 115200);
  myPort.bufferUntil('\n');
  
  // Plot setup
  plot = new GPlot(this, 25, 25);
  plot.setDim(800, 570);
  plot.getXAxis().setAxisLabelText("x");
  plot.getYAxis().setAxisLabelText("inoise8(x)");
  
  // GUI setup
  PFont pfont = createFont("Arial",20,true);
  ControlFont font = new ControlFont(pfont,20);
  
  pfont = createFont("Courier",20,true);
  ControlFont font2 = new ControlFont(pfont,30);
  
  gui = new ControlP5(this);
  gui.setFont(font);
  
  gui.addSlider("xSliderValue")
    .setPosition(950,100)
    .setSize(220, 30)
    .setRange(0,1000)
    .setId(1)
    .setCaptionLabel("x");
    
  gui.addSlider("scaleSliderValue")
    .setPosition(950,200)
    .setSize(220, 30)
    .setRange(0,30)
    .setId(2)
    .setCaptionLabel("scale");
    
  gui.addSlider("timeSliderValue")
    .setPosition(950,300)
    .setSize(220, 30)
    .setRange(0,1000)
    .setId(4)
    .setCaptionLabel("time");
    
  chk = gui.addCheckBox("checkbox")
    .setPosition(950, 350)
    .setSize(30,30)
    .setId(5)
    .addItem("animate",0);
    
  txt = gui.addTextlabel("label")
    .setFont(font2)
    .setPosition(90,10);
    
    
  updateText();
}

void draw() {
  drawPlot();
  
  if (animateCheckBoxValue == 1) {
    if (millis() > lastTime + 50) {
      timeSliderValue += 5;
      gui.getController("timeSliderValue").setValue(timeSliderValue);
      lastTime = millis();
    }
    if (timeSliderValue == 1000) chk.toggle(0);
  }
}

void drawPlot() {
  plot.setPoints(points);
  
  this.background(150);
  
  plot.beginDraw();
  plot.drawBox();
  plot.drawXAxis();
  plot.drawYAxis();
  plot.drawTitle();
  plot.drawPoints();
  plot.drawLines();
  plot.setYLim(0, 255);
  plot.endDraw();
}

// Triggered on recieving serial data
void serialEvent(Serial myPort) {
  Input = myPort.readStringUntil('\n');
  if (Input != null) {
    Input = trim(Input);
    data = int(split(Input, ','));
    
    points = new GPointsArray(numPoints);
    for (int i = 1; i < data.length; i++) {
      points.add(i, data[i]);
    }
    
  }
}

// Triggered when gui is triggered
void controlEvent(ControlEvent theEvent) {
  
  if(theEvent.isFrom("checkbox")){
    if(chk.getState(0) == false) animateCheckBoxValue = 0;
    else animateCheckBoxValue = 1;
  }

  Output = "<" + xSliderValue + "," + scaleSliderValue  + "," + timeSliderValue + ">";
  if (millis() - outputTime > 30) {
    myPort.write(Output);
    outputTime = millis();
  } 
  
  if (txt != null) updateText();
}

void updateText() {
  String s = "inoise8(i * " + scaleSliderValue + " + " + xSliderValue + ", " + timeSliderValue + ");";
  //String s = "inoise8(i * " + scaleSliderValue + " + " + xSliderValue + ");";
  txt.setText(s);
}
