# SimonUno
Learning how to break down a problem and structure code by creating a simon game using an Arduino.

## Hardware
* Arduino UNO
* 4 Buttons
* 4 RGB Leds (Common Cathode)
* 1 Piezzo Buzzer
* 3 1.5k ohm Resistors
* 1 68 ohm Resistor

Hardware connections are described in the hardware folder, including a fritzing project.

## Computer Requirements
This project requires installing Arduino 1.8.5 and should work with any computer capable of running it.

## Setup
Copy all folders into your Arduino sketchbook folder.

## Lessons
This repository has completed source code as it would exist at the end of the lessons.

### Lesson 1
We will discuss what a microcontroller is, how to read the hardware schematic and some basic electronics.  This culmiates in how to use GPIO on the microcontroller to output a signal. When complete with this lesson we will have code which will use the piezzo buzzer to generate beeps.

### Lesson 2a
We will build upon what we learned in Lesson 1 and learn how to use GPIO to read signals.  This code will read a button and sound the buzzer while the button is pressed.

### Lesson 2b
We will now create a keyboard controller to read multiple buttons. We also uncover a potential problem with buttons and how fast microcontrollers read signals.

### Lesson 2c
We will explore how to de-bounce the button inputs to fix our discovered problem in the last lesson.

### Lesson 3a
We will review how an RGB led works and create the ability to turn LEDs on and off individually.

### Lesson 3b
We introduce Color objects and use it to control the color of the LEDs.  We also realize that all the LEDs have to be the same color.

### Lesson 3c
We explore how we can "fake" having each LED a different color using multiplexing.

### Lesson 4
Now that we can display multiple colored LEDs we will create the ability to co-ordinate them into an animation.

### Lesson 5a
Now that we have all the tool necessary to interface with the buttons, lights and buzzer we start building out a simon game.  We create a pattern generator and an animation to display the pattern.

### Lesson 5b
Finally we will create a state model to keep track of our simon game and create a game loop which binds the keyboard and leds to the game state.