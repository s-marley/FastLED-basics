# Episode 6 - Noise
The FastLED noise functions can seem a little hard to understand if you don't know how they behave. Let's try and change that! The video covers the following content:
- What is noise?
- inoise8(x)
- Evolving noise through time
- Using fill_raw_noise8 and fill_noise16

We have barely scratched the surface of what's possible in this video, but it was long enough already. Using scale and x as the `inoise8(x)` parameters is completely optional, you can put whatever numbers or values you like in there. Have a play and see what's possible!
## YouTube video

[![Episode 6 - Noise](http://img.youtube.com/vi/7Dhh0IMSI4Q/0.jpg)](https://www.youtube.com/watch?v=7Dhh0IMSI4Q)

## Notes on the processing demo
I have included the processing code here in case anyone wants to play with it. Just a couple of things to note:
- Please don't use this as an example of how to do serial communication between processing and an Arduino. It was hacked together quickly just for this demo!
- I have chosen 56 points of noise to display on the graph for a good reason - my demo strip has 18 LEDs so this divides nicely for display. You will have to change these numbers for your own use case.
- I used the amazing [grafica](https://jagracar.com/grafica.php) library to create the chart, and the also-brilliant [ControlP5](http://www.sojamo.de/libraries/controlP5/) library for the UI components.

## Useful links
- [FastLED noise functions](http://fastled.io/docs/3.1/group___noise.html) FastLED API docs
- [An general explanation of noise](https://www.youtube.com/watch?v=8ZEMLCnn8v0) YouTube
- [Processing.org](https://processing.org/)
