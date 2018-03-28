#include "PID.h"

//using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	cte_previous = 0.0;
	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;

	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
}

void PID::UpdateError(double cte) {
	p_error = cte;
  	i_error += cte;
 	d_error = cte - cte_previous;
 	cte_previous = cte;
}

double PID::TotalError() {
	return Kp * p_error + Kd * d_error + Ki * i_error;
}

