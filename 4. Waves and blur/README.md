# Episode 4 - Waves and blur
Using the wave functions can result in dynamic patterns and are extremely helpful for smooth-looking animations. In this episode we will cover:
- Beatsin8 / Beatsin16
- Phase offset and timebase
- Adding waves
- Sawtooth waves
- 1D blurring
## NOTE
Since producing the video, a comment from a viewer made me realise that for longer strips at higher bpms, sinbeat8 is not of a high enough resolution when used as a position. This can result in certain LEDs never being switched on which looks odd. In this case, you will need to use beatsin16 instead of beatsin8. I've updated the examples here to mainly use beatsin16, but this means that the code here will look different to the code shown in the video.

If using beatsin16, the phase offset will now be from 0 - 65535 instead of 0 - 255. If using a wave for hue, brightness etc, beatsin8 will usually be fine, as it's often difficult to tell the difference for these parameters.

In the examples `phaseBeat`, `blurPhaseBeat` and `addingWaves`, I've left both options in the code in order that they remain consistent with the video. Choose whichever one works for you.
## YouTube video

[![Episode 4 - Waves and blur](http://img.youtube.com/vi/2owTxbrmY-s/0.jpg)](https://www.youtube.com/watch?v=2owTxbrmY-s)

## Useful links
- [Some info on waves](https://github.com/FastLED/FastLED/wiki/FastLED-Wave-Functions) FastLED wiki
- [List of wave and other math functions](http://fastled.io/docs/3.1/group__lib8tion.html) FastLED API docs
- [Blur and other color utilities](http://fastled.io/docs/3.1/group___colorutils.html) FastLED API docs
