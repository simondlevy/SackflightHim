/*
 * Class declaration for platform-independent multirotor dynamics
 *
 * Copyright (C) 2019 Simon D. Levy
 *
 * MIT License
 */

#pragma once

class MultirotorDynamics {

    private:

        // State
        double _acceleration[3];
        double _velocity[3];
        double _position[3];
        double _rotation[3];

        bool _airborne;

    protected:

        // Implement in a subclass for each vehicle
        virtual void motorsToForces(double * motorvals, double & Fz, double & L, double & M, double & N) = 0;

    public:

        void init(double position[3], double rotation[3], bool airborne=false);

        void update(
                double dt, 
                double motorvals[4],                                   
                double imuAngularVelocityRPY[3], 
                double eulerAngles[3], 
                double velocityXYZ[3],
                double positionXYZ[3]);

        static void eulerToQuaternion(double eulerAngles[3], double quaternion[4]);

        // Factory method
        static MultirotorDynamics * create(void);

}; // class MultirotorDynamics








