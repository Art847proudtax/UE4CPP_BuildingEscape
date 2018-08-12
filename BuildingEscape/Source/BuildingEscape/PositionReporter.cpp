// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReporter.h"
#include "Classes/GameFramework/Actor.h" //This line must to be here on UnrealEngine4.17 or greater UE


// Sets default values for this component's properties
UPositionReporter::UPositionReporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UPositionReporter::BeginPlay()
{
	Super::BeginPlay();

	FString objectName = GetOwner()->GetName();
	FString objectPos = GetOwner()->GetTransform().GetLocation().ToString();
	UE_LOG(LogTemp, Warning/*SELECT TEXT COLOR Warning=yellow, Error=red, Log=gray*/, TEXT("The position of %s is %s"), *objectName, *objectPos);
	
}


// Called every frame
void UPositionReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

