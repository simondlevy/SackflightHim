/*
* Class implementation for target pawn in MultiSim
*
* Copyright (C) 2018 Simon D. Levy
*
* MIT License
 */

#include "Target.h"

/*

ATarget::APhantom()
{
    vehicle.buildFull(this, FrameStatics.mesh.Get());

    // Add propellers
    addRotor(PropCCWStatics.mesh.Get(), +1, +1);
    addRotor(PropCCWStatics.mesh.Get(), -1, -1);
    addRotor(PropCWStatics.mesh.Get(), +1, -1);
    addRotor(PropCWStatics.mesh.Get(), -1, +1);

    // Un-comment for camera
    vehicle.addCamera(&camera);
}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
    vehicle.beginPlay(this, &dynamics);

    Super::BeginPlay();
}

void ATarget::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    vehicle.endPlay();

    Super::EndPlay(EndPlayReason);
}

void ATarget::PostInitializeComponents()
{
    vehicle.postInitializeComponents();

    Super::PostInitializeComponents();
}

// Called automatically on main thread
void ATarget::Tick(float DeltaSeconds)
{
    vehicle.tick(DeltaSeconds);

    Super::Tick(DeltaSeconds);
}

void ATarget::addRotor(UStaticMesh * mesh, int8_t dx, int8_t dy)
{
    vehicle.addRotor(mesh, dx*0.12, dy*0.12, 0.16);
}*/