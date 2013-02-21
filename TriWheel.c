////Trimotor task
float  V1, V2, V3;
int Vx, Vy, PowerA, PowerB, PowerC;
bool scan = false;
bool lastside = false;
task TriWheel()
{
  Vx = 0;
  Vy = 0;

  while (true)
  {
    if(!scan)
    {
      V1 = Vx;                                // Vector Calculation for MotorA(V1)'s Power

      V2 = -Vx / 2 - sqrt(3)/2 * Vy;          // Vector Calculation for MotorB(V2)'s Power

      V3 = -Vx / 2 + sqrt(3)/2 * Vy;          // Vector Calculation for MotorC(V3)'s Power

      if (V1 < 10 && V1 > 0) {V1 = 10;}       // Set Minimum MotorA's Forward Power
      if (V1 < 0 && V1 > -10) {V1 = -10;}     // Set Minimum MotorA's Reverse Power
      if (V2 < 10 && V2 > 0) {V2 = 10;}       // Set Minimum MotorB's Forward Power
      if (V2 < 0 && V2 > -10) {V2 = -10;}     // Set Minimum MotorB's Reverse Power
      if (V3 < 10 && V3 > 0) {V3 = 10;}       // Set Minimum MotorC's Forward Power
      if (V3 < 0 && V3 > -10) {V3 = -10;}     // Set Minimum MotorC's Reverse Power

      PowerA = V1;                            // Convert to an Integer Value for MotorA
      PowerB = V2;                            // Convert to an Integer Value for MotorB
      PowerC = V3;                            // Convert to an Integer Value for MotorC

      motor[motorA] = PowerA;                 // Set MotorA's Velocity (Power Setting)
      motor[motorB] = PowerB;                 // Set MotorB's Velocity (Power Setting)
      motor[motorC] = PowerC;                 // Set MotorC's Velocity (Power Setting)
    }
    else
    {
      if(lastside)
      {
        motor[motorA] = 100;                 // Set MotorA's Velocity (Power Setting)
        motor[motorB] = 100;                 // Set MotorB's Velocity (Power Setting)
        motor[motorC] = 100;
      }
      else
      {
        motor[motorA] = -100;                 // Set MotorA's Velocity (Power Setting)
        motor[motorB] = -100;                 // Set MotorB's Velocity (Power Setting)
        motor[motorC] = -100;
      }
    }
  }
}
