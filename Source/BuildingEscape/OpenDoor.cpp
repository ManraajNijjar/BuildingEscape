// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Gameframework/Actor.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	TriggerCharacter = GetWorld()->GetFirstPlayerController()->GetPawn();
	Owner = GetOwner();
	// ...
}

void UOpenDoor::OpenDoor()
{

	FRotator NewRotation = FRotator(0.0f, OpenAngle, 0.0f);

	Owner->SetActorRotation(NewRotation);
}

void UOpenDoor::CloseDoor()
{

	FRotator NewRotation = FRotator(0.0f, CloseAngle, 0.0f);

	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (PressurePlate->IsOverlappingActor(TriggerCharacter)) {
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	if ((GetWorld()->GetTimeSeconds() - LastDoorOpenTime) > DoorCloseDelay) {
		CloseDoor();
	}

}

