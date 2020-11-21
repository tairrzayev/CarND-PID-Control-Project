## Describe the effect of the P, I, D component of the PID algorithm

- The `P` component is **P**roportinal to the CTE. `P` is equal to CTE multiplied by its coefficient Kp. Because it does not account for the rate of change, it simply steers proportionaly to the current CTE, keeps overshooting the optimum, oscilating around it. In fact, these oscilations are amplified as the car gains the speed, eventually throwing it off the strack. [Here's the video example](./video/p_only.mov) of car driving with P = 0.15 and the rest of the PID components set to 0.


- The `D` component is the **D**fferential of the CTE. Roughly speaking, `D` dampens the oscilations, caused by `P`. Driving `D` to zero means driving the rate of the CTE to zero, effectively decaying the oscilations.

- The `I` component is the systematic error. E.g. if front wheels or the steering mechanism is not adjusted, the steering might be biased to the left or to the right, in which case using `P` and `D` only will have the car converging to some constant offset from zero.


## Student discusses how they chose the final hyperparameters (P, I, D coefficients)

The values were selected empirically. 

The `P` value seem to work best when it's in the range of (0.1, 03). Selected value `0.2` worked best with the selected `I` value. Higher values would result into growing oscilations, throwing the car off the track, lower values would result into understeer and car going off the track.
The `I` value is set to `0.001`. If set to a magnitude higher (`0.01`), the initial integral error affects steering to much, does not timely converge to specific value, resulting into car locking the steering to the min / max angle and going off the track. [Here's the video](./video/i_too_large.mov) with `I` coefficient set to a large value. Chosen value `0.001` dampens it enough to avoid initial oversteer.

The `D` value is set to `7`, which is enough to dampen the oscilations for the selected `P` value. `D` can be set to much larger value (tested with `100`) but the steering gets too "twitchy" in that case.


## Throttle

My implementation sets the throttle to `1` but heavily penalizes it for steering values larger than 0.01 (PID.cpp, Line 39)

## Demo video

My main goal was to drive 1 lap in the shortest amount of time possible so the drive is not that comfortable (too sharp steering). For smooter / slower ride `P` and `D` values should be lowered along with the max speed. [Here's the demo video.](./video/demo.mov)
