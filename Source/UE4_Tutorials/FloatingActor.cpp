// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4_Tutorials.h"
#include "FloatingActor.h"


// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

    FVector NewLocation = GetActorLocation();
    float DeltaHeight = (FMath::Sin(m_RunningTimeZ + DeltaTime) - FMath::Sin(m_RunningTimeZ));
    float DeltaLength = (FMath::Sin(m_RunningTimeY + DeltaTime) - FMath::Sin(m_RunningTimeY));
    NewLocation.Z += DeltaHeight * m_FloatScale;
    NewLocation.Y += DeltaLength * m_FloatScale;
    m_RunningTimeZ += DeltaTime * FMath::RandRange(-0.6f, 1.4f);
    m_RunningTimeY += DeltaTime * FMath::RandRange(-0.6f, 1.4f);
    SetActorLocation(NewLocation);
}

