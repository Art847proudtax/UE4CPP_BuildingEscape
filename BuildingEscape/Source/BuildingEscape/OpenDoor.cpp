// Copyright Arthur Di Muro 2018

#include "OpenDoor.h"
#include "Classes/GameFramework/Actor.h" //This line must to be here on UnrealEngine4.17 or greater UE
#include "Engine/World.h" //Necessary to use GetWorld()
#include "GameframeWork/PlayerController.h"  //Necessary to get the player


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
	owner = GetOwner(); //Finding the owning actor (SM_Door)
	ActorThatOpensDoor = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor()
{

	//Getting the actual Z (Yaw) rotation
	//float owneryaw = GetOwner()->GetActorRotation().Yaw;

	//Creating a rotator variable that decreases the default rotation of 70 degrees
	//FRotator NewRotation = FRotator(0.f, owneryaw - 70.f, 0.0f);
	FRotator NewRotation = FRotator(0.f, - 90.f - OpenAngle, 0.0f);

	//Set the rotation for object (door)
	owner->SetActorRotation(NewRotation);
}

void UOpenDoor::CloseDoor()
{
	//Set the rotation for object (door)
	owner->SetActorRotation(FRotator(0.f, -90.f, 0.0f));
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Polling the trigger volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpensDoor))
	{
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay)
		CloseDoor();
}

