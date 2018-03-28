#Project - PID Tuning

In this project the target is tuning a PID controller which controls the steering input in order to keep the simulation car in track.

In the current submission __no feed-back control afffecting the throttle value__ (thus speed) was performed. The throttle value is set to 0.3 by the simulator.

##Effect of PID parameters & comments

In a PID controlling scheme, the _Proportional gain_ "penalizes" the magnitude of the error of the tracked/controlled signal from the desired input value, and contributes to the control input with a magnitude proportional to the magnitude of the error, and with sign to opposite to that of the error. In our case, this error is the cross-track-error (cte in code). 

Likewise, the _Derivative gain_ penalizes the speed of change of the error. As fast as the error changes, the magnitude of contribution of the derivative control increases. Thus, this term can be used to damp out the overshoot in the system.

Finally, the _Integral control_ is used to minimize the steady-state offset. The error is avvumulated, and the integral part "penalizes" this accumulated error by contributing to the control input proportionally (and with opposite sign) to the accumulated error.

The cross-track error (cte) is provided by the simulator. Normally, a PID control scheme would have the following formula:

`Control = -Kp * cte - Ki * (cte * dt + cte_previous) - Kd * (cte - cte_previous) / dt`

where `cte_previous` is the cross track error in the previous time step and `dt` is the time period of the control system. 

Despite the fact that we are not supplied the period of the measurements; since `cte_previous = 0` at time=0, we can incorparate dt terms into the controller gains as `Ki = Ki * dt`and `Kd = Kd / dt` and tune our controller without taking dt into account.

##Tuning the controllers 

For the purpose of tuning P, I, D gains, manual tuning approach was used. The iterations followed are described below:

###Set P first

In the initial phase of manual tuning, starting values were __Kp = 1.0, Ki = 0.0, Kd = 0.0__. This configuration resulted in oscillations with increasing amplitude, even in the strting part of the circuit, where the path is relatively straight.

Second iteration was trying to set Kp to half of the initial value (i.e Kp = 0.5) while setting the other gains still to 0.0. With this setting as well, the response became unstable and car went out of the road in the very first stage of the road (before the first curve).

The Kp was reduced to 0.12, however, oscillations still persist and changes in cte, because of the curvature of road, results in a big control input by P controller, which results in rapid change of direction.

###Increase D

Damping shall be introduced to system, in order to damp out the quick oscillations. At this point, derivative control is added by setting __Kp = 0.12, Kd = 0.3 and Ki = 0.0.__

The damping was still not enough, the car crashed into the bridge after increasing oscillations.--> __Increased Kd to 0.6__. With these settings, the car is able to finish the track without going off-track, with having some ascillations around curves.

###I term

Next, integration gain of 0.0002 is introduced to help with the building up of the error offset. Also, to damp the oscillations more, Kd was increased to 0.8.

