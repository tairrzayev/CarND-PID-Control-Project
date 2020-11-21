#include "PID.h"
#include <algorithm>

// https://stackoverflow.com/a/9324086
float clip(double n, double lower, double upper) {
   return std::max(lower, std::min(n, upper));
}

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  p_error = cte;
  i_error += cte;
  d_error = cte - prev_p_error;

  prev_p_error = cte;

  steer = clip(TotalError(), -1, 1);

  throttle = clip(1 - steer * 50, 0.1, 0.5);
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return -Kp * p_error - Kd * d_error - Ki * i_error;
}

double PID::GetSteer() {
  return steer;
}

double PID::GetThrottle() {
  return throttle;
}
