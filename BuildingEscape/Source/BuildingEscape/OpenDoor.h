// Copyright Arthur Di Muro 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Engine/StaticMeshActor.h"
#include "OpenDoor.generated.h" //The .generated.h must be the last include


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
private:
	UPROPERTY(EditAnywhere) //VisibleAnywhere does not permit to edit
	float OpenAngle = 80.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate; //ATriggerVolume* type requires to include "Engine/TriggerVolume.h" in the 4.20 version of Unreal

	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 1.5f;

	float LastDoorOpenTime;

	//UPROPERTY(EditAnywhere)
	AActor* ActorThatOpensDoor;
	AActor* owner;
};
