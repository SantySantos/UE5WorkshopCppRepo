// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5WorkshopCppPickUpComponent.h"

UUE5WorkshopCppPickUpComponent::UUE5WorkshopCppPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UUE5WorkshopCppPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UUE5WorkshopCppPickUpComponent::OnSphereBeginOverlap);
}

void UUE5WorkshopCppPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AUE5WorkshopCppCharacter* Character = Cast<AUE5WorkshopCppCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
