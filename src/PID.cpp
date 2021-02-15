#include "PID.h"
#include <iostream>


/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;

  p_error = 0.0;
  d_error = 0.0;
  i_error = 0.0;
  
  previous_cte= 0.0;


}

void PID::UpdateError(double cte) {
  p_error = cte;
  d_error = cte - previous_cte;
  i_error += cte;
  std::cout<<" Updating errors, cte = "<<cte<<" previous cte = "<<previous_cte<<" p_error = "<<p_error<<" d_error = "<<d_error<<" i_error"<<i_error<<std::endl;
  previous_cte = cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  std::cout<<" kp = "<<Kp<<" p_error = "<<p_error<<std::endl;
  std::cout<<" kd = "<<Kd<<" d_error = "<<d_error<<std::endl;
  std::cout<<" ki = "<<Ki<<" i_error = "<<i_error<<std::endl;
  return Kp * p_error + Kd * d_error + Ki * i_error;
}