/*
 * Abstract, threaded flight-management class for MulticopterSim
 *
 * Copyright (C) 2019 Simon D. Levy
 *
 * MIT License
 */

#pragma once

#include "Dynamics.hpp"
#include "ThreadedManager.hpp"

class FFlightManager : public FThreadedManager {

    private:

        // Current actuator values from getActuators() method
        double * _actuatorValues = NULL; 
        
        // For computing deltaT
        double   _previousTime = 0;

        bool _running = false;

        /**
         * Flight-control method running repeatedly on its own thread.  
         * Override this method to implement your own flight controller.
         *
         * @param time current time in seconds (input)
         * @param values actuator values returned by your controller (output)
         *
         */
        virtual void getActuators(const double time, double * values)  = 0;
        
    protected:

        uint8_t _actuatorCount = 0;

        Dynamics * _dynamics = NULL;

        // Constructor, called main thread
        FFlightManager(Dynamics * dynamics) 
            : FThreadedManager()
        {
            // Constant
            _actuatorCount = dynamics->actuatorCount();

            // Allocate array for actuator values
            _actuatorValues = new double[_actuatorCount];

            // Store dynamics for performTask()
            _dynamics = dynamics;

            // For periodic update
            _previousTime = 0;

            _running = true;
        }

        // Called repeatedly on worker thread to compute dynamics and run
        // flight controller (PID)
        void performTask(double currentTime)
        {
            if (_running) {

                // Update dynamics
                _dynamics->update(_actuatorValues, currentTime - _previousTime);

                // PID controller: update the flight manager (e.g.,
                // HackflightManager) with the dynamics state, getting back the
                // actuator values
                this->getActuators(currentTime, _actuatorValues);

                // Track previous time for deltaT
                _previousTime = currentTime;
            }
        }


    public:

        ~FFlightManager(void)
        {
        }

        // Called by VehiclePawn::Tick() method to get actuator value for animation and sound
        double actuatorValue(uint8_t index)
        {
            return _actuatorValues[index];
        }

        void stop(void)
        {
            _running = false;
        }

}; // class FFlightManager
