// Copyright Arthur Di Muro 2018

#include "Grabber.h"
#include "Classes/GameFramework/Actor.h" //This line must to be here on UnrealEngine4.17 or greater UE
#include "Engine/World.h" //Necessary to use GetWorld()
#include "GameframeWork/PlayerController.h"  //Necessary to get the player

#define OUT


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber class loaded."));
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector playerViewPointLocation;
	FRotator playerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint( OUT playerViewPointLocation, OUT playerViewPointRotation );
	//UE_LOG(LogTemp, Warning, TEXT("Location : %s; Position : %s"),
	//	*playerViewPointLocation.ToString(), // X, Y and Z position
	//	*playerViewPointRotation.ToString()); // P= vertical axis Y=horizontal axis, R= pawn rotation

	// Getting player viewpoint
	FVector lineTraceEnd = playerViewPointLocation + playerViewPointRotation.Vector() * lineLength; //Setting end point lineLength cm above the player's head

	//Draw a red line to visualize orientation
	DrawDebugLine(GetWorld(), playerViewPointLocation, lineTraceEnd, FColor(255, 255, 255), false, 0.f, 0.f, 12.f);
	// Ray-cast out to reach distance
	//See what we hit
}

