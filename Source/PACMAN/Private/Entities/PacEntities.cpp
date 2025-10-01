// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/PacEntities.h"
#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
APacEntities::APacEntities()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create BoxComponent and set as RootComponent for the Actor
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	RootComponent = BoxCollision;

	// Create StaticMeshComponent and Attach to BoxComponent
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(BoxCollision);

	MovementComponent = CreateDefaultSubobject<UPawnMovementComponent, UFloatingPawnMovement>(TEXT("MovementComponent"));
	MovementComponent->UpdatedComponent = BoxCollision;


	StaticMesh->BodyInstance.bLockZTranslation = true;
	// Optional: allow only Z rotation
	//StaticMesh->BodyInstance.bLockXRotation = true;
	//StaticMesh->BodyInstance.bLockYRotation = true;

	MovementComponent->bConstrainToPlane = true;
	MovementComponent->SetPlaneConstraintNormal(FVector(0.0f, 0.0f, 1.0f));
	

}

// Called when the game starts or when spawned
void APacEntities::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APacEntities::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APacEntities::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

