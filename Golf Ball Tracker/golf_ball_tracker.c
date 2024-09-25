// filename: golf_ball_tracker.c
// This program tracks the flight path of a golf ball based on user-provided initial conditions.
// It demonstrates the use of floating-point operations and array ycalculation methods using functions.
//
// This program accepts the following user inputs:
// Initial Velocity (in meters per second)
// Angle of Projection (in degrees)
// Time Step (in seconds)
// Number of Steps
//
// The program calculates the golf ball's position at regular time intervals and determines if it has hit the ground or gone out of sight. It displays the titme, horizontal displacement,
// and vertical displacement at each step.

#include <stdio.h>
#include <math.h>

#define G 9.8
#define PI 3.14159265358979323846

// Function to convert degree to radians
double degToRad(double degrees) {
    return degrees * PI / 180.0;
}

int main(void) {
    double initialVelocity, angleInDegrees, timeStep;
    int numSteps;

    // Input Section
    printf("Enter the initial velocity (m/s): ");
    scanf("%lf", &initialVelocity);

    printf("Enter the angle of projection (degrees): ");
    scanf("%lf", &angleInDegrees);

    printf("Enter the time step (s): ");
    scanf("%lf", &timeStep);

    printf("Enter the number of steps: ");
    scanf("%d", &numSteps);


    // Processing Section
    double angleInRadians = degToRad(angleInDegrees);
    double horizontalVelocity = initialVelocity * cos(angleInRadians);
    double verticalVelocity = initialVelocity * sin(angleInRadians);

    for (int step_idx = 0; step_idx < numSteps; step_idx++) {
        double time = step_idx * timeStep;
        double horizontalDisplacement = horizontalVelocity * time;
        double verticalDisplacement = verticalVelocity * time - 0.5 * G * time * time;

        // Output Section
        printf("time: %.2lf s, Horizontal Displacement: %.2lf m, Vertical Displacement: %.2lf m\n", time, horizontalDisplacement, verticalDisplacement);

        if (verticalDisplacement < 0) {
            printf("Golf ball has touched down!\n");
            break;
        } else if (step_idx == numSteps -1 && verticalDisplacement > 0) {
            printf("Golf ball is still in flight.\n");
        }

    }

    return 0;

}